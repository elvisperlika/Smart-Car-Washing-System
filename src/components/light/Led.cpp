#include "Led.h"

Led::Led(unsigned short pin) : Light(pin) { }

void Light::switchLight(bool state) {
    digitalWrite(this->pins[0].getPinNumber(), state ? HIGH : LOW);
}

bool Light::isOn() {
    return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}

void Light::fading() {
    if ((currentLight >= 255 && fadeState == 1) || (currentLight <= 0 && fadeState == -1)) {
        fadeState = !fadeState;
    }
    currentLight += fadeState ? 1 : -1;
    digitalWrite(this->pins[0].getPinNumber(), currentLight);
}
