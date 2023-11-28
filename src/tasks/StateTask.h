#ifndef __STATETASK__
#define __STATETASK__
#include "Task.h"
#include "components/msg/MsgService.h"

class StateTask: public Task {
    private: 
        Msg* msg;
        char data;
        String dataOut;
        int temp;
        String state;
    public:
        StateTask(int period, CarWash *carWash);
        void tick();
};

#endif