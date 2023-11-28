#ifndef __ACCESS_TASK__
#define __ACCESS_TASK__

#include "tasks/Task.h"
#include "components/servo/servo_motor_impl.h"

class AccessTask: public Task {
    enum { CLOSE, WAITING_TO_OPEN, IN_OPENING, OPEN, WAITING_TO_CLOSE, IN_CLOSING } state;

    public:
        AccessTask(int period, CarWash *carWash);
        void tick();
};

#endif
