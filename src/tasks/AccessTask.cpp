#include "tasks/AccessTask.h"
#include <Arduino.h>

#define MAXDIST 20
#define MINDIST 5

extern int carDistance;

AccessTask::AccessTask(int gatePin) {
    this->servo = new ServoMotorImpl(gatePin);
    this->servo->on();
    this->servo->setPosition(-40);
}

void AccessTask::init(int period) {
    Task::init(period);
    state = CLOSE;
}

void AccessTask::tick() {
    Serial.println(this->servo->getAngle());
    switch (state) {
        case CLOSE:
            if (carDetected || !carWash) {
                state = WAITING_TO_OPEN;
                tOpen = millis();
            }
            Serial.println("CLOSE");
            break;
        case WAITING_TO_OPEN:
            if (millis() - tOpen >= this->TOPEN) {
                state = IN_OPENING;
            }
            Serial.println("WAITING_TO_OPEN");
            break;
        case IN_OPENING:
            this->servo->incOneGrade();
            //this->servo->setPosition(this->servo->getAngle()+5);
            if (this->servo->getAngle() >= 70) {   
                state = OPEN;
            }
            Serial.println("IN_OPENING");
            break;
        case OPEN:
            if (carDistance >= MAXDIST || carDistance <= MINDIST) {
                state = WAITING_TO_CLOSE;
                tClose = millis();
            }
            Serial.println("OPEN");
            break;
        case WAITING_TO_CLOSE:
            if (millis() - tClose >= TOPEN) {
                state = IN_CLOSING;
            }
            Serial.println("WAITING_TO_CLOSE");
            break;
        case IN_CLOSING:
            this->servo->decOneGrade();
            if (this->servo->getAngle() <= -40) {
                state = CLOSE;
            }
            Serial.println("IN_CLOSING");
            break;
    }
}