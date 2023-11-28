#include <Arduino.h>
#include <Scheduler.h>
#include "tasks/AccessTask.h"
#include "tasks/StateTask.h"

Scheduler sched;
Task *accessTask;
Task *stateTask;
CarWash *carWash;

void setup()
{
    carWash = new CarWash();
    accessTask = new AccessTask(100, carWash);
    // sched.addTask(accessTask);

    stateTask = new StateTask(100, carWash);
    stateTask->setActive(true);
    sched.addTask(stateTask);

    sched.init(100);
    Serial.begin(9600);
}

void loop()
{
    sched.schedule();
}
