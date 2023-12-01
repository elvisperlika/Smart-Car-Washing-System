#ifndef __BUTTON_TASK_H__
#define __BUTTON_TASK_H__

#include "../Task.h"
#include <Arduino.h>

class ButtonTask : public Task {
    private:
        enum ButtonTaskStates {
            OFFLINE,
            BUTTON_PRESSED
        };
        ButtonTaskStates state;
    public:
        ButtonTask(int period, CarWash *carWash);
        void tick();
};

#endif
