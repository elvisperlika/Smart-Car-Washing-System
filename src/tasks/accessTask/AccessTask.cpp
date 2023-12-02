#include "AccessTask.h"

AccessTask::AccessTask(int period, CarWash *carWash) : Task(period, carWash) {
    gateState = AccessTaskStates::CLOSE;
    angle = carWash->getServoMotor()->getDefaultCloseAngle();
    carWash->getServoMotor()->setPosition(angle);
}

void AccessTask::tick() {
    switch (gateState) {
        case AccessTaskStates::CLOSE:
            if (carWash->getState() == SystemState::CHECK_IN || carWash->getState() == SystemState::CHECK_OUT) {
                gateState = AccessTaskStates::OPENING;
            }
            break;
        case AccessTaskStates::OPENING:
            angle -= SERVO_DEGREE_CHANGE;
            carWash->getServoMotor()->setPosition(angle);

            if (carWash->getServoMotor()->isOpen())
            {
                gateState = AccessTaskStates::OPEN;
            }
            break;
        case AccessTaskStates::OPEN:
            if (carWash->getState() == SystemState::VEICHLE_WAITING || carWash->getState() == SystemState::DETECTION) {
                gateState = AccessTaskStates::CLOSING;
            }            
            break;
        case AccessTaskStates::CLOSING:
            angle += SERVO_DEGREE_CHANGE;
            carWash->getServoMotor()->setPosition(angle);
            if (carWash->getServoMotor()->isClose())
            {
                gateState = AccessTaskStates::CLOSE;
            }
            break;
      
    }

}

int AccessTask::getState() {
    return gateState;
}