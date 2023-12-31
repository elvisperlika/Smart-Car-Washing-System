#include "CarWash.h"

CarWash::CarWash() {
    led1 = new Led(LED1_PIN);
    led2 = new Led(LED2_PIN);
    led3 = new Led(LED3_PIN);
    temperatureSensor = new TempSensorTMP36(TMP36_PIN);
    proximitySensor = new HCSR501(MOTION_SENSOR_PIN);
    distanceSensor = new Sonar(DISTANCE_SENSOR_ECHO_PIN, DISTANCE_SENSOR_TRIG_PIN, MAX_DISTANCE_TIME);
    servoMotor = new ServoMImpl(GATE_PIN);
    lcd = new LcdI2C();
    button = new ButtonImpl(BUTTON_PIN);
    
    systemState = SystemState::DETECTION;
    suspended = false;
    globalWashingTime = 0;
    carWashed = 0;
}

Led *CarWash::getLed1() {
    return led1;
}

Led *CarWash::getLed2() {
    return led2;
}

Led *CarWash::getLed3() {
    return led3;
}

bool CarWash::getPresence() {
    return proximitySensor->checkPresence();
}

float CarWash::getTemperature() {
    return temperatureSensor->getTemperature();
}

int CarWash::getDistance() {
    return distanceSensor->getDistance();
}

bool CarWash::isButtonPressed() {
    return button->isClicked();
}

ServoM *CarWash::getServoMotor() {
    return servoMotor;
}

Lcd *CarWash::getLcd() {
    return lcd;
}

SystemState CarWash::getState() {
    return systemState;
}

void CarWash::setState(SystemState newState) {
    systemState = newState;
}

bool CarWash::isSuspended() {
    return suspended;
}

void CarWash::setSuspended(bool newState) {
    suspended = newState;
}

// Function to convert enum to string
const char* CarWash::enumToString(enum SystemState value) {
    return enumStrings[value];
}

void CarWash::errorTempratureFixed() {
    if (systemState == SystemState::WASHING_ERROR) {
        systemState = SystemState::WASHING;
    }
}

unsigned long CarWash::getGlobalWashingTime() {
    return globalWashingTime;
}

void CarWash::setGlobalWashingTime(unsigned long newTime) {
    globalWashingTime = newTime;
}

void CarWash::incCarWashed() {
    carWashed++;
}

int CarWash::getCarWashed() {
    return carWashed;
}