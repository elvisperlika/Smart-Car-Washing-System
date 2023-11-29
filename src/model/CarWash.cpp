#include "CarWash.h"

CarWash::CarWash() {
    led1 = new Led(LED1_PIN);
    led2 = new Led(LED2_PIN);
    led3 = new Led(LED3_PIN);
    temperatureSensor = new TempSensorTMP36(TMP36_PIN);
    proximitySensor = new HCSR501(MOTION_SENSOR_PIN);
    distanceSensor = new Sonar(DISTANCE_SENSOR_ECHO_PIN, DISTANCE_SENSOR_TRIG_PIN, MAX_DISTANCE_TIME);
    servoMotor = new ServoMotorImpl(GATE_PIN);
    lcd = new LcdI2C();
    
    systemState = SystemState::SLEEP;
    suspended = false;
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

ServoMotor *CarWash::getServoMotor() {
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
char* CarWash::enumToString(enum SystemState value) {
    return enumStrings[value];
}