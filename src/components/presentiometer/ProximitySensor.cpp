#include "../Component.h"
#include "ProximitySensor.h"
#include <Arduino.h>

ProximitySensor::ProximitySensor(int pin) : Component(new Pin(pin, INPUT_PIN), 1) { }

bool ProximitySensor::checkPresence() {
    return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}