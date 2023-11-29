#include "TempSensorTMP36.h"

#define VOLT_FACTOR ((float)5 / 1024)

TempSensorTMP36::TempSensorTMP36(unsigned short pin) : TempSensor(pin) {
}

float TempSensorTMP36::getTemperature(){
    int value = analogRead(pins[0].getPinNumber());
    float voltage = value * VOLT_FACTOR;
    float valueInCelsius = (voltage - 0.5) * 100.0;
    return valueInCelsius;
}
