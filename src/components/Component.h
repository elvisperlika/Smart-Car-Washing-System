#ifndef COMPONENT_H
#define COMPONENT_H

#include "Pin.h"

class Component {
public:
    Component(Pin* pins, int numPins);

private:
    Pin* pins;
};

#endif
