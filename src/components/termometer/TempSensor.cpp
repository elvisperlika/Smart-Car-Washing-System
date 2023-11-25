#include "TempSensor.h"
#include "../Component.h"

class TempSensor: public Component {

public:
    TempSensor(int pin) {
        pins = new Pin[1];
        pins[0] = Pin(pin, INPUT_PIN);
        TempSensor(pins, 1);
    }

    float getTemperature();

private:
    TempSensor(Pin pins[], int numPins) : Component(pins, numPins) { }

};