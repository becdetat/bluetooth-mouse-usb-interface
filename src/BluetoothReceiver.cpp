#include "BluetoothReceiver.h"
#include <HardwareSerial.h>
#include "CharacteristicCallbacks.h"
//#include <BLEHIDDevice.h>
#include <BLEMouse.h>
#include <BLEDevice.h>
//#include <ArduinoBLE.h>

BLEServer *pServer;
BLEService *pService;
BLECharacteristic *pCharacteristic;
BleMouse *bleMouse;

void startBtReceiver() {
    Serial.print("Setting up BT server and starting the service...");
    BLEDevice::init("Tanby Dynamics BT Receiver");
    pServer = BLEDevice::createServer();
    pService = pServer->createService(SERVICE_UUID);
    pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );
    pCharacteristic->setCallbacks(new CharacteristicCallbacks());
    pService->start();
    Serial.println("done");

    Serial.print("Setting up advertising...");
    BLEAdvertising *pAdvertising = pServer->getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(false);
    pAdvertising->setMinPreferred(0x06);  // 100ms
    pAdvertising->setMinPreferred(0x12);  // 200ms
    pAdvertising->start();
    Serial.println("done");

    Serial.print("Setting up virtual mouse...");
    bleMouse = new BleMouse(
        "TD Bluetooth Mouse",
        "Tanby Dynamics"
    );
    bleMouse->setBatteryLevel(100);
    bleMouse->begin();
    Serial.println("done");
}