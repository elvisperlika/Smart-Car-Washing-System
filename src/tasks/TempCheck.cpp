#include "TempCheck.h"

extern bool isWashing;
extern float temp;
extern bool alert;

TempCheck::TempCheck(int period, CarWash *carWash) : Task(period, carWash) { 
    state = T_NORM;
    alert = false;
}

void TempCheck::tick() {
    temp = tempSensor->getTemperature();
    
    if(isWashing) {
        switch (state) {
            case T_NORM:
                if (temp > WARNING_TEMP) {
                    state = HIGH_TEMP;
                    tHighTemp = millis();
                }
                break;
            case HIGH_TEMP:
                if(temp <= WARNING_TEMP){
                    state = T_NORM;
                }
                if (millis() - tHighTemp >= T_HIGH_TEMP) {
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