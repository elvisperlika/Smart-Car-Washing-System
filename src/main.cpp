#include <Arduino.h>
#include <Scheduler.h>
#include "tasks/detectMotionTask/DetectionTask.h"
#include "tasks/accessTask/AccessTask.h"
#include "tasks/sleepModeTask/SleepModeTask.h"
#include "tasks/checkInOutTask/checkInOutTask.h"
#include "tasks/buttonTask/ButtonTask.h"
#include "tasks/washTask/WashTask.h"
#include "tasks/tempCheckTask/TempCheckTask.h"
#include "tasks/communicationTask/CommunicationTask.h"

Scheduler sched;
CarWash *carWash;

void setup()
{
    Serial.begin(9600);
    carWash = new CarWash();

    Task *detectTask = new DetectionTask(100, carWash);
    Task *accessTask = new AccessTask(100, carWash);
    Task *sleepTask = new SleepModeTask(100, carWash);
    Task *checkInOutTask = new CheckInOutTask(100, carWash);
    Task *buttonTask = new ButtonTask(100, carWash);
    Task *washTask = new WashTask(100, carWash);
    Task *tempCheckTask = new TempCheckTask(100, carWash);
    Task *communicationTask = new CommunicationTask(100, carWash);
    
    sched.addTask(detectTask);
    sched.addTask(accessTask);
    sched.addTask(sleepTask);
    sched.addTask(checkInOutTask);
    sched.addTask(buttonTask);
    sched.addTask(washTask);
    sched.addTask(tempCheckTask);
    sched.addTask(communicationTask);

    sched.init(100);
}

void loop()
{
    sched.schedule();
}
