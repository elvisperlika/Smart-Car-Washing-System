#include "BlinkTask.h"

BlinkTask::BlinkTask(int pin){
     
}
  
void BlinkTask::init(int period){
    Task::init(period);
    //led = new Led(pin); 
    state = OFF;    
}
  
void BlinkTask::tick(){
    switch (state){
    case OFF:
        //led->switchOn();
        state = ON; 
        break;
    case ON:
        //led->switchOff();
        state = OFF;
        break;
    }
}
