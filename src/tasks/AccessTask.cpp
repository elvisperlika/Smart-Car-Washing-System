#include "tasks/AccessTask.h"
#include <Arduino.h>

#define MAXDIST 20
#define MINDIST 5

extern int carDistance;

AccessTask::AccessTask(int gatePin) {
    this->gate = new Gate(gatePin);
}

void AccessTask::init(int period) {
    Task::init(period);
    state = CLOSE;
}

void AccessTask::tick() {
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
            this->gate->incOneGrade();
            if (gate->getAngle() == 90) {   
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
            this->gate->decOneGrade();
            if (gate->getAngle() == 0) {
                state = CLOSE;
            }
            Serial.println("IN_CLOSING");
            break;
        
    }
}