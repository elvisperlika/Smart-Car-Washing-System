#include <Arduino.h>
#include "Scheduler.h"
#include "tasks/detectMotionTask/DetectionTask.h"
#include "tasks/accessTask/AccessTask.h"
#include "tasks/sleepModeTask/SleepModeTask.h"
#include "tasks/checkInOutTask/checkInOutTask.h"
#include "tasks/buttonTask/ButtonTask.h"
#include "tasks/washTask/WashTask.h"
#include "tasks/tempCheckTask/TempCheckTask.h"
#include "tasks/communicationTask/CommunicationTask.h"
#include "tasks/userInterfaceTask/UserInterfaceTask.h"
#include "test/CarWashTest.h"

Scheduler sched;
CarWash *carWash;

void unsleep() {
    carWash->setSuspended(false);
    Serial.println("Unsleep");
}

void setup()
{
    Serial.begin(BAUD_RATE);
    
    carWash = new CarWash();

    sched.init(100);

    Task *detectTask = new DetectionTask(100, carWash);
    detectTask->setName("DetectionTask");
    Task *accessTask = new AccessTask(100, carWash);
    accessTask->setName("AccessTask");
    Task *sleepTask = new SleepModeTask(500, carWash);
    sleepTask->setName("SleepModeTask");
    Task *checkInOutTask = new CheckInOutTask(100, carWash);
    checkInOutTask->setName("CheckInOutTask");
    Task *buttonTask = new ButtonTask(100, carWash);
    buttonTask->setName("ButtonTask");
    Task *washTask = new WashTask(100, carWash);
    washTask->setName("WashTask");
    Task *tempCheckTask = new TempCheckTask(100, carWash);
    tempCheckTask->setName("TempCheckTask");
    Task *communicationTask = new CommunicationTask(100, carWash);
    communicationTask->setName("CommunicationTask");
    Task *userInterfaceTask = new UserInterfaceTask(100, carWash);
    userInterfaceTask->setName("UserInterfaceTask");
    
    sched.addTask(userInterfaceTask);
    sched.addTask(communicationTask);
    sched.addTask(detectTask);
    sched.addTask(accessTask);
    sched.addTask(checkInOutTask);
    sched.addTask(buttonTask);
    sched.addTask(washTask);
    sched.addTask(tempCheckTask);
    sched.addTask(sleepTask);

    /* enableInterrupt(MOTION_SENSOR_PIN, unsleep, CHANGE); */
    attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), unsleep, RISING);
}

void loop()
{
    sched.schedule();
}
