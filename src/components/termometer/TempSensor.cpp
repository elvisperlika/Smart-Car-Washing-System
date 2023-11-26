#include "TempSensor.h"

class TempSensor: public Component {

public:
    TempSensor(unsigned short pin) : Component(new Pin(pin, INPUT), 1) { }

    virtual float getTemperature();
};