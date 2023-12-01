#ifndef __SERVO_MOTOR_2_H__
#define __SERVO_MOTOR_2_H__

#include "components/Component.h"

class ServoM : public Component {
    public:
        ServoM(unsigned short pin);
        virtual void setPosition(int angle) = 0;
        virtual int getAngle() = 0;
};

#endif
