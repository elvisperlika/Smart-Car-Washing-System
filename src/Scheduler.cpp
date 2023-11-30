#include "Scheduler.h"
#include <Arduino.h>
#include "components/Timer.h"

Timer* Timer_1;

void Scheduler::init(int basePeriod){
    Timer_1 = new Timer();
    this->basePeriod = basePeriod;
    long period = 1000l*basePeriod;
    
    Timer_1->setupPeriod(basePeriod);
    nTasks = 0;
}

bool Scheduler::addTask(Task* task){
    delay(500);
    if (nTasks < MAX_TASKS-1){
        taskList[nTasks] = task;
        nTasks++;
        return true;
    } else {
        return false; 
    }
}
  
void Scheduler::schedule(){   
    
    Timer_1->waitForNextTick();

    for (int i = 0; i <= nTasks; i++){
        if (taskList[i]->isActive() && taskList[i]->updateAndCheckTime(basePeriod)){
            taskList[i]->tick();
        }
    }

}
