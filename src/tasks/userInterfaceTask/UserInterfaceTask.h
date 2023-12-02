#ifndef __LED_ACTIVITY_TASK_H__
#define __LED_ACTIVITY_TASK_H__

#include "tasks/Task.h"
#include "Config.h"

enum UserInterfaceState { 
    DETECTION_,
    WELCOME_,
    CHECK_IN_,
    VEICHLE_WAITING_,
    WASHING_,
    WASHING_ERROR_,
    CHECK_OUT_
 };

class UserInterfaceTask: public Task {
    private:
        UserInterfaceState UIState;
        String buffer;
    public:
        UserInterfaceTask(int period, CarWash *carWash);
        void tick();
};

#endif
