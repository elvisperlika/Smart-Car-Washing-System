#include <Arduino.h>
#include <Scheduler.h>
#include "tasks/AccessTask.h"
#include "tasks/StateTask.h"

Scheduler sched;
Task* accessTask;
Task* stateTask;

void setup() {
  accessTask = new AccessTask(9);
  accessTask->init(100);
  // sched.addTask(accessTask);

  stateTask = new StateTask();
  stateTask->init(100);
  stateTask->setActive(true);
  stateTask->tick();
  sched.addTask(stateTask);

  sched.init(300);
  Serial.begin(9600);
}

void loop() {
  sched.schedule();
}
