#ifndef __TEMP_CHECK_TASK_H__
#define __TEMP_CHECK_TASK_H__

#include "../Task.h"
#include "components/termometer/TempSensorTMP36.h"
#include <Arduino.h>

class TempCheckTask: public Task {
<<<<<<< HEAD
    enum TempCheckTaskStates {
        OFFLINE,
        NORMAL_TEMP,
        HIGH_TEMP,
        ALERT
    };
    TempCheckTaskStates state;
    unsigned long tHighTemp;
    bool alert = false;
=======
    private:
        enum TempCheckTaskStates {
            OFFLINE,
            NORMAL_TEMP,
            HIGH_TEMP,
            ALERT
        };
        TempCheckTaskStates state;
        uint8_t tHighTemp;
        bool alert = false;
>>>>>>> 60a6591a444ea8a73b354d2874f654f6b507e831

    public:
        TempCheckTask(int period, CarWash *carWash);
        void tick();
        int getState();
};

#endif
