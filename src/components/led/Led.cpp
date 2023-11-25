#include "Led.h"
#include "Arduino.h"

Led::Led(unsigned short pin) : Component(new Pin(pin, OUTPUT_PIN), 1) { }

void Led::switchLed(bool state) {
  digitalWrite(this->pins[0].getPinNumber(), state ? HIGH : LOW);
}

bool Led::isOn() {
  return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}
