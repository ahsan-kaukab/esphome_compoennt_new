// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace binary_sensor;
logger::Logger *logger_logger_id;
web_server_base::WebServerBase *web_server_base_webserverbase_id;
wifi::WiFiComponent *wifi_wificomponent_id;
mdns::MDNSComponent *mdns_mdnscomponent_id;
web_server::WebServer *web_server_webserver_id;
const uint8_t ESPHOME_WEBSERVER_INDEX_HTML[174] PROGMEM = {60, 33, 68, 79, 67, 84, 89, 80, 69, 32, 104, 116, 109, 108, 62, 60, 104, 116, 109, 108, 62, 60, 104, 101, 97, 100, 62, 60, 109, 101, 116, 97, 32, 99, 104, 97, 114, 115, 101, 116, 61, 85, 84, 70, 45, 56, 62, 60, 108, 105, 110, 107, 32, 114, 101, 108, 61, 105, 99, 111, 110, 32, 104, 114, 101, 102, 61, 100, 97, 116, 97, 58, 62, 60, 47, 104, 101, 97, 100, 62, 60, 98, 111, 100, 121, 62, 60, 101, 115, 112, 45, 97, 112, 112, 62, 60, 47, 101, 115, 112, 45, 97, 112, 112, 62, 60, 115, 99, 114, 105, 112, 116, 32, 115, 114, 99, 61, 34, 104, 116, 116, 112, 115, 58, 47, 47, 111, 105, 46, 101, 115, 112, 104, 111, 109, 101, 46, 105, 111, 47, 118, 50, 47, 119, 119, 119, 46, 106, 115, 34, 62, 60, 47, 115, 99, 114, 105, 112, 116, 62, 60, 47, 98, 111, 100, 121, 62, 60, 47, 104, 116, 109, 108, 62};
const size_t ESPHOME_WEBSERVER_INDEX_HTML_SIZE = 174;
using namespace sensor;
using namespace json;
preferences::IntervalSyncer *preferences_intervalsyncer_id;
esp32_ble_tracker::ESP32BLETracker *esp32_ble_tracker_esp32bletracker_id;
bthome_ble_receiver::BTHomeBLEReceiverHub *bthome_ble_receiver_bthomeblereceiverhub_id;
bthome_receiver_base::BTHomeReceiverBaseDevice *bthome_receiver_base_bthomereceiverbasedevice_id;
bthome_receiver_base::BTHomeReceiverBaseDevice *bthome_receiver_base_bthomereceiverbasedevice_id_2;
bthome_receiver_base::BTHomeReceiverBaseDevice *bthome_receiver_base_bthomereceiverbasedevice_id_3;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id_3;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id_2;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id_5;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id_6;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id_7;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id_8;
bthome_receiver_base::BTHomeReceiverBaseSensor *bthome_receiver_base_bthomereceiverbasesensor_id_10;
bthome_receiver_base::BTHomeReceiverBaseBinarySensor *bthome_receiver_base_bthomereceiverbasebinarysensor_id;
esp32_ble::ESP32BLE *esp32_ble_esp32ble_id;
globals::GlobalsComponent<std::string> *mac_address_1;
globals::GlobalsComponent<std::string> *mac_address_2;
globals::GlobalsComponent<std::string> *mac_address_3;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // async_tcp:
  //   {}
  // esphome:
  //   name: bthome-1
  //   build_path: build/bthome-1
  //   friendly_name: ''
  //   area: ''
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2024.5.0
  App.pre_setup("bthome-1", "", "", "", __DATE__ ", " __TIME__, false);
  // binary_sensor:
  // logger:
  //   level: DEBUG
  //   id: logger_logger_id
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   logs: {}
  logger_logger_id = new logger::Logger(115200, 512);
  logger_logger_id->set_uart_selection(logger::UART_SELECTION_UART0);
  logger_logger_id->pre_setup();
  logger_logger_id->set_component_source("logger");
  App.register_component(logger_logger_id);
  // web_server_base:
  //   id: web_server_base_webserverbase_id
  web_server_base_webserverbase_id = new web_server_base::WebServerBase();
  web_server_base_webserverbase_id->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase_id);
  // wifi:
  //   id: wifi_wificomponent_id
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   passive_scan: false
  //   enable_on_boot: true
  //   networks:
  //   - ssid: !secret 'wifi_ssid'
  //     password: !secret 'wifi_password'
  //     id: wifi_wifiap_id
  //     priority: 0.0
  //   use_address: bthome-1.local
  wifi_wificomponent_id = new wifi::WiFiComponent();
  wifi_wificomponent_id->set_use_address("bthome-1.local");
  {
  wifi::WiFiAP wifi_wifiap_id = wifi::WiFiAP();
  wifi_wifiap_id.set_ssid("YourWiFiSSID");
  wifi_wifiap_id.set_password("YourWiFiPassword");
  wifi_wifiap_id.set_priority(0.0f);
  wifi_wificomponent_id->add_sta(wifi_wifiap_id);
  }
  wifi_wificomponent_id->set_reboot_timeout(900000);
  wifi_wificomponent_id->set_power_save_mode(wifi::WIFI_POWER_SAVE_LIGHT);
  wifi_wificomponent_id->set_fast_connect(false);
  wifi_wificomponent_id->set_passive_scan(false);
  wifi_wificomponent_id->set_enable_on_boot(true);
  wifi_wificomponent_id->set_component_source("wifi");
  App.register_component(wifi_wificomponent_id);
  // mdns:
  //   id: mdns_mdnscomponent_id
  //   disabled: false
  //   services: []
  mdns_mdnscomponent_id = new mdns::MDNSComponent();
  mdns_mdnscomponent_id->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent_id);
  // web_server:
  //   port: 80
  //   ota: false
  //   id: web_server_webserver_id
  //   version: 2
  //   enable_private_network_access: true
  //   web_server_base_id: web_server_base_webserverbase_id
  //   include_internal: false
  //   log: true
  //   css_url: ''
  //   js_url: https:oi.esphome.io/v2/www.js
  web_server_webserver_id = new web_server::WebServer(web_server_base_webserverbase_id);
  web_server_webserver_id->set_component_source("web_server");
  App.register_component(web_server_webserver_id);
  web_server_base_webserverbase_id->set_port(80);
  web_server_webserver_id->set_allow_ota(false);
  web_server_webserver_id->set_expose_log(true);
  web_server_webserver_id->set_include_internal(false);
  // sensor:
  // json:
  //   {}
  // substitutions:
  //   systemName: bthome-1
  // esp32:
  //   board: esp32dev
  //   flash_size: 4MB
  //   framework:
  //     version: 2.0.5
  //     source: ~3.20005.0
  //     platform_version: platformio/espressif32@5.4.0
  //     type: arduino
  //   variant: ESP32
  // preferences:
  //   id: preferences_intervalsyncer_id
  //   flash_write_interval: 60s
  preferences_intervalsyncer_id = new preferences::IntervalSyncer();
  preferences_intervalsyncer_id->set_write_interval(60000);
  preferences_intervalsyncer_id->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer_id);
  // external_components:
  //   - source:
  //       url: https:github.com/ahsan-kaukab/esphome_btreceiver.git
  //       type: git
  //     refresh: 1min
  //     components: all
  // esp32_ble_tracker:
  //   scan_parameters:
  //     active: false
  //     duration: 5min
  //     interval: 320ms
  //     window: 30ms
  //     continuous: true
  //   id: esp32_ble_tracker_esp32bletracker_id
  //   ble_id: esp32_ble_esp32ble_id
  esp32_ble_tracker_esp32bletracker_id = new esp32_ble_tracker::ESP32BLETracker();
  esp32_ble_tracker_esp32bletracker_id->set_component_source("esp32_ble_tracker");
  App.register_component(esp32_ble_tracker_esp32bletracker_id);
  // bthome_ble_receiver:
  //   dump: UNMATCHED
  //   devices:
  //   - mac_address: 11:22:33:44:55:66
  //     name_prefix: BTHome Living Room
  //     id: bthome_receiver_base_bthomereceiverbasedevice_id
  //   - mac_address: AA:BB:CC:DD:EE:FF
  //     name_prefix: BTHome Garage
  //     id: bthome_receiver_base_bthomereceiverbasedevice_id_2
  //   - mac_address: 22:33:44:55:66:77
  //     dump: ALL
  //     id: bthome_receiver_base_bthomereceiverbasedevice_id_3
  //   id: bthome_ble_receiver_bthomeblereceiverhub_id
  //   esp32_ble_id: esp32_ble_tracker_esp32bletracker_id
  bthome_ble_receiver_bthomeblereceiverhub_id = new bthome_ble_receiver::BTHomeBLEReceiverHub();
  bthome_ble_receiver_bthomeblereceiverhub_id->set_component_source("bthome_receiver_base");
  App.register_component(bthome_ble_receiver_bthomeblereceiverhub_id);
  bthome_ble_receiver_bthomeblereceiverhub_id->set_dump_option(bthome_receiver_base::DumpOption_Unmatched);
  bthome_receiver_base_bthomereceiverbasedevice_id = (bthome_receiver_base::BTHomeReceiverBaseDevice *)(bthome_ble_receiver_bthomeblereceiverhub_id->add_device("11:22:33:44:55:66"));
  bthome_receiver_base_bthomereceiverbasedevice_id->set_component_source("bthome_receiver_base");
  App.register_component(bthome_receiver_base_bthomereceiverbasedevice_id);
  bthome_receiver_base_bthomereceiverbasedevice_id->set_name_prefix("BTHome Living Room");
  bthome_receiver_base_bthomereceiverbasedevice_id_2 = (bthome_receiver_base::BTHomeReceiverBaseDevice *)(bthome_ble_receiver_bthomeblereceiverhub_id->add_device("AA:BB:CC:DD:EE:FF"));
  bthome_receiver_base_bthomereceiverbasedevice_id_2->set_component_source("bthome_receiver_base");
  App.register_component(bthome_receiver_base_bthomereceiverbasedevice_id_2);
  bthome_receiver_base_bthomereceiverbasedevice_id_2->set_name_prefix("BTHome Garage");
  bthome_receiver_base_bthomereceiverbasedevice_id_3 = (bthome_receiver_base::BTHomeReceiverBaseDevice *)(bthome_ble_receiver_bthomeblereceiverhub_id->add_device("22:33:44:55:66:77"));
  bthome_receiver_base_bthomereceiverbasedevice_id_3->set_component_source("bthome_receiver_base");
  App.register_component(bthome_receiver_base_bthomereceiverbasedevice_id_3);
  bthome_receiver_base_bthomereceiverbasedevice_id_3->set_dump_option(bthome_receiver_base::DumpOption_All);
  esp32_ble_tracker_esp32bletracker_id->register_listener(bthome_ble_receiver_bthomeblereceiverhub_id);
  // sensor.bthome_ble_receiver:
  //   platform: bthome_ble_receiver
  //   mac_address: 11:22:33:44:55:66
  //   sensors:
  //   - measurement_type:
  //       measurement_type: 2
  //       accuracy_decimals: 2
  //       unit_of_measurement: °C
  //       device_class: temperature
  //     name: Temperature
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id
  //   - measurement_type:
  //       measurement_type: 3
  //       accuracy_decimals: 2
  //       unit_of_measurement: '%'
  //       device_class: humidity
  //     name: Humidity
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id_2
  //   - measurement_type:
  //       measurement_type: 0
  //       accuracy_decimals: 0
  //     name: PacketId
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id_3
  //   BTHomeBLEReceiverHub_ID: bthome_ble_receiver_bthomeblereceiverhub_id
  //   id: bthome_receiver_base_bthomereceiverbasesensor_id_4
  //   BTHomeReceiverBaseDevice_ID: bthome_receiver_base_bthomereceiverbasedevice_id_4
  bthome_receiver_base_bthomereceiverbasesensor_id_3 = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id_3);
  bthome_receiver_base_bthomereceiverbasesensor_id_3->set_name("BTHome Living Room PacketId");
  bthome_receiver_base_bthomereceiverbasesensor_id_3->set_object_id("bthome_living_room_packetid");
  bthome_receiver_base_bthomereceiverbasesensor_id_3->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_3->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_3->set_measurement_type(0x00);
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id, 0x112233445566ULL, bthome_receiver_base_bthomereceiverbasesensor_id_3);
  bthome_receiver_base_bthomereceiverbasesensor_id = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id);
  bthome_receiver_base_bthomereceiverbasesensor_id->set_name("BTHome Living Room Temperature");
  bthome_receiver_base_bthomereceiverbasesensor_id->set_object_id("bthome_living_room_temperature");
  bthome_receiver_base_bthomereceiverbasesensor_id->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id->set_measurement_type(0x02);
  bthome_receiver_base_bthomereceiverbasesensor_id->set_accuracy_decimals(2);
  bthome_receiver_base_bthomereceiverbasesensor_id->set_unit_of_measurement("\302\260C");
  bthome_receiver_base_bthomereceiverbasesensor_id->set_device_class("temperature");
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id, 0x112233445566ULL, bthome_receiver_base_bthomereceiverbasesensor_id);
  bthome_receiver_base_bthomereceiverbasesensor_id_2 = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id_2);
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_name("BTHome Living Room Humidity");
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_object_id("bthome_living_room_humidity");
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_measurement_type(0x03);
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_accuracy_decimals(2);
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_unit_of_measurement("%");
  bthome_receiver_base_bthomereceiverbasesensor_id_2->set_device_class("humidity");
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id, 0x112233445566ULL, bthome_receiver_base_bthomereceiverbasesensor_id_2);
  // sensor.bthome_ble_receiver:
  //   platform: bthome_ble_receiver
  //   mac_address: AA:BB:CC:DD:EE:FF
  //   sensors:
  //   - measurement_type:
  //       measurement_type: 2
  //       accuracy_decimals: 2
  //       unit_of_measurement: °C
  //       device_class: temperature
  //     name: Temperature
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id_5
  //   - measurement_type: 2
  //     name: Temperature 2
  //     accuracy_decimals: 2
  //     unit_of_measurement: °C
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id_6
  //   - measurement_type: 2
  //     name: Temperature 3
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id_7
  //   - measurement_type:
  //       measurement_type: 62
  //       accuracy_decimals: 0
  //       unit_of_measurement: ''
  //     name: Count
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id_8
  //   BTHomeBLEReceiverHub_ID: bthome_ble_receiver_bthomeblereceiverhub_id
  //   id: bthome_receiver_base_bthomereceiverbasesensor_id_9
  //   BTHomeReceiverBaseDevice_ID: bthome_receiver_base_bthomereceiverbasedevice_id_5
  bthome_receiver_base_bthomereceiverbasesensor_id_5 = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id_5);
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_name("BTHome Garage Temperature");
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_object_id("bthome_garage_temperature");
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_measurement_type(0x02);
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_accuracy_decimals(2);
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_unit_of_measurement("\302\260C");
  bthome_receiver_base_bthomereceiverbasesensor_id_5->set_device_class("temperature");
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id_2, 0xAABBCCDDEEFFULL, bthome_receiver_base_bthomereceiverbasesensor_id_5);
  bthome_receiver_base_bthomereceiverbasesensor_id_6 = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id_6);
  bthome_receiver_base_bthomereceiverbasesensor_id_6->set_name("BTHome Garage Temperature 2");
  bthome_receiver_base_bthomereceiverbasesensor_id_6->set_object_id("bthome_garage_temperature_2");
  bthome_receiver_base_bthomereceiverbasesensor_id_6->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_6->set_unit_of_measurement("\302\260C");
  bthome_receiver_base_bthomereceiverbasesensor_id_6->set_accuracy_decimals(2);
  bthome_receiver_base_bthomereceiverbasesensor_id_6->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_6->set_measurement_type(2);
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id_2, 0xAABBCCDDEEFFULL, bthome_receiver_base_bthomereceiverbasesensor_id_6);
  bthome_receiver_base_bthomereceiverbasesensor_id_7 = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id_7);
  bthome_receiver_base_bthomereceiverbasesensor_id_7->set_name("BTHome Garage Temperature 3");
  bthome_receiver_base_bthomereceiverbasesensor_id_7->set_object_id("bthome_garage_temperature_3");
  bthome_receiver_base_bthomereceiverbasesensor_id_7->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_7->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_7->set_measurement_type(2);
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id_2, 0xAABBCCDDEEFFULL, bthome_receiver_base_bthomereceiverbasesensor_id_7);
  bthome_receiver_base_bthomereceiverbasesensor_id_8 = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id_8);
  bthome_receiver_base_bthomereceiverbasesensor_id_8->set_name("BTHome Garage Count");
  bthome_receiver_base_bthomereceiverbasesensor_id_8->set_object_id("bthome_garage_count");
  bthome_receiver_base_bthomereceiverbasesensor_id_8->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_8->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_8->set_measurement_type(0x3E);
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id_2, 0xAABBCCDDEEFFULL, bthome_receiver_base_bthomereceiverbasesensor_id_8);
  // sensor.bthome_ble_receiver:
  //   platform: bthome_ble_receiver
  //   mac_address: 22:33:44:55:66:77
  //   sensors:
  //   - measurement_type:
  //       measurement_type: 2
  //       accuracy_decimals: 2
  //       unit_of_measurement: °C
  //       device_class: temperature
  //     name: BTHome Workshop Temperature
  //     disabled_by_default: false
  //     force_update: false
  //     id: bthome_receiver_base_bthomereceiverbasesensor_id_10
  //   BTHomeBLEReceiverHub_ID: bthome_ble_receiver_bthomeblereceiverhub_id
  //   id: bthome_receiver_base_bthomereceiverbasesensor_id_11
  //   BTHomeReceiverBaseDevice_ID: bthome_receiver_base_bthomereceiverbasedevice_id_6
  bthome_receiver_base_bthomereceiverbasesensor_id_10 = new bthome_receiver_base::BTHomeReceiverBaseSensor();
  App.register_sensor(bthome_receiver_base_bthomereceiverbasesensor_id_10);
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_name("BTHome Workshop Temperature");
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_object_id("bthome_workshop_temperature");
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_force_update(false);
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_measurement_type(0x02);
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_accuracy_decimals(2);
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_unit_of_measurement("\302\260C");
  bthome_receiver_base_bthomereceiverbasesensor_id_10->set_device_class("temperature");
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id_3, 0x223344556677ULL, bthome_receiver_base_bthomereceiverbasesensor_id_10);
  // binary_sensor.bthome_ble_receiver:
  //   platform: bthome_ble_receiver
  //   mac_address: AA:BB:CC:DD:EE:FF
  //   sensors:
  //   - measurement_type:
  //       measurement_type: 17
  //       accuracy_decimals: 0
  //       device_class: opening
  //     name: Garage
  //     disabled_by_default: false
  //     id: bthome_receiver_base_bthomereceiverbasebinarysensor_id
  //   BTHomeBLEReceiverHub_ID: bthome_ble_receiver_bthomeblereceiverhub_id
  //   id: bthome_receiver_base_bthomereceiverbasebinarysensor_id_2
  //   BTHomeReceiverBaseDevice_ID: bthome_receiver_base_bthomereceiverbasedevice_id_7
  bthome_receiver_base_bthomereceiverbasebinarysensor_id = new bthome_receiver_base::BTHomeReceiverBaseBinarySensor();
  App.register_binary_sensor(bthome_receiver_base_bthomereceiverbasebinarysensor_id);
  bthome_receiver_base_bthomereceiverbasebinarysensor_id->set_name("BTHome Garage Garage");
  bthome_receiver_base_bthomereceiverbasebinarysensor_id->set_object_id("bthome_garage_garage");
  bthome_receiver_base_bthomereceiverbasebinarysensor_id->set_disabled_by_default(false);
  bthome_receiver_base_bthomereceiverbasebinarysensor_id->set_measurement_type(0x11);
  bthome_receiver_base_bthomereceiverbasebinarysensor_id->set_device_class("opening");
  bthome_ble_receiver_bthomeblereceiverhub_id->add_sensor(bthome_receiver_base_bthomereceiverbasedevice_id_2, 0xAABBCCDDEEFFULL, bthome_receiver_base_bthomereceiverbasebinarysensor_id);
  // network:
  //   min_ipv6_addr_count: 0
  // esp32_ble:
  //   id: esp32_ble_esp32ble_id
  //   io_capability: none
  //   enable_on_boot: true
  esp32_ble_esp32ble_id = new esp32_ble::ESP32BLE();
  esp32_ble_esp32ble_id->set_enable_on_boot(true);
  esp32_ble_esp32ble_id->set_io_capability(esp32_ble::IO_CAP_NONE);
  esp32_ble_esp32ble_id->set_component_source("esp32_ble");
  App.register_component(esp32_ble_esp32ble_id);
  esp32_ble_esp32ble_id->register_gap_event_handler(esp32_ble_tracker_esp32bletracker_id);
  esp32_ble_esp32ble_id->register_gattc_event_handler(esp32_ble_tracker_esp32bletracker_id);
  esp32_ble_esp32ble_id->register_ble_status_event_handler(esp32_ble_tracker_esp32bletracker_id);
  esp32_ble_tracker_esp32bletracker_id->set_parent(esp32_ble_esp32ble_id);
  esp32_ble_tracker_esp32bletracker_id->set_scan_duration(300);
  esp32_ble_tracker_esp32bletracker_id->set_scan_interval(512);
  esp32_ble_tracker_esp32bletracker_id->set_scan_window(48);
  esp32_ble_tracker_esp32bletracker_id->set_scan_active(false);
  esp32_ble_tracker_esp32bletracker_id->set_scan_continuous(true);
  // globals:
  //   id: mac_address_1
  //   type: std::string
  //   restore_value: false
  //   initial_value: '"ff:ff:ff:ff:ff:ff"'
  mac_address_1 = new globals::GlobalsComponent<std::string>("ff:ff:ff:ff:ff:ff");
  mac_address_1->set_component_source("globals");
  App.register_component(mac_address_1);
  // globals:
  //   id: mac_address_2
  //   type: std::string
  //   restore_value: false
  //   initial_value: '"ff:ff:ff:ff:ff:ff"'
  mac_address_2 = new globals::GlobalsComponent<std::string>("ff:ff:ff:ff:ff:ff");
  mac_address_2->set_component_source("globals");
  App.register_component(mac_address_2);
  // globals:
  //   id: mac_address_3
  //   type: std::string
  //   restore_value: false
  //   initial_value: '"ff:ff:ff:ff:ff:ff"'
  mac_address_3 = new globals::GlobalsComponent<std::string>("ff:ff:ff:ff:ff:ff");
  mac_address_3->set_component_source("globals");
  App.register_component(mac_address_3);
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}