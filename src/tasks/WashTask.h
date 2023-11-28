#ifndef __WASHTASK__
#define __WASHTASK__

#include "Task.h"
#include <Arduino.h>

enum TaskState{
    OFFLINE,
    WASHING,
    TEMPERATURE_WARNING,
    SUSPENDED
};

class WashTask: public Task {
    private:
        TaskState taskState;
        unsigned long washingTime;
        unsigned long warningTime;
        unsigned long suspendedTime;
    public:
        WashTask(int period, CarWash *carWash);
        void tick();
};

#endif
