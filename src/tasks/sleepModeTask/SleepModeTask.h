#ifndef __SLEEP_MODE_TASK_H__
#define __SLEEP_MODE_TASK_H__

#include "../Task.h"
#include <avr/sleep.h>

class SleepModeTask: public Task {
    public:
        SleepModeTask(int period, CarWash *carWash);
        void tick();
};
#endif
