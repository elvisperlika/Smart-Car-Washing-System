#ifndef __GATE__
#define __GATE__
#include <Servo.h>

class Gate {
    private:
        int pin;
        Servo servo;
    public:
        Gate(int pin);
        void setAngle(int angle);
};

#endif
