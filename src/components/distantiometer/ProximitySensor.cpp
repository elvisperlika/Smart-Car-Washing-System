#include "ProximitySensor.h"
#include "../Component.h"

class ProximitySensor : public Component {

public:
    ProximitySensor(int pin) : Component({new Pin(pin, INPUT_PIN)}, 1) { }
    virtual float getDistance() = 0;
};