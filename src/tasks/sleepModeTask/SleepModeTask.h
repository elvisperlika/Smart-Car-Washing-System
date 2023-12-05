#ifndef __SLEEP_MODE_TASK_H__
#define __SLEEP_MODE_TASK_H__

#include "../Task.h"
#include <avr/sleep.h>

class SleepModeTask: public Task {
    public:
        SleepModeTask(int period, CarWash *carWash);
        void tick();
<<<<<<< HEAD
        void unsleep1();
=======
        int getState();
>>>>>>> 60a6591a444ea8a73b354d2874f654f6b507e831
};
#endif
