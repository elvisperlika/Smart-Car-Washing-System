#include "Sonar.h"

Sonar::Sonar(unsigned short echoP, unsigned short trigP, long maxTime) : DistanceSensor(new Pin[2]{Pin(trigP, OUTPUT), Pin(echoP, INPUT)}, 2) {
    
    // AGGIUNGERE IL MAX DIST IN SENSOR
    
    timeOut = maxTime;
}

Sonar::Sonar(Pin pins[], int numPins) : DistanceSensor(pins, numPins) { }

float Sonar::getDistance() {
    digitalWrite(pins[0].getPinNumber(), LOW);
    delayMicroseconds(2);
    digitalWrite(pins[0].getPinNumber(), HIGH);
    delayMicroseconds(10);
    digitalWrite(pins[0].getPinNumber(), LOW);
    long duration = pulseIn(pins[1].getPinNumber(), HIGH);
    long distance= duration*0.034/2;
    return distance;
}
