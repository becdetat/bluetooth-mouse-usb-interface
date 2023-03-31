# Bluetooth mouse to USB adapter

I need to hook up my ancient, BT-less lab PC up to a Bluetooth mouse, because I don't have any wired mice. Because it's 2023?

## BOM
- ESP32 dev board with WIFI, BT, and BTLE

## Steps
(according to ChatGPT)

1. Use the BLE HID library to advertise as a HID
    - ESP32 BLE HID Library: https://github.com/T-vK/ESP32-BLE-Keyboard
2. Find a way to put the ESP32 into pairing mode
3. Implement the HID protocol on the ESP32 to receive data from the mouse using the HID library included with the Arduino framework for ESP32
    - ESP32 HID Library: https://github.com/espressif/arduino-esp32/tree/master/libraries/HID
4. Use the ESP32 USB HID library to configure the USB interface as a HID device
    - ESP32 USB HID Library: https://github.com/joshajohnson/esp32-usb-hid
5. Map the data received from the mouse to the appropriate HID report format for a mouse

## Credits
Code shamelessly stolen from:
- https://github.com/T-vK/ESP32-BLE-Mouse
- 