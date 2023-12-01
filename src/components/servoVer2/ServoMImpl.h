#ifndef SERVOIMPL_H
#define SERVOIMPL_H
#include "components/servoVer2/ServoM.h"
#include <Servo.h>

class ServoMImpl : public ServoM {
    private:
    public:
        ServoMImpl(unsigned short pin);
        void setPosition(int angle);
        void incOneGrade();
        void decOneGrade();
        int getAngle();
};

#endif
