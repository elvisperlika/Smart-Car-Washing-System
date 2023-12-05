#include "components/tests/LedTest.h"
#include <assert.h>

LedTest::LedTest(Component *component) : Test(component) {
    this->component = component;
}

bool LedTest::test()
{
    /* UNITY_BEGIN(); // IMPORTANT LINE! */

    Led *led = (Led *) this->component;
    led->switchLight(true);

    

    /* UNITY_END(); // stop unit testing */
    return true;
}


