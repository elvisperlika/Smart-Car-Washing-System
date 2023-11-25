#include <Arduino.h>
#include "Gate.h"

Gate::Gate(int pin){
    //this->servo.attach(pin);
    this->pwmServo.attach(pin);
    //this->servo.write(0);
    this->pwmServo.write(0);
}

void Gate::setAngle(int angle){
    this->pwmServo.write(angle);
}

void Gate::incOneGrade(){
    //this->servo.write(this->servo.read() + 1);
    this->pwmServo.write(this->pwmServo.read() + 1);
}

void Gate::decOneGrade(){
    this->pwmServo.write(this->pwmServo.read() - 1);
}

int Gate::getAngle(){
    return this->pwmServo.read();
}
