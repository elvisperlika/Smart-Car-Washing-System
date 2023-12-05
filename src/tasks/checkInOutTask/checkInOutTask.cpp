#include "CheckInOutTask.h"

CheckInOutTask::CheckInOutTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = CheckInOutTaskStates::OFFLINE;
    checkErrorCounter = 0;
}

void CheckInOutTask::tick() {
    int currentDistance = carWash->getDistance();

    switch (state)
    {
        case CheckInOutTaskStates::OFFLINE:
            if (carWash->getState() == SystemState::CHECK_IN){
                state = CheckInOutTaskStates::CHECK_IN;
            }
            break;
        case CheckInOutTaskStates::CHECK_IN:
            if (currentDistance >= MAX_ERROR_DISTANCE) {
                if (!checkError()) {
                    break;
                }
            } else {
                checkErrorCounter = 0;
            }

            if (currentDistance >= MAX_DISTANCE) {
                state = CheckInOutTaskStates::RESTORING;
                carWash->setState(SystemState::DETECTION);
                Serial.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
            }

            if (currentDistance <= MIN_DISTANCE) {
                state = CheckInOutTaskStates::CHECKING_IN;
                checkInTimer = millis();
            }
            break;
        
        case CheckInOutTaskStates::RESTORING:
            if (carWash->getServoMotor()->isClose()) {
                state = CheckInOutTaskStates::OFFLINE;
            }
            break;

        case CheckInOutTaskStates::CHECKING_IN:
            if (currentDistance >= MAX_ERROR_DISTANCE) {
                if (!checkError()) {
                    break;
                }
            } else {
                checkErrorCounter = 0;
            }

            if (currentDistance > MIN_DISTANCE) {
                state = CheckInOutTaskStates::CHECK_IN;
            }

            if (millis() - checkInTimer >= T2) {
                carWash->setState(SystemState::VEICHLE_WAITING);
                state = GATE_CLOSING;
            }
            break;
        case CheckInOutTaskStates::GATE_CLOSING:
            if (carWash->getServoMotor()->isClose()) {
                carWash->setState(SystemState::READY_TO_BE_WASHED);
                state = CheckInOutTaskStates::IN_WASH_WAITING;
            }
            break;
        case CheckInOutTaskStates::IN_WASH_WAITING:
            if (carWash->getState() == SystemState::CHECK_OUT) {
                state = CheckInOutTaskStates::CHECKING_OUT;
                checkOutTimer = millis();
            }                
            break;
        case CheckInOutTaskStates::CHECKING_OUT:
            if (currentDistance >= MAX_ERROR_DISTANCE) {
                if (!checkError()) {
                    break;
                }
            } else {
                checkErrorCounter = 0;
            }

            if (millis() - checkOutTimer >= T4) {
                carWash->setState(SystemState::DETECTION);
                state = CheckInOutTaskStates::OFFLINE;
            }

            if (currentDistance < MAX_DISTANCE) {
                checkOutTimer = millis();
            }            
            break;
    }
}

<<<<<<< HEAD
bool CheckInOutTask::checkError() {
    if (checkErrorCounter++ >= 3) {
        return true;
    }
    return false;
=======
int CheckInOutTask::getState() {
    return state;
>>>>>>> 60a6591a444ea8a73b354d2874f654f6b507e831
}