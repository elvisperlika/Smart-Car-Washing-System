#include "AccessTask.h"
#include <Arduino.h>

#define MAXDIST 20
#define MINDIST 5

int angle;

AccessTask::AccessTask(int period, CarWash *carWash) : Task(period, carWash) {
    gateState = GATE_STATE::CLOSE;
    angle = 180;
}

void AccessTask::tick() {
    Serial.println("gate Tick!");
    Serial.println(angle);
    Serial.println(gateState);
    switch (gateState) {
        case GATE_STATE::CLOSE:
            gateState = GATE_STATE::IN_OPENING;
            break;
        case GATE_STATE::WAITING_TO_OPEN:
            break;
        case GATE_STATE::IN_OPENING:
            angle -= 10;
            this->carWash->getServoMotor()->setPosition(angle);
            if (angle <= 70)
            {
               // gateState = GATE_STATE::OPEN;
            }
        case GATE_STATE::OPEN:
            gateState = GATE_STATE::IN_CLOSING;
            break;
        case GATE_STATE::IN_CLOSING:
            angle += 10;
            this->carWash->getServoMotor()->setPosition(angle);
            if (angle >= 180)
            {
                gateState = GATE_STATE::CLOSE;
            }

            
    }

}