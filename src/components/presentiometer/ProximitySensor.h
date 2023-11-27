#ifndef __PROXIMITY_SENSOR_H__
#define __PROXIMITY_SENSOR_H__

#include "../Component.h"

class ProximitySensor : public Component {
    public:
        ProximitySensor(unsigned short pin);
        virtual bool checkPresence() = 0;
};

#endif
