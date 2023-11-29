#ifndef __SLEEPMODETASK__
#define __SLEEPMODETASK__

#include "../Task.h"
#include <avr/sleep.h>
#include "Config.h"

class SleepModeTask: public Task {
    private: 
    public:
        SleepModeTask(int period, CarWash *carWash);
        void tick();
};

#endif
