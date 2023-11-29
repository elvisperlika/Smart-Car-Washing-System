#include "TempCheckTask.h"

TempCheckTask::TempCheckTask(int period, CarWash *carWash) : Task(period, carWash) { 
    state = T_NORM;
}

void TempCheckTask::tick() {
    float temp = carWash->getTemperature();
    
    if(carWash->getState() == SystemState::CAR_WASHING) {
        switch (state) {
            case T_NORM:
                if (temp > WARNING_TEMP) {
                    tHighTemp = millis();
                }
                break;
            case HIGH_TEMP:
                if(temp <= WARNING_TEMP){
                    state = T_NORM;
                }
                if (millis() - tHighTemp >= MAX_TEMPERATURE) {
                    state = ALERT;
                }
                break;
            case ALERT:
                if (!alert) {
                    state = T_NORM;
                }
                break;
        }
    } else {
        state = T_NORM;
        alert = false;
    }
}