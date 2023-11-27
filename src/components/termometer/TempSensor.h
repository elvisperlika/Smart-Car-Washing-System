#ifndef __TEMP_SENSOR__
#define __TEMP_SENSOR__

#include "../Component.h"

class TempSensor: public Component {
    public:
        TempSensor(unsigned short pin);
        virtual float
         getTemperature() = 0;
};

#endif

