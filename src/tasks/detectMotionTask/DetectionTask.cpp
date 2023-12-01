#include "DetectionTask.h"

DetectionTask::DetectionTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = CAR_NOT_DETECTED;
    tStart = millis();
}

void DetectionTask::tick() {
    switch (state)
    {
        case DetectionTaskStates::CAR_NOT_DETECTED:
            if (carWash->getPresence()) {
                tCarDetected = millis();
                carWash->getLed1()->switchLight(true);
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Welcome");
                state = DetectionTaskStates::CAR_DETECTED;
            }

            if (millis() - tStart >= T0) {
                state = DetectionTaskStates::SLEEP;
            }
            break;
        
        case DetectionTaskStates::CAR_DETECTED:
            if (millis() - tCarDetected >= T1) {
                state = DetectionTaskStates::CHECK_IN;
                carWash->setState(SystemState::CHECK_IN);
                carWash->getLcd()->displayText("Proceed to the washing area!");
            }
            break;

        case DetectionTaskStates::CHECK_IN:

            break;

        case DetectionTaskStates::OFF:
            if (carWash->getState() == SystemState::DETECTION) {
                state = DetectionTaskStates::CAR_NOT_DETECTED;
                carWash->getLed1()->switchLight(false);
            }
            break;
        
        case DetectionTaskStates::SLEEP:
            carWash->setSuspended(true);
            if (carWash->getState() == SystemState::DETECTION) {
                tCarDetected = millis();
                state = DetectionTaskStates::CAR_DETECTED;
            }
            break;
        
        default:        
            break;
    }
}