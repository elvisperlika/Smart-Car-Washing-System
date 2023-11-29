#ifndef __TEMP_CHECK_TASK__
#define __TEMP_CHECK_TASK__

#define WARNING_TEMP 60

#include "../Task.h"
#include "components/termometer/TempSensorTMP36.h"
#include <Arduino.h>

class TempCheck: public Task {
    TempSensor* tempSensor;
    enum { T_NORM, HIGH_TEMP, ALERT } state;
    uint8_t tHighTemp;
    static uint8_t T_HIGH_TEMP;

public:
    TempCheck(int period, CarWash *carWash);
    void tick();
};

#endif
