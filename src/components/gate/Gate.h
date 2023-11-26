#ifndef __GATE__
#define __GATE__

#include "../Component.h"
#include <Servo.h>


class Gate : public Component {
    private:
        Servo servo;
    public:
        Gate(unsigned short pin);
        void setAngle(int angle);
        void incOneGrade();
        void decOneGrade();
        int getAngle();
};

#endif
