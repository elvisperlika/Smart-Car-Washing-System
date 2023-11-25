#include <Arduino.h>
#include <Scheduler.h>
#include "tasks/AccessTask.h"

Scheduler sched;
Task* accessTask;

void setup() {
  sched.init(100);
  accessTask = new AccessTask(new Gate(8));
  sched.addTask(accessTask);
  Serial.begin(9600);
}

void loop() {
  sched.schedule();
}
