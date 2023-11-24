#ifndef __TEMP_SENSOR__
#define __TEMP_SENSOR__

#include "../Component.h"

class TempSensor: public Component {

public:
    TempSensor(int pin);
    virtual float getTemperature() = 0;
};

#endif

