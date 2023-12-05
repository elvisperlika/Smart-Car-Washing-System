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
    sprintf(dataOut, "{\"temperature\": \"%s\", \"state\": \"%s\", \"washingNumber\": \"%d\"}", 
        buffer.begin(), carWash->isSuspended() ? "SLEEP" : carWash->enumToString(carWash->getState()), carWash->getCarWashed());
    Serial.println(dataOut);
}