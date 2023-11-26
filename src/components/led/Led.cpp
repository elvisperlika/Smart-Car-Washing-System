#include "Led.h"

Led::Led(unsigned short pin) : Component(new Pin(pin, OUTPUT), 1) { }

void Led::switchLed(bool state) {
  digitalWrite(this->pins[0].getPinNumber(), state ? HIGH : LOW);
}

bool Led::isOn() {
  return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}
