#include "Pin.h"

Pin::Pin(int pinNumber, PinType type) {
    this->pinNumber = pinNumber;
    this->type = type;
}

Pin::Pin() {
}

int Pin::getPinNumber() {
    return this->pinNumber;
}

PinType Pin::getPinType() {
    return this->type;
}