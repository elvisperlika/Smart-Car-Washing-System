#include "DetectionTask.h"

DetectionTask::DetectionTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = DetectionTaskStates::CAR_NOT_DETECTED;
    tStart = millis();
}

void DetectionTask::tick() {
    switch (state)
    {
        case DetectionTaskStates::CAR_NOT_DETECTED:
            if (carWash->getPresence() && carWash->getServoMotor()->isClose()) {
                carWash->setState(SystemState::WELCOME);
                tCarDetected = millis();
                state = DetectionTaskStates::CAR_DETECTED;
            }

            if (millis() - tStart >= T0 && carWash->getServoMotor()->isClose()) {
                state = DetectionTaskStates::SLEEP;
                carWash->setSuspended(true);
            }
            break;
        
        case DetectionTaskStates::CAR_DETECTED:
            Serial.println("------------------------------------");
            if (millis() - tCarDetected >= T1) {
                state = DetectionTaskStates::CHECK_IN;
                carWash->setState(SystemState::CHECK_IN);
            }
            else {
                carWash->setState(SystemState::WELCOME);
            }
            break;

        case DetectionTaskStates::CHECK_IN:
            Serial.println("/////////////////////////////////////////");
            if (carWash->getState() == SystemState::READY_TO_BE_WASHED) {
                state = DetectionTaskStates::OFF;
            }
            
            if (carWash->getState() == SystemState::DETECTION) {
                state = DetectionTaskStates::CAR_NOT_DETECTED;
                tStart = millis();
            }
            break;

        case DetectionTaskStates::OFF:
            if (carWash->getState() == SystemState::DETECTION) {
                state = DetectionTaskStates::CAR_NOT_DETECTED;
                tStart = millis();
            }
            break;
        
        case DetectionTaskStates::SLEEP:
            if (carWash->getState() == SystemState::DETECTION) {
                tCarDetected = millis();
                state = DetectionTaskStates::CAR_DETECTED;
            }
            break;
    }
}

int DetectionTask::getState() {
    return state;
}