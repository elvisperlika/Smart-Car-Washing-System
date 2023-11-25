#include "TempSensorTMP36.h"
#include "Arduino.h"

#define VOLT_FACTOR ((float)0.0048828145)

TempSensorLM35::TempSensorLM35(int p) : pin(p){
}

float TempSensorLM35::getTemperature(){
    int value = analogRead(pin);
    float voltage = value * VOLT_FACTOR;
    float valueInCelsius = (voltage - 0.5) * 100.0;
    return valueInCelsius;
}
