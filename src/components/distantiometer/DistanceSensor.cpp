#include "DistanceSensor.h"
#include "../Component.h"

DistanceSensor::DistanceSensor() {}

DistanceSensor::DistanceSensor(Pin pins[], int numPins) : Component(pins, numPins) { }