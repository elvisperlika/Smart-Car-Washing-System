#include "AccessTask.h"
#include <Arduino.h>

#define MAXDIST 20
#define MINDIST 5

extern int carDistance;

AccessTask::AccessTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = CLOSE;
}

void AccessTask::tick() {
    switch (state) {
        case CLOSE:
            carWash->getServoMotor()->setPosition(0); 
            state = OPEN;
            break;

        case OPEN:
            carWash->getServoMotor()->setPosition(90);
            state = CLOSE;
            break;

        default:
            break;
    }
}