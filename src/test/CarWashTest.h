#ifndef __CAR_WASH_TEST_H__
#define __CAR_WASH_TEST_H__

#include "../src/model/CarWash.h"

class CarWashTest {
    private:
        CarWash* carWash;
        const char* getState();

    public:
        CarWashTest(CarWash* carWash);
        void testLedsOn();
        void testLedsOff();
        void testLedsBlink();
        void testPresentiometer();
        void testButton();
        void testLcdWrite();
        void testLcdClear();


};

#endif