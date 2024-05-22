#pragma once
#include "esphome/core/macros.h"
#include "esphome/components/esp32/gpio.h"
#include "esphome/components/esp32/preferences.h"
#include "esphome/components/json/json_util.h"
#include "esphome/components/logger/logger.h"
#include "esphome/components/md5/md5.h"
#include "esphome/components/mdns/mdns_component.h"
#include "esphome/components/mqtt/custom_mqtt_device.h"
#include "esphome/components/mqtt/mqtt_backend.h"
#include "esphome/components/mqtt/mqtt_backend_esp32.h"
#include "esphome/components/mqtt/mqtt_backend_esp8266.h"
#include "esphome/components/mqtt/mqtt_backend_libretiny.h"
#include "esphome/components/mqtt/mqtt_binary_sensor.h"
#include "esphome/components/mqtt/mqtt_button.h"
#include "esphome/components/mqtt/mqtt_client.h"
#include "esphome/components/mqtt/mqtt_climate.h"
#include "esphome/components/mqtt/mqtt_component.h"
#include "esphome/components/mqtt/mqtt_const.h"
#include "esphome/components/mqtt/mqtt_cover.h"
#include "esphome/components/mqtt/mqtt_date.h"
#include "esphome/components/mqtt/mqtt_datetime.h"
#include "esphome/components/mqtt/mqtt_event.h"
#include "esphome/components/mqtt/mqtt_fan.h"
#include "esphome/components/mqtt/mqtt_light.h"
#include "esphome/components/mqtt/mqtt_lock.h"
#include "esphome/components/mqtt/mqtt_number.h"
#include "esphome/components/mqtt/mqtt_select.h"
#include "esphome/components/mqtt/mqtt_sensor.h"
#include "esphome/components/mqtt/mqtt_switch.h"
#include "esphome/components/mqtt/mqtt_text.h"
#include "esphome/components/mqtt/mqtt_text_sensor.h"
#include "esphome/components/mqtt/mqtt_time.h"
#include "esphome/components/mqtt/mqtt_valve.h"
#include "esphome/components/mqtt_wl_rr/mqtt_wl_rr.h"
#include "esphome/components/network/ip_address.h"
#include "esphome/components/network/util.h"
#include "esphome/components/ota/automation.h"
#include "esphome/components/ota/ota_backend.h"
#include "esphome/components/ota/ota_backend_arduino_esp32.h"
#include "esphome/components/ota/ota_backend_arduino_esp8266.h"
#include "esphome/components/ota/ota_backend_arduino_libretiny.h"
#include "esphome/components/ota/ota_backend_arduino_rp2040.h"
#include "esphome/components/ota/ota_backend_esp_idf.h"
#include "esphome/components/ota/ota_component.h"
#include "esphome/components/preferences/syncer.h"
#include "esphome/components/socket/headers.h"
#include "esphome/components/socket/socket.h"
#include "esphome/components/wifi/wifi_component.h"
#include "esphome/core/application.h"
#include "esphome/core/automation.h"
#include "esphome/core/base_automation.h"
#include "esphome/core/color.h"
#include "esphome/core/component.h"
#include "esphome/core/component_iterator.h"
#include "esphome/core/controller.h"
#include "esphome/core/datatypes.h"
#include "esphome/core/defines.h"
#include "esphome/core/entity_base.h"
#include "esphome/core/gpio.h"
#include "esphome/core/hal.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "esphome/core/macros.h"
#include "esphome/core/optional.h"
#include "esphome/core/preferences.h"
#include "esphome/core/ring_buffer.h"
#include "esphome/core/scheduler.h"
#include "esphome/core/string_ref.h"
#include "esphome/core/time.h"
#include "esphome/core/util.h"
#include "esphome/core/version.h"

