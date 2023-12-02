#ifndef __LED_ACTIVITY_TASK_H__
#define __LED_ACTIVITY_TASK_H__

#include "tasks/Task.h"

class UserInterfaceTask: public Task {
    private:
        enum UserInterfaceTaskStates { 
            DETECTION_,
            WELCOME_,
            CHECK_IN_,
            VEICHLE_WAITING_,
            WASHING_,
            WASHING_ERROR_,
            CHECK_OUT_
        };
        UserInterfaceTaskStates state;
        String buffer;
    public:
        UserInterfaceTask(int period, CarWash *carWash);
        void tick();
};

#endif
