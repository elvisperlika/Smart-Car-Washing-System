#ifndef __ACCESS_TASK__
#define __ACCESS_TASK__

#include "tasks/Task.h"
#include "components/Gate.h"

class AccessTask: public Task {

    Gate* gate;
    enum { CLOSE, WAITING_TO_OPEN, IN_OPENING, OPEN, WAITING_TO_CLOSE, IN_CLOSING } state;
    uint8_t tOpen;
    uint8_t tClose;
    const unsigned long TOPEN = 3000;
    const unsigned long TCLOSE = 1000;
    bool carDetected = true;
    bool carWash = false;
    int carDistance = 0;

    public:
        AccessTask(int gatePin);  
        void init(int period);  
        void tick();
};

#endif
