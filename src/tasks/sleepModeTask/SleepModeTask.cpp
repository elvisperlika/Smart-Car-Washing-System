#include "SleepModeTask.h"

bool flag = false;

void wakeUpNow()
{
    flag = true;
}

SleepModeTask::SleepModeTask(int period, CarWash *carWash) : Task(period, carWash) {}

void SleepModeTask::tick()
{
    if (carWash->isSuspended())
    {
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();

        attachInterrupt(digitalPinToInterrupt(MOTION_SENSOR_PIN), wakeUpNow, CHANGE);

        sleep_mode();
        sleep_disable();
    }

    if (flag)
    {
        carWash->setSuspended(false);
        flag = false;
    }
}