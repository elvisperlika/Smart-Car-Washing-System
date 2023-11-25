#include "ButtonImpl.h" // Include the header file for ButtonImpl class
#include "Arduino.h" // Include the Arduino library

ButtonImpl::ButtonImpl(int pin) {
  this->pin = pin; // Set the passed pin as the ButtonImpl class pin
  pinMode(pin, INPUT); // Set the pin mode to INPUT for reading button state
}

bool ButtonImpl::isClicked() {
  return clicked; // Return the value of the 'clicked' member variable
}
