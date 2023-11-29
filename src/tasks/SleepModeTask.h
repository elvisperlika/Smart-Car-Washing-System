#ifndef __SLEEPMODETASK__
#define __SLEEPMODETASK__

#include "Task.h"

class SleepModeTask: public Task {
    private: 
    public:
        SleepModeTask(int period, CarWash *carWash);
        void tick();
};

#endif
