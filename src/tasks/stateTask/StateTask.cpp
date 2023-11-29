#include "StateTask.h"

StateTask::StateTask(int period, CarWash *carWash) : Task(period, carWash) {
    MsgService.init();
}

void StateTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();    
        if (msg->getContent() == "1"){
            // carWash->errorTempratureFixed();
        }
        // NOT TO FORGET: message deallocation 
        delete msg;
    } else {
        this->state = carWash->enumToString(carWash->getState());
    }

    this->buffer = String(carWash->getTemperature(), 2);

    char dataOut[100];
    sprintf(dataOut, "{\"temperature\": \"%s\", \"state\": \"%s\"}", buffer.begin(), this->state.c_str());
    
    MsgService.sendMsg(dataOut);
}