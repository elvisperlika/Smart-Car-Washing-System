#include "TempCheckTask.h"

TempCheckTask::TempCheckTask(int period, CarWash *carWash) : Task(period, carWash) { 
    state = OFFLINE;
}

void TempCheckTask::tick() {
    switch (state) {
        case OFFLINE:
            if (carWash->getState() == SystemState::WASHING) {
                state = NORMAL_TEMP;
                tHighTemp = millis();
            }
            break;
        case NORMAL_TEMP:
            if (carWash->getState() != SystemState::WASHING) {
                state = OFFLINE;
                tHighTemp = millis();
            }

            if (carWash->getTemperature() >= MAX_TEMPERATURE) {
                tHighTemp = millis();
                state = HIGH_TEMP;
            }
            break;
        case HIGH_TEMP:
            Serial.print("TEMPTEMP: ");
            Serial.println(millis() - tHighTemp);
            if (carWash->getState() != SystemState::WASHING) {
                state = OFFLINE;
            }

            if (carWash->getTemperature() < MAX_TEMPERATURE) {
                state = NORMAL_TEMP;
            }

            if (millis() - tHighTemp >= T4) {
                state = ALERT;
                carWash->setState(SystemState::WASHING_ERROR);
                Serial.println("LLLLLLLLLLLLLLLLLLLLLLLLLL");
            }
            break;
        case ALERT:
            if (carWash->getState() == SystemState::WASHING) {
                state = NORMAL_TEMP;
            }
            break;
    }
}