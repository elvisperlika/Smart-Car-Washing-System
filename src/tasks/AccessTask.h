#ifndef __ACCESS_TASK__
#define __ACCESS_TASK__

#include "Task.h"
#include "Gate.h"

class AccessTask: public Task {

    Gate* gate;
    enum { CLOSE, WAITING_TO_OPEN, IN_OPENING, OPEN, WAITING_TO_CLOSE, IN_CLOSING } state;
    uint8_t tOpen;
    uint8_t tClose;
    static uint8_t TOPEN;
    static uint8_t TCLOSE;

    public:
        AccessTask(Gate* gate);  
        void init(int period);  
        void tick();
};

#endif
