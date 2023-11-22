#include <Arduino.h>
#include "Gate.h"

Gate::Gate(int pin){
    this->servo.attach(pin);
}

void Gate::setAngle(int angle){
    this->servo.write(angle);
}
