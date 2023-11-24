#include "TempSensor.h"
#include "../Component.h"

class TempSensor: public Component {

public:
    TempSensor(int pin) : Component({new Pin(pin, INPUT_PIN)}, 1) {}
    virtual float getTemperature() = 0;

};


