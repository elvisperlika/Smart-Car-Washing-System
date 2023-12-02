#ifndef __CARWASH__
#define __CARWASH__

#include "Config.h"
#include "components/button/Button.h"
#include "components/distantiometer/Sonar.h"
#include "components/servo/ServoMImpl.h"
#include "components/lcd/Lcd.h"
#include "components/lcd/LcdI2C.h"
#include "components/light/Led.h"
#include "components/presentiometer/HCSR501.h"
#include "components/termometer/TempSensorTMP36.h"
#include "components/button/ButtonImpl.h"


enum SystemState {
    DETECTION,
    WELCOME,
    CHECK_IN,
    VEICHLE_WAITING,
    READY_TO_BE_WASHED,
    READY_TO_BE_WASHED_BUTTON_PRESSED,
    WASHING,
    WASHING_ERROR,
    CHECK_OUT
};

class CarWash {
    private:
        Led *led1;
        Led *led2;
        Led *led3;
        TempSensor *temperatureSensor;
        ProximitySensor *proximitySensor;
        DistanceSensor *distanceSensor;
        ServoM *servoMotor;
        Lcd *lcd;
        Button *button;

        SystemState systemState;
        bool suspended;
        const char* enumStrings[9] = {
            "DETECTION",
            "WELCOME",
            "CHECK_IN",
            "VEICHLE_WAITING",
            "READY_TO_BE_WASHED",
            "READY_TO_BE_WASHED_BUTTON_PRESSED",
            "WASHING",
            "WASHING_ERROR",
            "CHECK_OUT"
        };
        

    public:
        CarWash();
        Led *getLed1();
        Led *getLed2();
        Led *getLed3();
        bool getPresence();
        float getTemperature();
        int getDistance();
        bool isButtonPressed();
        ServoM *getServoMotor();
        Lcd *getLcd();
        SystemState getState();
        void setState(SystemState newState);
        bool isSuspended();
        void setSuspended(bool newState);
        const char* enumToString(enum SystemState value);
        void errorTempratureFixed();

};

#endif
