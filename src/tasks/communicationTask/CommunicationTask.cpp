#include "CommunicationTask.h"

CommunicationTask::CommunicationTask(int period, CarWash *carWash) : Task(period, carWash) {
    MsgService.init();
}

void CommunicationTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();    
        if (msg->getContent() == "1"){
            carWash->errorTempratureFixed();
        }
        // NOT TO FORGET: message deallocation 
        delete msg;
    } else {
        this->state = carWash->enumToString(carWash->getState());
    }

    char dataOut[100];
    sprintf(dataOut, "{\"temperature\": \"%d\", \"state\": \"%s\"}", carWash->getTemperature(), this->state.c_str());
    MsgService.sendMsg(dataOut);
}