#include "AccessTask.h"

AccessTask::AccessTask(int period, CarWash *carWash) : Task(period, carWash) {
    gateState = AccessTaskStates::CLOSE;
}

void AccessTask::tick() {
    switch (gateState) {
        case AccessTaskStates::CLOSE:
            if (carWash->getState() == SystemState::CHECK_IN || carWash->getState() == SystemState::CHECK_OUT) {
                gateState = AccessTaskStates::OPENING;
            }
            break;
        case AccessTaskStates::OPENING:
            carWash->getServoMotor()->setPosition(carWash->getServoMotor()->getPosition() - SERVO_DEGREE_CHANGE);

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
<<<<<<< HEAD
            carWash->getServoMotor()->setPosition(carWash->getServoMotor()->getPosition() + SERVO_DEGREE_CHANGE);
=======
            angle += SERVO_DEGREE_CHANGE;
            carWash->getServoMotor()->setPosition(angle);
>>>>>>> 60a6591a444ea8a73b354d2874f654f6b507e831
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