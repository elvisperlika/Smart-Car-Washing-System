#include "WashTask.h"

WashTask::WashTask(int period, CarWash *carWash) : Task(period, carWash) {
    taskState = TaskState::OFFLINE;
}

void WashTask::tick() {
    switch (taskState)
    {
        case OFFLINE:
            carWash->getLed2()->switchLight(true);

            if (carWash->getState() == SystemState::READY_TO_BE_WASHED_BUTTON_PRESSED) {                
                taskState = TaskState::WASHING;
                washingTime = millis();
                suspendedTime = 0;
            }
            break;
            
        case WASHING:
            if (millis() - washingTime - (millis() - suspendedTime) < T3) {
                carWash->setState(SystemState::CHECK_OUT);
                break;
            }

            if (carWash->getTemperature() >= MAX_TEMPERATURE) {
                taskState = TaskState::TEMPERATURE_WARNING;
                warningTime = millis();
            }

            break;
                
        case TEMPERATURE_WARNING:
            if (millis() - washingTime - (millis() - suspendedTime) < T3) {
                carWash->setState(SystemState::CHECK_OUT);
                break;
            }

            if (carWash->getTemperature() < MAX_TEMPERATURE) {
                taskState = TaskState::WASHING;
            }

            if (millis() - warningTime < T4) {
                taskState = TaskState::SUSPENDED;
                carWash->setSuspended(true);
                suspendedTime = millis();
            }

            break;
                
        case SUSPENDED:
            if (!carWash->isSuspended()) {
                taskState = TaskState::WASHING;
            }
            break;
                
        default:
            break;
    }
}