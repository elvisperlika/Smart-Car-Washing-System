#ifndef __WASHTASK__
#define __WASHTASK__

#include "Task.h"
#include <Arduino.h>

class WashTask: public Task {
    private:
        
    public:
        WashTask(int period, CarWash *carWash);
        void tick();
};

#endif
