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
            carWash->getLed2()->fading();

            if (carWash->getDistance() > MAX_DISTANCE) {
                state = CAR_NOT_DETECTED;
            }

            break;
        
        case SLEEP:
            carWash->setSuspended(true);

            if (carWash->getState() == SystemState::DETECTION) {
                state = CAR_NOT_DETECTED;
            }
            break;
        
        default:        
            break;
    }
}