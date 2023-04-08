#ifndef CHARACTERISTIC_CALLBACKS_H
#define CHARACTERISTIC_CALLBACKS_H

//#include <BLEDevice.h>
#include <BLEServer.h>

class CharacteristicCallbacks : public BLECharacteristicCallbacks {
public:
    CharacteristicCallbacks();
    void onWrite(BLECharacteristic *pCharacteristic);
};

#endif
