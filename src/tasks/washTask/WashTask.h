#ifndef __WASH_TASK_H__
#define __WASH_TASK_H__

#include "../Task.h"
#include <Arduino.h>

class WashTask: public Task {
    private:
        enum WashTaskStates {
            OFFLINE,
            WASHING,            
            SUSPENDED,
            CAR_EXIT
        };
        WashTaskStates state;
        unsigned long washingTime;
        unsigned long warningTime;
        unsigned long startSuspendedTime;
        unsigned long totalSuspendedTime;
    public:
        WashTask(int period, CarWash *carWash);
        void tick();
        int getState();
};

#endif
