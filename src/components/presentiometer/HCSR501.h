#ifndef __HCSR501__
#define __HCSR501__

#include "ProximitySensor.h"

class HCSR501 : public ProximitySensor {
    public:
        HCSR501(unsigned short pin);
        bool checkPresence() override;
};

#endif
