#include "WashTask.h"

WashTask::WashTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = WashTaskStates::OFFLINE;
}

void WashTask::tick() {
    switch (state)
    {
        case WashTaskStates::OFFLINE:
            if (carWash->getState() == SystemState::WASHING) {
                state = WashTaskStates::WASHING;
                washingTime = millis();
                totalSuspendedTime = 0;
            }
            break;
            
        case WashTaskStates::WASHING:
            carWash->setGlobalWashingTime(round(millis() - washingTime + totalSuspendedTime));
            
            if (millis() - washingTime + totalSuspendedTime >= T3) {
                carWash->setState(SystemState::CHECK_OUT);
                state = WashTaskStates::CAR_EXIT;
                break;
            }

            if (carWash->getState() == SystemState::WASHING_ERROR) {
                state = WashTaskStates::SUSPENDED;
                startSuspendedTime = millis();
            }
            break;
                
        case WashTaskStates::SUSPENDED:
            if (carWash->getState() == SystemState::WASHING) {
                state = WashTaskStates::WASHING;
                totalSuspendedTime += millis() - startSuspendedTime;
            }
            break;
        
        case WashTaskStates::CAR_EXIT:
            if (carWash->getState() == SystemState::DETECTION) {
                state = WashTaskStates::OFFLINE;
                carWash->setGlobalWashingTime(0);
            }
            break;
    }
}