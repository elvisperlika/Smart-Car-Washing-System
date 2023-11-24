#ifndef __PROXIMITYSENSOR__
#define __PROXIMITYSENSOR__

class ProximitySensor : public Component {

public:
    ProximitySensor(int pin);
    virtual float getDistance() = 0;
};

#endif
