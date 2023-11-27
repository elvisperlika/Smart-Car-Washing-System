#include "Led.h"

Led::Led(unsigned short pin) : Light(pin) { }

void Light::switchLight(bool state) {
    digitalWrite(this->pins[0].getPinNumber(), state ? HIGH : LOW);
}

bool Light::isOn() {
    return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}
