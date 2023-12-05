#ifndef __TEST_H__
#define __TEST_H__

#include "components/Component.h"
/* #include <unity.h> */


class Test {
    protected:
        Component *component;
    public:
        Test(Component *component);
        virtual bool test() = 0;
};

#endif
