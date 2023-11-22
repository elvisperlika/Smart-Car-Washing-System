#include <Arduino.h>
#include <Scheduler.h>

Scheduler sched;

void setup() {
  sched.init(100);
  Serial.begin(9600);
}

void loop() {
  sched.schedule();
}
