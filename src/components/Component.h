#ifndef COMPONENT_H
#define COMPONENT_H

#include "Pin.h"
#include <Arduino.h>

class Component {
public:
    Component(Pin pins[], int numPins);
    Component();

protected:
    Pin *pins;
};

#endif
