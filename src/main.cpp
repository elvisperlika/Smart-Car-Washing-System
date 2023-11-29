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
    carWash = new CarWash();
    accessTask = new TempCheckTask(100, carWash);
    // sched.addTask(accessTask);

    stateTask = new StateTask(1000, carWash);
    stateTask->setName("StateTask");
    stateTask->setActive(true);
    sched.addTask(stateTask);

    sched.init(200);
    Serial.begin(9600);
}

void loop()
{
    sched.schedule();
}
