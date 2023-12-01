#include "ServoMImpl.h"

ServoMImpl::ServoMImpl(unsigned short pin) : ServoM(pin) {
    servo.attach(pin);
    angle = CLOSE_GATE_DEGREE;
    servo.write(this->angle);
}

void ServoMImpl::setPosition(int _angle) {
    if (_angle > CLOSE_GATE_DEGREE) {
        angle = CLOSE_GATE_DEGREE;
    } else if (_angle < OPEN_GATE_DEGREE) {
        angle = OPEN_GATE_DEGREE;
    }

    float coeff = (2400.0 - 544.0) / 180;
    servo.write(544 + _angle * coeff);
}

bool ServoMImpl::isClose() {
    return angle == CLOSE_GATE_DEGREE;
}

bool ServoMImpl::isOpen() {
    return angle == OPEN_GATE_DEGREE;
}