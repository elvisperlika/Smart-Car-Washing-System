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
<<<<<<< HEAD
=======

int SleepModeTask::getState()
{
    return 0;
}
>>>>>>> 60a6591a444ea8a73b354d2874f654f6b507e831
