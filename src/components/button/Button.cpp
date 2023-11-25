#include "Button.h"
#include "Arduino.h"

Button::Button(unsigned short pin) : Component(new Pin(pin, INPUT_PIN), 1) { }

bool Button::isClicked() { }
