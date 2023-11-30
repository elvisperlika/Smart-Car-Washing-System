#ifndef __STATE_TASK_H__
#define __STATE_TASK_H__
#include "../Task.h"
#include "components/msg/MsgService.h"

class CommunicationTask: public Task {
    private: 
        Msg* msg;
        char data;
        String dataOut;
        String state;
        String buffer;
    public:
        CommunicationTask(int period, CarWash *carWash);
        void tick();
};

#endif