#include "CarWash.h"

CarWash::CarWash() {
    Light *led1 = new Led(LED1_PIN);
    Light *led2 = new Led(LED2_PIN);
    Light *led3 = new Led(LED3_PIN);
    TempSensor *temperatureSensor = new TempSensorTMP36(TMP36_PIN);
    ProximitySensor *proximitySensor = new HCSR501(MOTION_SENSOR_PIN);
    DistanceSensor *distanceSensor = new Sonar(DISTANCE_SENSOR_ECHO_PIN, DISTANCE_SENSOR_TRIG_PIN, MAX_DISTANCE_TIME);
    Gate *gate = new Gate(GATE_PIN);
    Lcd *lcd = new LcdI2C();
}