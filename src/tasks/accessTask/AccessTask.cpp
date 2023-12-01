#include "AccessTask.h"
#include <Arduino.h>

#define MAXDIST 20
#define MINDIST 5

extern int carDistance;

AccessTask::AccessTask(int period, CarWash *carWash) : Task(period, carWash) {
    state = CLOSE;
   
}

void AccessTask::tick() {
    Serial.println("gate Tick!");
    Serial.println(carWash->getServoMotor()->getAngle());
    switch (state) {
        case CLOSE:
            carWash->getServoMotor()->setPosition(180);
            state = OPEN;
            break;

        case OPEN:
            carWash->getServoMotor()->setPosition(70);
            state = CLOSE;
            break;

        default:
            break;
    }
}