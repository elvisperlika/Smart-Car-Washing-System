#ifndef __LED__
#define __LED__

#include "Light.h"

class Led : public Light {
    public:
        Led(unsigned short pin);        
};

#endif
