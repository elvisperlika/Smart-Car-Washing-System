#ifndef __CHECK_IN_OUT_TASK_H__
#define __CHECK_IN_OUT_TASK_H__

#include "../Task.h"
#include <Arduino.h>

class CheckInOutTask : public Task {
    private:
        enum CheckInOutTaskStates {
            OFFLINE,
            CHECK_IN,
            RESTORING,
            CHECKING_IN,
            GATE_CLOSING,
            IN_WASH_WAITING,
            CHECKING_OUT
        };
        CheckInOutTaskStates state;
        unsigned long checkInTimer;
        unsigned long checkOutTimer;
        bool checkError();
        unsigned short checkErrorCounter;
    public:
        CheckInOutTask(int period, CarWash *carWash);
        void tick();
        int getState();
};

#endif
