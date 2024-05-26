/*
 BTHome protocol virtual sensors for ESPHome

 Author: Attila Farago
 */
#define USE_MQTT
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"

#include "esphome/components/bthome_base/bthome_base_common.h"

#include "bthome_receiver_base_common.h"
#include "bthome_receiver_base_device.h"
#include "bthome_receiver_base_basesensor.h"
#include "bthome_receiver_base_sensor.h"
#include "bthome_receiver_base_hub.h"
#include "esphome/core/log.h"
#include "esphome/core/preferences.h"
//#include "esphome/components/mqtt/mqtt_client.h"
#include <vector>
#include <string>
#include <ArduinoJson.h>


namespace esphome
{
  namespace bthome_receiver_base
  {
    using namespace bthome_base;

    static const char *const TAG = "bthome_receiver_base";

    BTHomeReceiverBaseDevice *BTHomeReceiverBaseHub::add_device(mac_address_t address)
    {
      auto btdevice = this->create_device(address);
      my_devices.emplace(address, btdevice);

      return btdevice;
    }

    BTHomeReceiverBaseDevice *BTHomeReceiverBaseHub::add_sensor(BTHomeReceiverBaseDevice *btdevice, mac_address_t address, BTHomeReceiverBaseBaseSensor *sensor)
    {
      if (!btdevice)
        btdevice = get_device_by_address(address);
      if (!btdevice)
        btdevice = add_device(address);

      // register new btsensor for the btdevice
      btdevice->register_sensor(sensor);
      return btdevice;
    }

    void BTHomeReceiverBaseHub::report_measurements_(vector<bthome_measurement_record_t> measurements, mac_address_t address, BTHomeReceiverBaseDevice *btdevice)
    {
      bool device_header_reported = false;
      measurement_log_handler_t measurement_log_handler = [&](const bthome_measurement_record_t measurement, const bool matched)
      {
#ifdef ESPHOME_LOG_HAS_DEBUG
        if (
            (this->get_dump_option() == DumpOption_All || (!matched && (this->get_dump_option() == DumpOption_Unmatched))) ||
            (btdevice != NULL &&
             (btdevice->get_dump_option() == DumpOption_All || (!matched && (btdevice->get_dump_option() == DumpOption_Unmatched)))))
        {
          if (!device_header_reported)
          {
            ESP_LOGD(TAG, "Data received from %s %s",
                     bthome_base::addr64_to_str(address).c_str(),
                     btdevice ? btdevice->get_name_prefix().c_str() : "");
            device_header_reported = true;
          }
          if (measurement.is_value)
            ESP_LOGD(TAG, " - measure_type: 0x%02x = value: %0.3f%s",
                     measurement.d.value.id, measurement.d.value.value,
                     matched ? "" : ", unmatched");
          else
            ESP_LOGD(TAG, " - id: 0x%02x = event_type %d, value: %d",
                     measurement.d.event.device_type, measurement.d.event.event_type, measurement.d.event.steps);
        }
#endif // ESPHOME_LOG_HAS_DEBUG
      };

      // report events - trigger automations
      for (auto item : measurements)
      {
        if (!item.is_value)
        {
          this->on_event_callback_.call(address, item.d.event);
          if (btdevice)
            btdevice->on_event_callback_.call(address, item.d.event);
        }
      }

      // report measurements to devices
      if (btdevice)
        btdevice->report_measurements_(measurements, measurement_log_handler);
      else
        for (auto item : measurements)
          measurement_log_handler(item, false);
    }

    optional<uint8_t> BTHomeReceiverBaseHub::parse_message_bthome_(const mac_address_t address, const uint8_t *payload_data, const uint32_t payload_length, bthome_base::BTProtoVersion_e proto)
    {
      vector<bthome_measurement_record_t> measurements;

      // TODO: should do a loop here instead of finding the right device and stopping
      //  for (auto btdevice_i : this->my_devices)
      //    if (btdevice_i->match(address))
      //      return btdevice_i;

      auto *btdevice = get_device_by_address(address);
      // if (!btdevice && this->get_dump_option() == DumpOption_None)
      //   return;

#ifdef ESPHOME_LOG_HAS_DEBUG
      if (dump_packets_option_)
      {
        // log incoming packet
        std::string serviceData = "";
        for (auto i = 0; i < payload_length; i++)
          serviceData += str_snprintf("%02X ", 3, payload_data[i]);
        ESP_LOGD(TAG, "DATA received - %s = %s", bthome_base::addr64_to_str(address).c_str(), serviceData.c_str());
      }
#endif // ESPHOME_LOG_LEVEL_DEBUG

      // parse the payload and report measurements in the callback, will be fixing this to V2
      optional<uint8_t> packet_id = nullopt;
      bthome_base::parse_payload_bthome(
          payload_data, payload_length, proto,
          [&](uint8_t measurement_type, float value)
          {
            switch (measurement_type)
            {
            case BTHOME_BUTTON_EVENT:
            case BTHOME_DIMMER_EVENT:
            {
              bthome_measurement_event_record_t event_data{measurement_type, (uint8_t)((int)value & 0xff), (uint8_t)((int)value << 8 & 0xff)};
              bthome_measurement_record_t data{false, .d = {.event = event_data}};
              measurements.push_back(data);
              break;
            }
            case BTHOME_PACKET_ID_VALUE:
              packet_id = value; // intentional fallthrough
            default:
            {
              bthome_measurement_value_record_t value_data{measurement_type, value};
              bthome_measurement_record_t data{true, .d = {.value = value_data}};
              measurements.push_back(data);
            }
            break;
            }
          },
          [&](const char *message)
          {
            ESP_LOGD(TAG, "%s", message);
          });

      // report the measurements
      this->report_measurements_(measurements, address, btdevice);

      // trigger automation
      this->on_packet_callback_.call(address, measurements);
      if (btdevice)
        btdevice->on_packet_callback_.call(address, measurements);

      // return parsed packet_id
      return packet_id;
    }
    uint32_t BTHomeReceiverBaseHub::get_unique_id () {
        // Implement a method to return a unique identifier
        // This is just an example. Adjust as needed.
        return static_cast<uint32_t>(reinterpret_cast<uintptr_t>(this));
    }

