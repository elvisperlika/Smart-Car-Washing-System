#ifndef __GATE__
#define __GATE__
#include <Servo.h>
#include "../Component.h"

class Gate : public Component {
    private:
        Servo servo;
    public:
        Gate(int pin);
        void open();
        void close();
};

#endif
