#include <Arduino.h>
#include "Gate.h"

Gate* gate = new Gate(8);

void setup() {
  Serial.begin(9600);
}

void loop() {
  gate->setAngle(90);
  delay(1000);
  gate->setAngle(0);
  delay(1000);
}
