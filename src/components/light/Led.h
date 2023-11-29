#ifndef __LED__
#define __LED__

#define FADE_STEP 5

#include "Light.h"

class Led : public Light {
    public:
        Led(unsigned short pin);
        void switchLight(bool state) override;
        bool isOn() override;
        void fading() override;
};

#endif
