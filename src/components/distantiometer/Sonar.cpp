#include "Sonar.h"

#include "Arduino.h"

Sonar::Sonar(int echoP, int trigP, long maxTime) : echoPin(echoP), trigPin(trigP), timeOut(maxTime) {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    temperature = 20; // default value

    Pin pins[2] = { Pin(trigPin, OUTPUT_PIN), Pin(echoPin, INPUT_PIN) };
    Sonar(pins, 2);
}

Sonar::Sonar(Pin pins[], int numPins) : Sonar(pins, numPins) { }

void Sonar::setTemperature(float temp){
    temperature = temp;
}

float Sonar::getSoundSpeed() {
    return 331.5 + 0.6*temperature;
}

float Sonar::getDistance(){
    digitalWrite(trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);

    float tUS = pulseIn(echoPin, HIGH, timeOut);
    if (tUS == 0) {
        return NO_OBJ_DETECTED;
    } else {
        float t = tUS / 1000.0 / 1000.0 / 2;
        float d = t*getSoundSpeed();
        return d;
    }
}
