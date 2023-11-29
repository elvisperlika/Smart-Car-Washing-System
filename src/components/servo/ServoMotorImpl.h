#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include "ServoMotor.h"
#include "ServoTimer2.h"
#include <Arduino.h>

class ServoMotorImpl: public ServoMotor {
    private:
        ServoTimer2 motor;

    public:
        ServoMotorImpl(int pin);
        ~ServoMotorImpl();
        void setPosition(int angle);
        void incOneGrade();
        void decOneGrade();
        int getAngle();
};

#endif
