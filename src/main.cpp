#include <Arduino.h>
#include <Scheduler.h>
#include "tasks/tempCheckTask/TempCheckTask.h"
#include "tasks/stateTask/StateTask.h"
#include "tasks/detectMotionTask/DetectionTask.h"

Scheduler sched;
CarWash *carWash;

Task *accessTask;
Task *stateTask;
Task *detectMotionTask;

void setup()
{
    sched.init(100);

    carWash = new CarWash();
    accessTask = new TempCheckTask(100, carWash);
    // sched.addTask(accessTask);

    detectMotionTask = new DetectionTask(100, carWash);
    detectMotionTask->setName("DetectionTask");
    detectMotionTask->setActive(true);

    stateTask = new StateTask(1000, carWash);
    stateTask->setName("StateTask");
    stateTask->setActive(true);

    sched.addTask(detectMotionTask);
    sched.addTask(stateTask);
}

void loop()
{
    sched.schedule();
}
