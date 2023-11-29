#include "SleepModeTask.h"

SleepModeTask::SleepModeTask(int period, CarWash *carWash) : Task(period, carWash) {}

void wakeUpNow() {}

void SleepModeTask::tick() {
    if (carWash->isSuspended())
    {
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();

        attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), wakeUpNow, CHANGE);        
        
        sleep_mode();
        sleep_disable(); 
    }
}

