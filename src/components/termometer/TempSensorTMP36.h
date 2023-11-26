#ifndef __TEMP_SENSOR_LM35__
#define __TEMP_SENSOR_LM35__

#include "TempSensor.h"

class TempSensorTMP36: public TempSensor {
    public:
        TempSensorTMP36(unsigned short pin);
        float getTemperature();
};


#endif
