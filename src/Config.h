#ifndef __CONFIG_H__
#define __CONFIG_H__

// Digital Pins
#define LED1_PIN 3
#define LED2_PIN 4
#define LED3_PIN 5
#define MOTION_SENSOR_PIN 6
#define GATE_PIN 7
#define BUTTON_PIN 8
#define DISTANCE_SENSOR_TRIG_PIN 10
#define DISTANCE_SENSOR_ECHO_PIN 11

// Analog Pins
#define TMP36_PIN A0
#define LCD_SDA_PIN A4
#define LCD_SCL_PIN A5

// Timers
#define T0 3000 //Sleep mode time
#define T1 3000 //Car on gate time
#define T2 3000 //Car inside time
#define T3 3000 //Washing time
#define T4 3000 //Temperature warning max time
#define T5 3000 //Car left time

// Other Constants
#define BAUD_RATE 9600
#define MAX_DISTANCE_TIME 1000000l // microsecond time limit to wait for a distance sensor range
#define MAX_DISTANCE 10
#define MAX_TEMPERATURE 40

#endif