#include "Component.h"

Component::Component(Pin* pins, int numPins) {
    this->pins = new Pin[numPins];
    for (int i = 0; i < numPins; ++i) {
        this->pins[i] = pins[i];
    }
}

Component::~Component() {
    delete[] pins;
}