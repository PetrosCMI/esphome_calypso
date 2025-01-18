# esphome_calypso
Interface Calypso Ultrasonic Portable (BLE) Wind Sensor to Home Assistant.
In this implementation the MAC address of the sensor is hard-coded (you'll have to update for your device).
This implementation attempts to minimize the power consumption of the BLE device since my device seems to deplete quickly.
To minimize BLE device power, extra sensors are turned off and sampling rate is 1Hz.
