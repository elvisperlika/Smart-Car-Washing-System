#ifndef __PROXIMITYSENSOR__
#define __PROXIMITYSENSOR__

class ProximitySensor : public Component {

public:
    ProximitySensor();
    ProximitySensor(Pin pins[], int numPins);
    virtual float getDistance() = 0;

};

#endif
