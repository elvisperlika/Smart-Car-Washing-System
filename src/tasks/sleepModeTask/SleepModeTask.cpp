#include "SleepModeTask.h"

SleepModeTask::SleepModeTask(int period, CarWash *carWash) : Task(period, carWash) {}

void SleepModeTask::unsleep1()
{
    carWash->setSuspended(false);
    /* Serial.println("Unsleep"); */
}

void SleepModeTask::tick()
{
    if (carWash->isSuspended())
    {
        /* Serial.println("Sleep"); */
        delay(100);
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        

        sleep_mode();
        sleep_disable();
        /* detachInterrupt(MOTION_SENSOR_PIN); */

    }
}
