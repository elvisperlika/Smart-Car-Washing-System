#include "TempCheckTask.h"

TempCheckTask::TempCheckTask(int period, CarWash *carWash) : Task(period, carWash) { 
    state = T_NORM;
}

void TempCheckTask::tick() {
    float temp = carWash->getTemperature();
    
    if(carWash->getState() == SystemState::CAR_WASHING) {
        switch (state) {
            case T_NORM:
                if (temp > MAX_TEMPERATURE) {
                    tHighTemp = millis();
                    state = HIGH_TEMP;
                }
                break;
            case HIGH_TEMP:
                if(temp <= MAX_TEMPERATURE){
                    state = T_NORM;
                }
                if (millis() - tHighTemp >= MAX_TEMPERATURE_TIME) {
                    state = ALERT;
                    carWash->setState(SystemState::CAR_WASHING_ERROR);
                }
                break;
            case ALERT:
                if (!carWash->isSuspended()) {
                    state = T_NORM;
                }
                break;
        }
    }
}