#include <Arduino.h>
#include <Scheduler.h>
#include "tasks/tempCheckTask/TempCheckTask.h"
#include "tasks/communicationTask/CommunicationTask.h"
#include "tasks/detectMotionTask/DetectionTask.h"
#include "tasks/accessTask/AccessTask.h"
#include "ServoTimer2.h"

Scheduler sched;
CarWash *carWash;

Task *accessTask;
Task *communicationTask;
Task *detectMotionTask;


void setup()
{
    sched.init(100);

    carWash = new CarWash();
    accessTask = new AccessTask(500, carWash);
    accessTask->setName("AccessTask");
    accessTask->setActive(true);

    detectMotionTask = new DetectionTask(100, carWash);
    detectMotionTask->setName("DetectionTask");
    detectMotionTask->setActive(false);

    communicationTask = new CommunicationTask(1000, carWash);
    communicationTask->setName("StateTask");
    communicationTask->setActive(true);


    sched.addTask(accessTask);
    sched.addTask(detectMotionTask);
    sched.addTask(communicationTask);
}

void loop()
{
    sched.schedule();
       
}
