#pragma once

#include "esphome.h"
#include "esphome/core/component.h"
#include "esphome/components/esp32_ble_tracker/esp32_ble_tracker.h"

class CustomBLEClient : public esphome::Component, public esphome::esp32_ble_tracker::ESPBTClientListener {
 public:
  void setup() override;
  void loop() override;
  void on_notify(uint16_t handle, const uint8_t *data, uint16_t length) override;
};
