#include "CarWashTest.h"
#include "Config.h"
#include <assert.h>

CarWashTest::CarWashTest(CarWash* carWash) {
    this->carWash = carWash;
}

const char* CarWashTest::getState() {
    return carWash->enumToString(carWash->getState());
}

/**
 * Test if leds turn on and off in order.
*/
void CarWashTest::testLedsOnOff() {
    carWash->getLed1()->switchLight(true);
    Serial.print("Led1 on: ");
    Serial.println(digitalRead(LED1_PIN) == HIGH);
    delay(500);
    carWash->getLed1()->switchLight(false);
    Serial.print("Led1 off: ");
    Serial.println(digitalRead(LED1_PIN) == LOW);
    delay(500);
    carWash->getLed2()->switchLight(true);
    Serial.print("Led2 on: ");
    Serial.println(digitalRead(LED2_PIN) == HIGH);
    delay(500);
    carWash->getLed2()->switchLight(false);
    Serial.print("Led2 off: ");
    Serial.println(digitalRead(LED2_PIN) == LOW);
    delay(500);
    carWash->getLed3()->switchLight(true);
    Serial.print("Led3 on: ");
    Serial.println(digitalRead(LED3_PIN) == HIGH);
    delay(500);
    carWash->getLed3()->switchLight(false);
    Serial.print("Led3 off: ");
    Serial.println(digitalRead(LED3_PIN) == LOW);
    delay(500);
}

/**
 * Test if leds blink in different frequencies.
 * Test this fun in superloop.
*/
void CarWashTest::testLedsBlink() {
    carWash->getLed1()->blink(100);
    Serial.println("Led1 blink");
    carWash->getLed2()->blink(250);
    Serial.println("Led2 blink");
    carWash->getLed3()->blink(500);
    Serial.println("Led3 blink");
}

/**
 * Test if pir detects presence.
 * Test this fun in superloop.
*/
void CarWashTest::testPresentiometer() {
    Serial.print("Presentiometer: ");
    Serial.println(carWash->getPresence());
    Serial.print("Pin value: ");
    Serial.println(digitalRead(MOTION_SENSOR_PIN));
}

/** 
 * Test if button is pressed.
 * Test this fun in superloop.
*/
void CarWashTest::testButton() {
    Serial.print("Button: ");
    Serial.println(carWash->isButtonPressed());
    Serial.print("Pin value: ");
    Serial.println(digitalRead(BUTTON_PIN));
}

void CarWashTest::testLcdWrite() {
    carWash->getLcd()->displayText("Hello world");
}

void CarWashTest::testLcdClear() {
    carWash->getLcd()->clearScreen();
}

void CarWashTest::testServoMotor() {
    carWash->getServoMotor()->setPosition(carWash->getServoMotor()->getDefaultCloseAngle());
    Serial.println("Servo motor close");
    delay(1000);
    carWash->getServoMotor()->setPosition(carWash->getServoMotor()->getDefaultOpenAngle());
    Serial.println("Servo motor open");
    delay(1000);
}

/**
 * Test if temperature sensor works.
 * It's better to run this fun in superloop.
*/
void CarWashTest::testTemperatureSensor() {
    Serial.print("Temperature: ");
    Serial.println(carWash->getTemperature());
}

void CarWashTest::testDistanceSensor() {
    Serial.print("Distance: ");
    Serial.println(carWash->getDistance());
}
