#include "CarWash.h"

CarWash::CarWash() {
    led1 = new Led(LED1_PIN);
    led2 = new Led(LED2_PIN);
    led3 = new Led(LED3_PIN);
    temperatureSensor = new TempSensorTMP36(TMP36_PIN);
    proximitySensor = new HCSR501(MOTION_SENSOR_PIN);
    distanceSensor = new Sonar(DISTANCE_SENSOR_ECHO_PIN, DISTANCE_SENSOR_TRIG_PIN, MAX_DISTANCE_TIME);
    gate = new Gate(GATE_PIN);
    lcd = new LcdI2C();
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
    proximitySensor->checkPresence();
}

float CarWash::getTemperature() {
    temperatureSensor->getTemperature();
}

int CarWash::getDistance() {
    distanceSensor->getDistance();
}

Gate *CarWash::getGate() {
    return gate;
}

Lcd *CarWash::getLcd() {
    return lcd;
}