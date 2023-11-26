#ifndef __DISTANCE_SENSOR__
#define __DISTANCE_SENSOR__

class DistanceSensor : public Component {
public:
    DistanceSensor();

    DistanceSensor(Pin pins[], int numPins);

    virtual float getDistance() = 0;
};

#endif
