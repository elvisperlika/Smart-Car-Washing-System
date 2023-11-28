#include "Led.h"

Led::Led(unsigned short pin) : Light(pin) { }

void Led::switchLight(bool state) {
    digitalWrite(this->pins[0].getPinNumber(), state ? HIGH : LOW);
}

bool Led::isOn() {
    return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}

void Led::fading() {
    if ((currentLight >= 255 && fadeState == true) || (currentLight <= 0 && fadeState == false)) {
        fadeState = !fadeState;
    }
    currentLight += fadeState ? 1 : -1;
    digitalWrite(this->pins[0].getPinNumber(), currentLight);
}
