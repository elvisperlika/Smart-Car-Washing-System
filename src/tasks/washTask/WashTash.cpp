#include "WashTask.h"

WashTask::WashTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = WashTaskStates::OFFLINE;
}

void WashTask::tick() {
    switch (state)
    {
        case WashTaskStates::OFFLINE:
            if (carWash->getState() == SystemState::READY_TO_BE_WASHED_BUTTON_PRESSED) {
                state = WashTaskStates::WASHING;
                washingTime = millis();
                suspendedTime = 0;
            }
            break;
            
        case WashTaskStates::WASHING:
            if (millis() - washingTime - (millis() - suspendedTime) < T3) {
                carWash->setState(SystemState::CHECK_OUT);
                state = WashTaskStates::CAR_EXIT;
                break;
            }

            if (carWash->getState() == SystemState::WASHING_ERROR) {
                state = WashTaskStates::SUSPENDED;
            }
            break;
                
        case WashTaskStates::SUSPENDED:
            if (carWash->getState() == SystemState::WASHING) {
                state = WashTaskStates::WASHING;
            }
            break;
        
        case WashTaskStates::CAR_EXIT:
            if (carWash->getState() == SystemState::DETECTION) {
                state = WashTaskStates::OFFLINE;
            }
            break;
    }
}

int WashTask::getState() {
    return state;
}