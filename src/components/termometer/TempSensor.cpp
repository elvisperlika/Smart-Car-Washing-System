#include "TempSensor.h"
#include "../Component.h"

class TempSensor: public Component {

public:
    TempSensor(unsigned short pin) : Component(new Pin(pin, INPUT_PIN), 1) { }

    virtual float getTemperature();
};