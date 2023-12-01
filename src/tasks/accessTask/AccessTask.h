#ifndef __ACCESS_TASK__H__
#define __ACCESS_TASK__H__

#include "../Task.h"

enum GATE_STATE { CLOSE, WAITING_TO_OPEN, IN_OPENING, OPEN, WAITING_TO_CLOSE, IN_CLOSING };

class AccessTask: public Task {
    private:
        GATE_STATE gateState;
    public:
        AccessTask(int period, CarWash *carWash);
        void tick();
};

#endif
