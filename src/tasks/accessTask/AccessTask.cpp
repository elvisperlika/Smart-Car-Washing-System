#include "AccessTask.h"

AccessTask::AccessTask(int period, CarWash *carWash) : Task(period, carWash) {
    gateState = GATE_STATE::CLOSE;
    angle = CLOSE_GATE_DEGREE;
    carWash->getServoMotor()->setPosition(angle);
}

void AccessTask::tick() {
    switch (gateState) {
        case GATE_STATE::CLOSE:
            if (carWash->getState() == SystemState::CHECK_IN || carWash->getState() == SystemState::CHECK_OUT) {
                gateState = GATE_STATE::OPENING;
            }
            break;
        case GATE_STATE::OPENING:
            angle -= 5;
            carWash->getServoMotor()->setPosition(angle);
            if (angle <= 70)
            {
                gateState = GATE_STATE::OPEN;
            }
            break;
        case GATE_STATE::OPEN:
            if (carWash->getState() == SystemState::VEICHLE_WAITING || carWash->getState() == SystemState::DETECTION) {
                gateState = GATE_STATE::CLOSING;
            }
            
            break;
        case GATE_STATE::CLOSING:
            angle += 5;
            carWash->getServoMotor()->setPosition(angle);
            if (angle >= 180)
            {
                gateState = GATE_STATE::CLOSE;
            }
            break;
      
    }

}