    //////
    void BTHomeReceiverBaseHub::setup() {
      // ESP_LOGCONFIG(TAG, "Setting up BTHomeReceiverBaseDevice...");
      
      // // Load the whitelist from NVS
      this->nvs_whitelist = global_preferences->make_preference(1024, this->get_unique_id());


      this->load_whitelist();

      // Subscribe to the MQTT topic
      std::string topic = this->get_base_topic() + "/ble_whitelist/config";
      ESP_LOGD(TAG, "Subscribing to topic: %s", topic.c_str());
      // mqtt::global_mqtt_client->subscribe(topic, [this](const std::string &topic, const std::string &payload) {
      //   this->on_mqtt_message(topic, payload);
      // });
    }

    void BTHomeReceiverBaseHub::on_mqtt_message(const std::string &topic, const std::string &payload) {
      // ESP_LOGD(TAG, "Received MQTT message on topic %s", topic.c_str());
      ESP_LOGD(TAG, "Payload: %s", payload.c_str());
      
      // Parse JSON payload
      StaticJsonDocument<1024> json;
      DeserializationError error = deserializeJson(json, payload);
      if (error) {
        ESP_LOGE(TAG, "Failed to parse JSON payload");
        return;
      }
      
      // Update whitelist
      if (json.containsKey("ble") && json["ble"].containsKey("wl")) {
        std::vector<BLEDevice> new_whitelist;
        for (JsonObject wl_entry : json["ble"]["wl"].as<JsonArray>()) {
          BLEDevice device;
          device.desc = wl_entry["desc"].as<std::string>();
          device.mac = wl_entry["mac"].as<std::string>();
          device.type = wl_entry["type"].as<std::string>();
          new_whitelist.push_back(device);
        }
        
        // Compare with current whitelist
        if (new_whitelist != this->whitelist) {
          this->whitelist = new_whitelist;
          // Save the new whitelist to NVS
          this->save_whitelist();
        }
      }
    } 

    void BTHomeReceiverBaseHub::load_whitelist() {
      std::string json_str;
      if (!this->nvs_whitelist.load(&json_str)) {
        ESP_LOGI(TAG, "No whitelist found in NVS");
        return;
      }
      
      //ESP_LOGD(TAG, "Loaded whitelist from NVS: %s", json_str.c_str());
      
      StaticJsonDocument<1024> json;
      DeserializationError error = deserializeJson(json, json_str);
      if (error) {
        ESP_LOGE(TAG, "Failed to parse JSON from NVS");
        return;
      }
      
      if (json.containsKey("ble") && json["ble"].containsKey("wl")) {
        this->whitelist.clear();
        for (JsonObject wl_entry : json["ble"]["wl"].as<JsonArray>()) {
          BLEDevice device;
          device.desc = wl_entry["desc"].as<std::string>();
          device.mac = wl_entry["mac"].as<std::string>();
          device.type = wl_entry["type"].as<std::string>();
          this->whitelist.push_back(device);
        }
      }
    }

    void BTHomeReceiverBaseHub::save_whitelist() {
   // Assuming you have a DynamicJsonDocument initialized with sufficient size
      DynamicJsonDocument jsonDoc(1024);

      // Create the root JSON object
      JsonObject root = jsonDoc.to<JsonObject>();

      // Create a nested object for "ble"
      JsonObject ble = root.createNestedObject("ble");

      // Create a nested array for "wl" inside the "ble" object
      JsonArray wl_array = ble.createNestedArray("wl");

      // Iterate over the whitelist and add each device to the JSON array
      for (const auto &device : whitelist) {
        JsonObject wl_entry = wl_array.createNestedObject();
        wl_entry["desc"] = device.desc;
        wl_entry["mac"] = device.mac;
        wl_entry["type"] = device.type;
      }

      // Serialize the JSON document to a string for debugging
      String output;
      serializeJson(jsonDoc, output);
      this->nvs_whitelist.save(&output);
      
      //ESP_LOGD(TAG, "Saved whitelist to NVS: %s", json_str.c_str());
    }

    std::string BTHomeReceiverBaseHub::get_base_topic() {
      // Return the base topic for this device
      return "your_base_device_topic"; // Replace with your actual base topic
    }

    mac_address_t BTHomeReceiverBaseHub::get_mac_address_from_nvs(const std::string nvs_id) {
        mac_address_t mac_address = {0};

          ESPPreferenceObject nvs_pref = global_preferences->make_preference(6, std::stoul(nvs_id));

          // if (!nvs_pref.load(mac_address.data())) {
          //   ESP_LOGE(TAG, "Failed to load MAC address from NVS");
          // } else {
          //   ESP_LOGD(TAG, "Loaded MAC address from NVS: %s", mac_address_to_string(mac_address).c_str());
          // }

          return mac_address;
    }

    int BTHomeReceiverBaseHub::get_mac_address_from_nvs_as_hex(const std::string nvs_id) {
          mac_address_t mac_address = this->get_mac_address_from_nvs(nvs_id);
          return mac_address;
    }
  }
}