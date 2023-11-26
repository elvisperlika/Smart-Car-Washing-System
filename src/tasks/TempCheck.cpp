#include "TempCheck.h"
#include "../components/TempSensorImpl.h"
#include <Arduino.h>

#define WARNING_TEMP 60

extern bool isWashing;
extern float temp;
extern bool alert;

TempCheck::TempCheck(int pin) {
    tempSensor = new TempSensorLM35(pin);
}

void TempCheck::init(int period) {
    Task::init(period);
    state = T_NORM;
    alert = false;
}

void TempCheck::tick() {


    switch (state) {
        temp = tempSensor->getTemperature();
        if(isWashing){
            case T_NORM:
                if (temp > MAX_TEMP) {
                    state = HIGH_TEMP;
                    tHighTemp = millis();
                }
            break;
            case HIGH_TEMP:
                if(temp <= MAX_TEMP){
                    state = T_NORM
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
        else{
            state = T_NORM;
            alert = false;
        }

    }
}