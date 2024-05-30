/*
 BTHome protocol virtual sensors for ESPHome

 Author: Attila Farago
 */

#pragma once
#define USE_MQTT
#include "esphome/core/component.h"
#include "esphome/components/sensor/sensor.h"

#include "esphome/components/bthome_base/bthome_base_common.h"
#include "esphome/components/bthome_base/bthome_parser.h"

#include "esphome/core/preferences.h"
//#include "esphome/components/mqtt/mqtt_client.h"

#include "bthome_receiver_base_common.h"
#include "bthome_receiver_base_device.h"
#include "bthome_receiver_base_basesensor.h"
#include "bthome_receiver_base_binarysensor.h"
#include "bthome_receiver_base_sensor.h"
#include "bthome_receiver_base_eventtarget.h"
#include "esphome/components/mqtt/mqtt_client.h"


#include <vector>
#include <map>
#include <string>

namespace esphome
{
  namespace bthome_receiver_base
  {
    using namespace std;
    using namespace bthome_base;
    using namespace bthome_receiver_base;

    struct BLEDevice {
      std::string desc;
      std::string mac;
      std::string type;

      bool operator==(const BLEDevice &other) const {
        return (desc == other.desc && mac == other.mac && type == other.type);
      }
    };

    class BTHomeReceiverBaseHub : public Component, public BTHomeReceiverBaseEventTarget
    {
    public:
      BTHomeReceiverBaseHub() {
        // Constructor logic here
        // If the setup logic is simple and does not depend on the ESPHome framework being fully initialized, call it here.
        //this->setup();
        
        this->nvs_whitelist = global_preferences->make_preference(512, this->get_unique_id());
        this->load_whitelist();
        // Subscribe to the MQTT topic
        std::string topic = this->get_base_topic() + "/BTHomeReceiverBaseHub/config";
        //ESP_LOGD(TAG, "Subscribing to topic: %s", topic.c_str());
        mqtt::global_mqtt_client->subscribe(topic, [this](const std::string &topic, const std::string &payload) {
          this->on_mqtt_message(topic, payload);
        });
      }
      DumpOption_e get_dump_option() { return this->dump_option_; };
      void set_dump_option(DumpOption_e value) { this->dump_option_ = value; };
      void set_dump_packets_option(bool value) { this->dump_packets_option_ = value; };

      float get_setup_priority() const override { return setup_priority::DATA; }
      string load_mac_address(string key);
      BTHomeReceiverBaseDevice *add_device(bthome_base::mac_address_t address);
      BTHomeReceiverBaseDevice *add_sensor(BTHomeReceiverBaseDevice *btdevice, bthome_base::mac_address_t address, BTHomeReceiverBaseBaseSensor *sensor);
      void on_mqtt_message(const std::string &topic, const std::string &payload); 
      void load_whitelist();
      void save_whitelist(); 
      uint32_t get_unique_id();
      string get_base_topic();
      std::string mac_address_to_hex(const mac_address_t mac_address);
      uint64_t get_mac_address_from_nvs_as_hex(const std::string nvs_id);
      mac_address_t mac_string_to_uint64(const string &mac); 

    protected:
      virtual optional<uint8_t> parse_message_bthome_(const bthome_base::mac_address_t address, const uint8_t *payload_data, const uint32_t payload_length, bthome_base::BTProtoVersion_e proto);
      void report_measurements_(vector<bthome_base::bthome_measurement_record_t> measurements, bthome_base::mac_address_t address, BTHomeReceiverBaseDevice *btdevice);
      virtual BTHomeReceiverBaseDevice *create_device(const bthome_base::mac_address_t address) { return new BTHomeReceiverBaseDevice(address); }

      BTHomeReceiverBaseDevice *get_device_by_address(const bthome_base::mac_address_t address)
      {
        if (my_devices.find(address) != my_devices.end())
          return my_devices[address];
        else
          return nullptr;
      }

    private:
      vector<BLEDevice> whitelist;
      ESPPreferenceObject nvs_whitelist;
      DumpOption_e dump_option_{DumpOption_None};
      bool dump_packets_option_{false};
      std::map<bthome_base::mac_address_t, BTHomeReceiverBaseDevice *> my_devices;
    };
  }
}
