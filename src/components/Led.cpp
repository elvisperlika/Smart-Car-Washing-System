#include "Led.h" // Include the header file for the Led class
#include "Arduino.h" // Include the Arduino library

Led::Led(int pin) {
  this->pin = pin; // Set the passed pin as the Led class pin
  pinMode(pin, OUTPUT); // Set the pin mode to OUTPUT
}

void Led::switchOn() {
  digitalWrite(pin, HIGH); // Turn on the LED by setting the pin to HIGH
}

void Led::switchOff() {
  digitalWrite(pin, LOW); // Turn off the LED by setting the pin to LOW
}
