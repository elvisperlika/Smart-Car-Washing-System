#ifndef __BLINK_TASK_H__
#define __BLINK_TASK_H__

#include "../Task.h"
// #include "Led.h"

class BlinkTask: public Task {

    int pin;
    //Light* led;
    enum { ON, OFF} state;

    public:
        BlinkTask(int period, CarWash *carWash);
        void tick();
};

#endif
