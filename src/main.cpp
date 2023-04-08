#include <BLEDevice.h>
#include <HardwareSerial.h>
#include "BluetoothReceiver.h"

void setup() {
    Serial.begin(9600);
    while (!Serial);

    Serial.println("Starting BT receiver");
    startBtReceiver();

    Serial.println("Finished init, starting loop");
}



void loop() {

}