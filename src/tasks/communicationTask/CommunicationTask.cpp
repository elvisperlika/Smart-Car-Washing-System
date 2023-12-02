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
        delete msg;
    } else {
        state = carWash->enumToString(carWash->getState());
    }

    buffer = String(carWash->getTemperature(), 2);

    char dataOut[100];
    sprintf(dataOut, "{\"temperature\": \"%s\", \"state\": \"%s\"}", buffer.begin(), this->state.c_str());
    
    MsgService.sendMsg(dataOut);
}