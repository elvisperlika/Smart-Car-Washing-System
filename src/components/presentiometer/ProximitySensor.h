#ifndef PROXIMITY_SENSOR_H
#define PROXIMITY_SENSOR_H

#include "../Component.h"

class ProximitySensor : public Component{
    public:
        ProximitySensor(int pin);
        bool checkPresence();
};

#endif
