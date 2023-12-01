#ifndef SERVOIMPL_H
#define SERVOIMPL_H
#include "components/servoVer2/ServoM.h"
#include <ServoTimer2.h>

class ServoMImpl : public ServoM {
    private:
        ServoTimer2 servo;
        int angle;
    public:
        ServoMImpl(unsigned short pin);
        void setPosition(int _angle);
        
};

#endif
