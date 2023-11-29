#ifndef __BUTTON_TASK_H__
#define __BUTTON_TASK_H__

#include "../Task.h"
#include <Arduino.h>

class ButtonTask : public Task {
public:
    ButtonTask(int period, CarWash *carWash);
    void checkButtonState();
};

#endif
