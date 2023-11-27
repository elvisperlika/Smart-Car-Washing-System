#ifndef __CARWASH__
#define __CARWASH__

#include "../Config.h"
#include "../components/button/Button.h"
#include "../components/distantiometer/Sonar.h"
#include "../components/gate/Gate.h"
#include "../components/lcd/LcdI2C.h"
#include "../components/light/Led.h"
#include "../components/presentiometer/HCSR501.h"
#include "../components/termometer/TempSensorTMP36.h"

class CarWash {
    Led *led1;
    Led *led2;
    Led *led3;
    TempSensor *temperatureSensor;
    ProximitySensor *proximitySensor;
    DistanceSensor *distanceSensor;
    Gate *gate;
    Lcd *lcd;

    public:
        CarWash();

};

#endif
