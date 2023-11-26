#ifndef __TEMP_SENSOR_LM35__
#define __TEMP_SENSOR_LM35__

#include "TempSensor.h"

class TempSensorLM36: public TempSensor {
    public:
        TempSensorLM36(unsigned short pin);
        virtual float getTemperature() = 0;
};


#endif
