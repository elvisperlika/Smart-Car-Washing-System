#include "BlinkTask.h"
  
BlinkTask::BlinkTask(int period, CarWash *carWash) : Task(period, carWash) {
  //led = new Led(pin); 
  state = OFF;    
}
  
void BlinkTask::tick() {
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
