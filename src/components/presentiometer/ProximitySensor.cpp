#include "ProximitySensor.h"

ProximitySensor::ProximitySensor(unsigned short pin) : Component(new Pin(pin, INPUT), 1) { }