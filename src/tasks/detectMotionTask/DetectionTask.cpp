#include "DetectionTask.h"

DetectionTask::DetectionTask(int period, CarWash *carWash) : Task(period, carWash) {
    carWash->setState(SystemState::DETECTION);
    state = CAR_NOT_DETECTED;
    tStart = millis();
}

void DetectionTask::tick() {
    switch (state)
    {
        case CAR_NOT_DETECTED:
            if (carWash->getPresence()) {
                tCarDetected = millis();
                carWash->getLed1()->switchLight(true);
                state = CAR_DETECTED;
            }

            if (millis() - tStart >= T0) {
                state = SLEEP;
            }
            break;
        
        case CAR_DETECTED:
            if (millis() - tCarDetected >= T1) {
                state = CHECK_IN;
                carWash->getLcd()->displayText("Proceed to the washing area!");
            }
            break;

        case CHECK_IN:
            if (carWash->getDistance() > MAX_DISTANCE) {
                state = CAR_NOT_DETECTED;
            }

            break;
        
        case SLEEP:
            carWash->setSuspended(true);
            carWash->getLed1()->switchLight(false);
            if (carWash->getState() == SystemState::DETECTION) {
                tCarDetected = millis();
                state = CAR_DETECTED;
            }
            break;
        
        default:        
            break;
    }
}