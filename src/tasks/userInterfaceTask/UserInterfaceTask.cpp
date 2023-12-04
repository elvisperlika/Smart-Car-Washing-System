#include "UserInterfaceTask.h"

UserInterfaceTask::UserInterfaceTask(int period, CarWash *carWash): Task(period, carWash) {
    state = UserInterfaceTaskStates::DETECTION_;
}

void UserInterfaceTask::tick() {


    switch (state) {
        case UserInterfaceTaskStates::DETECTION_:
            carWash->getLcd()->clearScreen();
            carWash->getLed1()->switchLight(false);
            carWash->getLed2()->switchLight(false);
            carWash->getLed3()->switchLight(false);
            if (carWash->getState() == SystemState::WELCOME)
            {
                carWash->getLed1()->switchLight(true);
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Welcome!");
                state = UserInterfaceTaskStates::WELCOME_;
            }
            break;

        case UserInterfaceTaskStates::WELCOME_:
            if (carWash->getState() == SystemState::CHECK_IN)
            {
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Proceed to the Washing Area!");
                state = UserInterfaceTaskStates::CHECK_IN_;
            } else if (carWash->getState() == SystemState::DETECTION) {
                state = UserInterfaceTaskStates::DETECTION_;
            }
            break;

        case UserInterfaceTaskStates::CHECK_IN_:
            carWash->getLed2()->blink(100l);
            if (carWash->getState() == SystemState::READY_TO_BE_WASHED)
            {
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Ready to Wash!");
                carWash->getLed2()->switchLight(true);
                state = UserInterfaceTaskStates::VEICHLE_WAITING_;
            }
            break;

        case UserInterfaceTaskStates::VEICHLE_WAITING_:
            if (carWash->getState() == SystemState::WASHING)
            {
                state = UserInterfaceTaskStates::WASHING_;
                carWash->getLcd()->clearScreen();
            }
            break;

        case UserInterfaceTaskStates::WASHING_:
            carWash->getLed2()->blink(500l);
            buffer = String(T3 - carWash->getGlobalWashingTime(), 0);
            carWash->getLcd()->displayText(buffer.begin());
            if (carWash->getState() == SystemState::WASHING_ERROR)
            {
                state = UserInterfaceTaskStates::WASHING_ERROR_;
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Detected a Problem - Please Wait!");
            } else if (carWash->getState() == SystemState::CHECK_OUT) {
                state = UserInterfaceTaskStates::CHECK_OUT_;
                carWash->getLed2()->switchLight(false);
                carWash->getLed3()->switchLight(true);
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Washing complete, you can leave the area!");
            }
            break;

        case UserInterfaceTaskStates::WASHING_ERROR_:
            if (carWash->getState() == SystemState::WASHING)
            {
                state = UserInterfaceTaskStates::WASHING_;
                carWash->getLcd()->clearScreen();
            }
            break;

        case UserInterfaceTaskStates::CHECK_OUT_:
            if (carWash->getState() == SystemState::DETECTION)
            {
                state = UserInterfaceTaskStates::DETECTION_;
                carWash->getLed3()->switchLight(false);
                carWash->getLcd()->clearScreen();
            }
            break;
    }
}