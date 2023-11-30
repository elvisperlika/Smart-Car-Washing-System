#include "ServoMotor.h"

ServoMotor::ServoMotor(unsigned short pin) : Component(new Pin(pin, OUTPUT), 1) { }
