#ifndef __SERVO_MOTOR_H__
#define __SERVO_MOTOR_H__

#include "components/Component.h"

class ServoMotor : public Component {
    public:
        ServoMotor(unsigned short pin);
        virtual void setPosition(int angle) = 0;
        virtual void incOneGrade() = 0;
        virtual void decOneGrade() = 0;
        virtual int getAngle() = 0;
};

#endif
