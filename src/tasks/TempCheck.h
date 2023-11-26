#ifndef __TEMPCHECK__
#define __TEMPCHECK__

#include "Task.h"
#include "../components/termometer/TempSensorTMP36.h"
#include <Arduino.h>

class TempCheck: public Task {
    TempSensor* tempSensor;
    enum { T_NORM, HIGH_TEMP, ALERT } state;
    uint8_t tHighTemp;
    static uint8_t T_HIGH_TEMP;

public:
    TempCheck(int pin);
    void init(int period);
    void tick();
};

#endif