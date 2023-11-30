#ifndef __DETECTION_TASK_H__
#define __DETECTION_TASK_H__
#include "../Task.h"
#include <Arduino.h>

enum DetectionTaskStates { 
    CAR_NOT_DETECTED,
    CAR_DETECTED,
    CHECK_IN,
    SLEEP
 };

class DetectionTask: public Task {
    private:
        DetectionTaskStates state;
        unsigned long tCarDetected;
        unsigned long tStart;
    public:
        DetectionTask(int period, CarWash *carWash);
        void tick();
};

#endif