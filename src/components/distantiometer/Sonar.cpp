#include "Sonar.h"

Sonar::Sonar(unsigned short echoP, unsigned short trigP, long maxTime) : echoPin(echoP), trigPin(trigP), timeOut(maxTime) {
    temperature = 20; // default value

    Pin pins[2] = { Pin(trigPin, OUTPUT), Pin(echoPin, INPUT) };
    Sonar(pins, 2);
}

Sonar::Sonar(Pin pins[], int numPins) : DistanceSensor(pins, numPins) { }

void Sonar::setTemperature(float temp){
    temperature = temp;
}

float Sonar::getSoundSpeed() {
    return 331.5 + 0.6*temperature;
}

float Sonar::getDistance() {
    digitalWrite(trigPin,LOW);
    delayMicroseconds(3);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(5);
    digitalWrite(trigPin,LOW);

    unsigned long tUS = pulseIn(echoPin, HIGH, timeOut);
    if (tUS == 0) {
        return NO_OBJ_DETECTED;
    } else {
        float t = tUS / 1000.0 / 1000.0 / 2;
        float d = t*getSoundSpeed();
        return d;
    }
}
