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
            break;

        case OPEN:
            carWash->getServoMotor()->setPosition(90);
            break;

        default:
            break;
    }
}