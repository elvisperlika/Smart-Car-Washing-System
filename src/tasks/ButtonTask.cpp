#include "ButtonTask.h"

ButtonTask::ButtonTask(int period, CarWash *carWash) : Task(period, carWash) { }

void ButtonTask::checkButtonState() {
    if (carWash->getState() == READY_TO_BE_WASHED && carWash->isButtonPressed()) {
        carWash->setState(READY_TO_BE_WASHED_BUTTON_PRESSED);
    }
}
