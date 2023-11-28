#include "HCSR501.h"

HCSR501::HCSR501(unsigned short pin) : ProximitySensor(pin) {}

bool HCSR501::checkPresence() {
    return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}