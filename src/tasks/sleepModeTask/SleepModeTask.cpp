#include "SleepModeTask.h"

SleepModeTask::SleepModeTask(int period, CarWash *carWash) : Task(period, carWash) {}

void SleepModeTask::tick()
{
    if (carWash->isSuspended())
    {
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode();

        sleep_disable();
    }
}
