#include "TempCheckTask.h"

TempCheckTask::TempCheckTask(int period, CarWash *carWash) : Task(period, carWash) { 
    state = OFFLINE;
}

void TempCheckTask::tick() {
    switch (state) {
        case OFFLINE:
            if (carWash->getState() == SystemState::WASHING) {
                state = NORMAL_TEMP;
            }
            break;
        case NORMAL_TEMP:
            if (carWash->getTemperature() >= MAX_TEMPERATURE) {
                tHighTemp = millis();
                state = HIGH_TEMP;
            }
            break;
        case HIGH_TEMP:
            if (carWash->getTemperature() < MAX_TEMPERATURE) {
                state = NORMAL_TEMP;
            }

            if (millis() - tHighTemp >= T4) {
                state = ALERT;
                carWash->setState(SystemState::WASHING_ERROR);
            }
            break;
        case ALERT:
            if (carWash->getState() == SystemState::WASHING) {
                state = NORMAL_TEMP;
                carWash->setState(SystemState::WASHING);
            }
            break;
    }
}

int TempCheckTask::getState() {
    return state;
}