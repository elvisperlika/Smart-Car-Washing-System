#ifndef __CARWASH__
#define __CARWASH__

#include "../Config.h"
#include "../components/button/Button.h"
#include "../components/distantiometer/Sonar.h"
#include "components/servo/servo_motor_impl.h"
#include "../components/lcd/Lcd.h"
#include "../components/lcd/LcdI2C.h"
#include "../components/light/Led.h"
#include "../components/presentiometer/HCSR501.h"
#include "../components/termometer/TempSensorTMP36.h"


enum SystemState {
    SYSTEM_SLEEP,
    DETECTION,
    WELCOME,
    VEICHLE_WAITING,
    READY_TO_BE_WASHED,
    READY_TO_BE_WASHED_BUTTON_PRESSED,
    CAR_WASHING,
    VEICHLE_LEAVING
};

class CarWash {
    private:
        Led *led1;
        Led *led2;
        Led *led3;
        TempSensor *temperatureSensor;
        ProximitySensor *proximitySensor;
        DistanceSensor *distanceSensor;
        ServoMotor *servoMotor;
        Lcd *lcd;
        Button *button;

        SystemState systemState;
        bool suspended;
        const char* enumStrings[9] = {
            "SLEEP",
            "DETECTION",
            "WELCOME",
            "VEICHLE_WAITING",
            "READY_TO_BE_WASHED",
            "READY_TO_BE_WASHED_BUTTON_PRESSED",
            "CAR_WASHING",
            "VEICHLE_LEAVING"
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
        ServoMotor *getServoMotor();
        Lcd *getLcd();
        SystemState getState();
        void setState(SystemState newState);
        bool isSuspended();
        void setSuspended(bool newState);
        const char* enumToString(enum SystemState value);
        void errorTempratureFixed();

};

#endif
