#include "CarWashTest.h"

CarWashTest::CarWashTest(CarWash* carWash) {
    this->carWash = carWash;
}

const char* CarWashTest::getState() {
    return carWash->enumToString(carWash->getState());
}