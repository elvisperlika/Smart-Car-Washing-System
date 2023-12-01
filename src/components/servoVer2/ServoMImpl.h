#ifndef SERVOIMPL_H
#define SERVOIMPL_H
#include "components/servoVer2/ServoM.h"
#include <Servo.h>

class ServoMImpl : public ServoM {
    private:
        Servo servo;
        int angle;
    public:
        ServoMImpl(unsigned short pin);
        void setPosition(int _angle);
        void incOneGrade();
        void decOneGrade();
        int getAngle();
};

#endif
