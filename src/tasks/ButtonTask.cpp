#include "ButtonTask.h"

ButtonTask::ButtonTask(Button* button) {
    buttonPtr = button;
}

void ButtonTask::checkButtonState() {
    if (SystemState::READY_TO_BE_WASHED && !SystemState::READY_TO_BE_WASHED_BUTTON_PRESSED && buttonPtr->isClicked()) {
        SystemState::READY_TO_BE_WASHED_BUTTON_PRESSED;
    }
}
