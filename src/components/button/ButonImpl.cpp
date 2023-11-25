#include "ButtonImpl.h"
#include "Arduino.h"

ButtonImpl::ButtonImpl(unsigned short pin) : Button(pin) { }

bool ButtonImpl::isClicked() {
  return digitalRead(this->pins[0].getPinNumber()) == HIGH;
}
