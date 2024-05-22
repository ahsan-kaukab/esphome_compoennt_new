// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
logger::Logger *logger_logger_id;
wifi::WiFiComponent *wifi_wificomponent_id;
mdns::MDNSComponent *mdns_mdnscomponent_id;
ota::OTAComponent *ota_otacomponent_id;
mqtt::MQTTClientComponent *mqtt_mqttclientcomponent_id;
using namespace mqtt;
using namespace json;
preferences::IntervalSyncer *preferences_intervalsyncer_id;
mqtt_wl_rr::MQTTWLRRComponent *my_mqtt_wl_rr;
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esphome:
  //   name: myespdevice
  //   build_path: build/myespdevice
  //   friendly_name: ''
  //   area: ''
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  //   min_version: 2024.5.0
  App.pre_setup("myespdevice", "", "", "", __DATE__ ", " __TIME__, false);
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
  // wifi:
  //   id: wifi_wificomponent_id
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: LIGHT
  //   fast_connect: false
  //   passive_scan: false
  //   enable_on_boot: true
  //   networks:
  //   - ssid: your_ssid
  //     password: your_password
  //     id: wifi_wifiap_id
  //     priority: 0.0
  //   use_address: myespdevice.local
  wifi_wificomponent_id = new wifi::WiFiComponent();
  wifi_wificomponent_id->set_use_address("myespdevice.local");
  {
  wifi::WiFiAP wifi_wifiap_id = wifi::WiFiAP();
  wifi_wifiap_id.set_ssid("your_ssid");
  wifi_wifiap_id.set_password("your_password");
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
  // ota:
  //   id: ota_otacomponent_id
  //   safe_mode: true
  //   version: 2
  //   port: 3232
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent_id = new ota::OTAComponent();
  ota_otacomponent_id->set_port(3232);
  ota_otacomponent_id->set_component_source("ota");
  App.register_component(ota_otacomponent_id);
  if (ota_otacomponent_id->should_enter_safe_mode(10, 300000)) return;
  // mqtt:
  //   broker: your_mqtt_broker
  //   username: your_username
  //   password: your_password
  //   id: mqtt_mqttclientcomponent_id
  //   port: 1883
  //   discovery: true
  //   discovery_retain: true
  //   discovery_prefix: homeassistant
  //   discovery_unique_id_generator: legacy
  //   discovery_object_id_generator: none
  //   use_abbreviations: true
  //   topic_prefix: myespdevice
  //   keepalive: 15s
  //   reboot_timeout: 15min
  //   birth_message:
  //     topic: myespdevice/status
  //     payload: online
  //     qos: 0
  //     retain: true
  //   will_message:
  //     topic: myespdevice/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   shutdown_message:
  //     topic: myespdevice/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   log_topic:
  //     topic: myespdevice/debug
  //     qos: 0
  //     retain: true
  mqtt_mqttclientcomponent_id = new mqtt::MQTTClientComponent();
  mqtt_mqttclientcomponent_id->set_component_source("mqtt");
  App.register_component(mqtt_mqttclientcomponent_id);
  mqtt_mqttclientcomponent_id->set_broker_address("your_mqtt_broker");
  mqtt_mqttclientcomponent_id->set_broker_port(1883);
  mqtt_mqttclientcomponent_id->set_username("your_username");
  mqtt_mqttclientcomponent_id->set_password("your_password");
  mqtt_mqttclientcomponent_id->set_discovery_info("homeassistant", mqtt::MQTT_LEGACY_UNIQUE_ID_GENERATOR, mqtt::MQTT_NONE_OBJECT_ID_GENERATOR, true);
  mqtt_mqttclientcomponent_id->set_topic_prefix("myespdevice");
  mqtt_mqttclientcomponent_id->set_birth_message(mqtt::MQTTMessage{
      .topic = "myespdevice/status",
      .payload = "online",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent_id->set_last_will(mqtt::MQTTMessage{
      .topic = "myespdevice/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent_id->set_shutdown_message(mqtt::MQTTMessage{
      .topic = "myespdevice/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent_id->set_log_message_template(mqtt::MQTTMessage{
      .topic = "myespdevice/debug",
      .payload = "",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent_id->set_keep_alive(15);
  mqtt_mqttclientcomponent_id->set_reboot_timeout(900000);
  // json:
  //   {}
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
  //       path: /home/flinux/Desktop/esphome_component_bthome-master/components
  //       type: local
  //     refresh: 1d
  //     components: all
  // mqtt_wl_rr:
  //   id: my_mqtt_wl_rr
  //   component_name: mqtt_wl_rr
  //   mqtt_topic: your_device_prefix/mqtt_wl_rr/config
  //   mac_address:
  //   - 00:11:22:33:44:55
  my_mqtt_wl_rr = new mqtt_wl_rr::MQTTWLRRComponent();
  my_mqtt_wl_rr->set_component_name("mqtt_wl_rr");
  my_mqtt_wl_rr->set_mqtt_topic("your_device_prefix/mqtt_wl_rr/config");
  my_mqtt_wl_rr->add_mac_address({"00:11:22:33:44:55"});
  my_mqtt_wl_rr->set_component_source("mqtt");
  App.register_component(my_mqtt_wl_rr);
  // network:
  //   min_ipv6_addr_count: 0
  // socket:
  //   implementation: bsd_sockets
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
