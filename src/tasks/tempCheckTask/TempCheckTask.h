#ifndef __TEMP_CHECK_TASK_H__
#define __TEMP_CHECK_TASK_H__

#include "../Task.h"
#include "components/termometer/TempSensorTMP36.h"
#include <Arduino.h>

class TempCheckTask: public Task {
    enum TempCheckTaskStates {
        OFFLINE,
        NORMAL_TEMP,
        HIGH_TEMP,
        ALERT
    };
    TempCheckTaskStates state;
    unsigned long tHighTemp;
    bool alert = false;

public:
    TempCheckTask(int period, CarWash *carWash);
    void tick();
};

#endif
