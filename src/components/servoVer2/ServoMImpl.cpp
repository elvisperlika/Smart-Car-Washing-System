#include "components/servoVer2/ServoMImpl.h"

ServoMImpl::ServoMImpl(unsigned short pin) : ServoM(pin) {
    this->servo.attach(pin);
    this->angle = 0;
    this->servo.write(this->angle);
}

void ServoMImpl::setPosition(int _angle) {
    this->angle = _angle;
    this->servo.write(this->angle);
}

void ServoMImpl::incOneGrade() {
    this->angle++;
    this->servo.write(this->angle);
}

void ServoMImpl::decOneGrade() {
    this->angle--;
    this->servo.write(this->angle);
}

int ServoMImpl::getAngle() {
    return this->angle;
}
