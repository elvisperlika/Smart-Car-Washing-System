#include "ProximitySensor.h"

ProximitySensor::ProximitySensor(int pin) : Component(new Pin(pin, INPUT), 1) { }

bool ProximitySensor::checkPresence() {
    return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}