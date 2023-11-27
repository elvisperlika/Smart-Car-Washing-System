#ifndef __ACCESS_TASK__
#define __ACCESS_TASK__

#include "Task.h"
#include "../components/gate/Gate.h"

class AccessTask: public Task {
    enum { CLOSE, WAITING_TO_OPEN, IN_OPENING, OPEN, WAITING_TO_CLOSE, IN_CLOSING } state;
    uint8_t tOpen;
    uint8_t tClose;
    static uint8_t TOPEN;
    static uint8_t TCLOSE;

    public:
        AccessTask(int period, CarWash *carWash);
        void tick();
};

#endif
