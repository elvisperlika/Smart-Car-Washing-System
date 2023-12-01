#ifndef __DETECTION_TASK_H__
#define __DETECTION_TASK_H__
#include "../Task.h"
#include <Arduino.h>

class DetectionTask: public Task {
    private:
        enum DetectionTaskStates { 
            CAR_NOT_DETECTED,
            CAR_DETECTED,
            CHECK_IN,
            SLEEP
        };
        DetectionTaskStates state;
        unsigned long tCarDetected;
        unsigned long tStart;        
    public:
        DetectionTask(int period, CarWash *carWash);
        void tick();
};

#endif