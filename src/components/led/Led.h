#ifndef __LED__
#define __LED__

#include "../Component.h"

class Led : public Component {
    public:
        Led(unsigned short pin);
        void switchLed(bool state);
        bool isOn();
};

#endif
