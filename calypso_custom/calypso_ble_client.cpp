#include "esphome.h"
#include "custom_ble_client.h"

using namespace esphome;

#warning "Compiling calypso_ble_sensor.cpp"
#pragma message("Compiling calypso_ble_sensor.cpp")

#if 1
class CustomBLEClient : public esp32_ble_tracker::ESPBTClientListener {
public:
  void setup() override {
    ESP_LOGI("CustomBLEClient", "Custom BLE Client initialized.");
  }

  void on_notify(uint16_t handle, const uint8_t *data, uint16_t length) override {
    ESP_LOGD("CustomBLEClient", "Notification received on handle: 0x%04X", handle);

    // Check if this is the characteristic we're interested in (0x2A39)
    if (handle == 0x2A39) {
      ESP_LOGI("CustomBLEClient", "Handling notification for characteristic 0x2A39");

      // Process the received data
      if (length < 2) {
        ESP_LOGW("CustomBLEClient", "Notification data too short!");
        return;
      }

      // Example: Interpret the first two bytes as a 16-bit integer
      uint16_t value = (data[1] << 8) | data[0];
      ESP_LOGI("CustomBLEClient", "Parsed value: %u", value);

      // Perform additional processing or publish data to Home Assistant
    } else {
      ESP_LOGW("CustomBLEClient", "Notification for unhandled characteristic: 0x%04X", handle);
    }
  }
};
#else
#include "esphome.h"

class CustomBLEClient : public PollingComponent, public ble_client::BLEClientNode {
 public:
  CustomBLEClient() : PollingComponent(15000) {}

  void setup() override {
    // This will be called by App.setup()
  }

  void update() override {
    // This will be called every "update_interval" milliseconds
  }

  void on_notify(const std::vector<uint8_t> &data) override {
    std::string data_str = "";
    for (auto c : data) {
      data_str += (char)c;
    }
    ESP_LOGD("BLE_NOTIFY", "Notification received: %s", data_str.c_str());
    // Process the data as needed
  }
};

#endif