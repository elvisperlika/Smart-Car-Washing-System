#ifndef __GATE__
#define __GATE__
#include "PWMServo.h"

class Gate {
    private:
        PWMServo servo;
    public:
        Gate(int pin);
        void setAngle(int angle);
        void incOneGrade();
        void decOneGrade();
        int getAngle();
};

#endif
