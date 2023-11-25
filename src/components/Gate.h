#ifndef __GATE__
#define __GATE__
//#include "Servo.h"
#include "PWMServo.h"

class Gate {
    private:
        //Servo servo;
        PWMServo pwmServo;
    public:
        Gate(int pin);
        void setAngle(int angle);
        void incOneGrade();
        void decOneGrade();
        int getAngle();
};

#endif
