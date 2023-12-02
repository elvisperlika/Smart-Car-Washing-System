#include "CheckInOutTask.h"

CheckInOutTask::CheckInOutTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = CheckInOutTaskStates::OFFLINE;
}

void CheckInOutTask::tick() {
    switch (state)
    {
        case CheckInOutTaskStates::OFFLINE:
            if (carWash->getState() == SystemState::CHECK_IN){
                state = CheckInOutTaskStates::CHECK_IN;
            }
            break;
        case CheckInOutTaskStates::CHECK_IN:
            if (carWash->getDistance() >= MAX_DISTANCE) {
                state = CheckInOutTaskStates::OFFLINE;
                carWash->setState(SystemState::DETECTION);
            }

            if (carWash->getDistance() <= MIN_DISTANCE) {
                state = CheckInOutTaskStates::CHECKING_IN;
                checkInTimer = millis();
            }
            break;
        case CheckInOutTaskStates::CHECKING_IN:
            if (carWash->getDistance() > MIN_DISTANCE) {
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
            if (checkOutTimer >= T4) {
                carWash->setState(SystemState::DETECTION);
                state = CheckInOutTaskStates::OFFLINE;
            }

            if (carWash->getDistance() < MAX_DISTANCE) {
                checkOutTimer = millis();
            }            
            break;
    }
}
