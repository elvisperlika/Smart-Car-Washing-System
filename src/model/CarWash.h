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


enum SystemState {
    SLEEP,
    WELCOME,
    VEICHLE_APPROCHING,
    VEICHLE_WAITING,
    READY_TO_BE_WASHED,
    READY_TO_BE_WASHED_BUTTON_PRESSED,
    WASHING,
    VEICHLE_LEAVING
}

class CarWash {
    private:
        Led *led1;
        Led *led2;
        Led *led3;
        TempSensor *temperatureSensor;
        ProximitySensor *proximitySensor;
        DistanceSensor *distanceSensor;
        Gate *gate;
        Lcd *lcd;

        SystemState systemState;
        bool suspended;
        

    public:
        CarWash();
        Led *getLed1();
        Led *getLed2();
        Led *getLed3();
        bool getPresence();
        float getTemperature();
        int getDistance();
        Gate *getGate();
        Lcd *getLcd();
        SystemState getState();
        void setState(SystemState newState);
        bool isSuspended();
        void setSuspended(bool newState);

};

#endif
