#include "components/servoVer2/ServoMImpl.h"

ServoMImpl::ServoMImpl(unsigned short pin) : ServoM(pin) {
    this->servo.attach(pin);
    this->angle = 0;
    this->servo.write(this->angle);
}

void ServoMImpl::setPosition(int _angle) {
    if (_angle > 180) {
        this->angle = 180;
    } else if (_angle < 0) {
        this->angle = 0;
    }

    float coeff = (2400.0  - 544.0) / 180;
    this->servo.write(544 + _angle * coeff);
}
