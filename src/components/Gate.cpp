#include <Arduino.h>
#include "Gate.h"

Gate::Gate(int pin){
    this->servo.attach(pin);
    this->servo.write(0);
}

void Gate::setAngle(int angle){
    this->servo.write(angle);
}

void Gate::incOneGrade(){
    this->servo.write(this->servo.read() + 1);
}

void Gate::decOneGrade(){
    this->servo.write(this->servo.read() - 1);
}

int Gate::getAngle(){
    return this->servo.read();
}
