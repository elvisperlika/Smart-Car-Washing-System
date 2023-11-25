#ifndef __GATE__
#define __GATE__
#include <Servo.h>

class Gate {
    private:
        Servo servo;
    public:
        Gate(int pin);
        void setAngle(int angle);
        void incOneGrade();
        void decOneGrade();
        int getAngle();
};

#endif
