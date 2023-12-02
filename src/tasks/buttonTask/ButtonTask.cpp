#include "ButtonTask.h"

ButtonTask::ButtonTask(int period, CarWash *carWash) : Task(period, carWash) { 
    state = ButtonTaskStates::OFFLINE;
}

void ButtonTask::tick() {
    switch (state)
    {
        case ButtonTaskStates::OFFLINE:
            if (carWash->getState() == SystemState::READY_TO_BE_WASHED && carWash->isButtonPressed()) {
                state = ButtonTaskStates::BUTTON_PRESSED;
            }
            break;
        case ButtonTaskStates::BUTTON_PRESSED:
            if (!carWash->isButtonPressed()) {
                carWash->setState(SystemState::WASHING);
                state = ButtonTaskStates::OFFLINE;
            }
            break;
    }
}
