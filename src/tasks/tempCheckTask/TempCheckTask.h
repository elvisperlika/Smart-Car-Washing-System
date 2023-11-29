#ifndef __TEMP_CHECK_TASK_H__
#define __TEMP_CHECK_TASK_H__

#define WARNING_TEMP 60

#include "../Task.h"
#include "components/termometer/TempSensorTMP36.h"
#include <Arduino.h>

class TempCheckTask: public Task {
    enum { T_NORM, HIGH_TEMP, ALERT } state;
    uint8_t tHighTemp;
    static uint8_t T_HIGH_TEMP;
    bool alert = false;

public:
    TempCheckTask(int period, CarWash *carWash);
    void tick();
};

#endif
