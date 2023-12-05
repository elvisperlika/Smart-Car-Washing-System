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
    }

    buffer = String(carWash->getTemperature(), 2);

    char dataOut[100];
<<<<<<< HEAD
    sprintf(dataOut, "{\"temperature\": \"%s\", \"state\": \"%s\"}", buffer.begin(), carWash->isSuspended() ? "SLEEP" : carWash->enumToString(carWash->getState()));
    Serial.println(dataOut);
=======
    sprintf(dataOut, "{\"temperature\": \"%s\", \"state\": \"%s\"}", buffer.begin(), this->state.c_str());
    
    MsgService.sendMsg(dataOut);
}

int CommunicationTask::getState() {
    return -1;
>>>>>>> 60a6591a444ea8a73b354d2874f654f6b507e831
}