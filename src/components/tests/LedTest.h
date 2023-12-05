#ifndef __LED_TEST_H__
#define __LED_TEST_H__

#include "components/tests/Test.h"
#include "components/light/Led.h"

class LedTest: public Test {
    public:
        LedTest(Component *component);
        bool test();
};

#endif