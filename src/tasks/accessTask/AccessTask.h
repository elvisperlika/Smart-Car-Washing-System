#ifndef __ACCESS_TASK__H__
#define __ACCESS_TASK__H__

#include "../Task.h"

class AccessTask: public Task {
    private:
        enum AccessTaskStates {
            CLOSE,
            OPENING,
            OPEN,
            CLOSING
        };
        AccessTaskStates gateState;
    public:
        AccessTask(int period, CarWash *carWash);
        void tick();
};

#endif
