#ifndef __STATETASK__
#define __STATETASK__
#include "Task.h"
#include "components/msg/MsgService.h"

class StateTask: public Task {
    private: 
        Msg* msg;
        char data;
        String dataOut;
        double temp;
    public:
        StateTask();
        void init(int period);
        void tick();
};

#endif