#include "tasks/StateTask.h"
#include "StateTask.h"

StateTask::StateTask() {}

void StateTask::init(int period) {
  Task::init(period);
  MsgService.init();
}

void StateTask::tick() {
    if (MsgService.isMsgAvailable()) {
        Msg* msg = MsgService.receiveMsg();    
        if (msg->getContent() == "1"){
            delay(500);
            // alert = false;
        }
        /* NOT TO FORGET: message deallocation */
        delete msg;
    }
    this->state = "NOT_DEFINED";
    
    /* switch (this->state) {
    case :
        state = "CAR_DETECTED";
        break;
    case :
        state = "CAR_CHECK_IN";
        break;
    case :
        state = "CAR_WASH";
        break;
    case :
        state = "CAR_CHECK_OUT";
        break;
    case :
        state = "ALERT";
        break;
    
    default:
        state = "NOT_DEFINED";
        break;
    } */

    char dataOut[100];
    sprintf(dataOut, "{\"temperature\": [%d], \"state\": \"%s\"}", this->temp, this->state.c_str());

    MsgService.sendMsg(dataOut);
    delay(200);
    
}