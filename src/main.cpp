#include <Arduino.h>
#include <Scheduler.h>
#include "tasks/tempCheckTask/TempCheckTask.h"
#include "tasks/stateTask/StateTask.h"

Scheduler sched;
Task *accessTask;
Task *stateTask;
CarWash *carWash;

void setup()
{
    Serial.begin(9600);
    carWash = new CarWash();
    accessTask = new TempCheckTask(100, carWash);
    // sched.addTask(accessTask);

    stateTask = new StateTask(1000, carWash);
    stateTask->setName("StateTask");
    stateTask->setActive(true);
    sched.addTask(stateTask);

    sched.init(100);
}

void loop()
{
    sched.schedule();
}
