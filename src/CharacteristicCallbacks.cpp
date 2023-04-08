#include "CharacteristicCallbacks.h"

CharacteristicCallbacks::CharacteristicCallbacks() {}

void CharacteristicCallbacks::onWrite(BLECharacteristic *pCharacteristic) {
    std::string value = pCharacteristic->getValue();
    // Do something
}


