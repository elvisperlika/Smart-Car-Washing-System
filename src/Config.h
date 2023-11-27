#ifndef __CONFIG_H__
#define __CONFIG_H__

// Digital Pins
#define LED1_PIN 3
#define LED2_PIN 4
#define LED3_PIN 5
#define MOTION_SENSOR_PIN 6
#define GATE_PIN 7
#define BUTTON_PIN 8
#define TMP36_PIN 9
#define DISTANCE_SENSOR_TRIG_PIN 10
#define DISTANCE_SENSOR_ECHO_PIN 11

// Analog Pins
#define LCD_SDA_PIN A4
#define LCD_SCL_PIN A5

// Other Constants
#define BAUD_RATE 9600
#define MAX_DISTANCE_TIME 1l // milliseconds time limit to wait for a distance sensor range

#endif