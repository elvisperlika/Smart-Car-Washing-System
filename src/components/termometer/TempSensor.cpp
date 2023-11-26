#include "TempSensor.h"

TempSensor::TempSensor(unsigned short pin) : Component(new Pin(pin, INPUT), 1) { }