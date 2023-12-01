#include "checkInOutTask.h"

CheckInOutTask::CheckInOutTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = CheckInOutTaskStates::OFFLINE;
}

void CheckInOutTask::tick() {
    switch (state)
    {
        case CheckInOutTaskStates::OFFLINE:
            Serial.println("OFFLINE");
            carWash->getLed2()->switchLight(false);
            if (carWash->getState() == SystemState::CHECK_IN){
                state = CheckInOutTaskStates::CHECK_IN;
            }
            break;
        case CheckInOutTaskStates::CHECK_IN:
            Serial.println("CHECK_IN");
            carWash->getLed2()->blink(100);
            if (carWash->getDistance() >= MAX_DISTANCE) {
                state = CheckInOutTaskStates::OFFLINE;
                carWash->setState(SystemState::DETECTION);
            }

            if (carWash->getDistance() <= MIN_DISTANCE) {
                state = CheckInOutTaskStates::OFFLINE;
                checkInTimer = millis();
            }
            break;
        case CheckInOutTaskStates::CHECKING_IN:
            Serial.println("CHECKING_IN");
            carWash->getLed2()->switchLight(false);
            if (millis() - checkInTimer >= T2) {
                carWash->setState(SystemState::VEICHLE_WAITING);
                state = GATE_CLOSING;
            }
            break;
        case CheckInOutTaskStates::GATE_CLOSING:
            Serial.println("GATE_CLOSING");
            carWash->getLed2()->switchLight(false);
            if (carWash->getServoMotor()->isClose()) {
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Ready to Wash");
                carWash->setState(SystemState::READY_TO_BE_WASHED);
                state = CheckInOutTaskStates::IN_WASH_WAITING;
            }
            break;
        case CheckInOutTaskStates::IN_WASH_WAITING:
            Serial.println("IN_WASH_WAITING");
            carWash->getLed2()->blink(500);
            if (carWash->getState() == SystemState::CHECK_OUT) {
                state = CheckInOutTaskStates::CHECKING_OUT;
                checkOutTimer = millis();
            }                
            break;
        case CheckInOutTaskStates::CHECKING_OUT:
            Serial.println("CHECKING_OUT");
            carWash->getLed2()->blink(100);
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
