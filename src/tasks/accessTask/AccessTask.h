#ifndef __ACCESS_TASK__H__
#define __ACCESS_TASK__H__

#include "../Task.h"

enum GATE_STATE { CLOSE, OPENING, OPEN, CLOSING };

class AccessTask: public Task {
    private:
        GATE_STATE gateState;
    public:
        AccessTask(int period, CarWash *carWash);
        void tick();
};

#endif
