#include "AccessTask.h"
#include <Arduino.h>

#define MAXDIST 20
#define MINDIST 5

extern bool carDetected;
extern bool carWash;
extern int carDistance;

AccessTask::AccessTask(Gate* gate) {
    this->gate = gate;
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
            break;
        case WAITING_TO_OPEN:
            if (millis() - tOpen >= TOPEN) {
                state = IN_OPENING;
            }
            break;
        case IN_OPENING:
            gate->incOneGrade();
            if (gate->getAngle() == 90) {   
                state = OPEN;
            }
            break;
        case OPEN:
            if (carDistance >= MAXDIST || carDistance <= MINDIST) {
                state = WAITING_TO_CLOSE;
                tClose = millis();
            }
            break;
        case WAITING_TO_CLOSE:
            if (millis() - tClose >= TOPEN) {
                state = IN_CLOSING;
            }
            break;
        case IN_CLOSING:
            gate->decOneGrade();
            if (gate->getAngle() == 0) {
                state = CLOSE;
            }
            break;
    }
}