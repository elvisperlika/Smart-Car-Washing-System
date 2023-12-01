#include "checkInOutTask.h"

CheckInOutTask::CheckInOutTask(int period, CarWash *carWash) : Task(period, carWash) { }

void CheckInOutTask::tick() {
    switch (state)
    {
        case OFFLINE:
            if (carWash->getState() == SystemState::CHECK_IN){
                state = CheckInOutTaskStates::CHECK_IN;
            }
            break;
        case CHECK_IN:
            if (carWash->getDistance() >= MAX_DISTANCE) {
                state = CheckInOutTaskStates::OFFLINE;
            }

            if (carWash->getDistance() <= MIN_DISTANCE) {
                state = CheckInOutTaskStates::OFFLINE;
                checkInTimer = millis();
            }
            break;
        case CHECKING_IN:
            if (millis() - checkInTimer >= T2) {
                carWash->setState(SystemState::VEICHLE_WAITING);
                state = GATE_CLOSING;
            }
            break;
        case GATE_CLOSING:
            if (carWash->getServoMotor()->isClose()) {
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Ready to Wash");
                carWash->setState(SystemState::READY_TO_BE_WASHED);
                state = CheckInOutTaskStates::IN_WASH_WAITING;
            }
            break;
        case IN_WASH_WAITING:
            if (carWash->getState() == SystemState::CHECK_OUT) {
                state = CheckInOutTaskStates::CHECKING_OUT;
                checkOutTimer = millis();
            }                
            break;
        case CHECKING_OUT:
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
