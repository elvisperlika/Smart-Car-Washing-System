#ifndef __ACCESS_TASK__H__
#define __ACCESS_TASK__H__

#include "../Task.h"

class AccessTask: public Task {
    enum { CLOSE, WAITING_TO_OPEN, IN_OPENING, OPEN, WAITING_TO_CLOSE, IN_CLOSING } state;
    public:
        AccessTask(int period, CarWash *carWash);
        void tick();
};

#endif
