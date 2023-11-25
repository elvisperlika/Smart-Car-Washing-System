#include "ProximitySensor.h"
#include "../Component.h"

ProximitySensor::ProximitySensor() {}

ProximitySensor::ProximitySensor(Pin pins[], int numPins) : Component(pins, numPins) { }