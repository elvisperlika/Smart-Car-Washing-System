#include "Gate.h"

Gate::Gate(unsigned short pin) : Component(new Pin(pin, OUTPUT), 1){
    this->servo.attach(pin);
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