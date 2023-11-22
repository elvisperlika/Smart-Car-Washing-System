#ifndef __GATE__
#define __GATE__
#include <Servo.h>

class Gate {
    private:
        Servo servo;
    public:
        Gate(int pin);
        void open();
        void close();
};

#endif
