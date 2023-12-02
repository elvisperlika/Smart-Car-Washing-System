#include "tasks/userInterfaceTask/UserInterfaceTask.h"

UserInterfaceTask::UserInterfaceTask(int period, CarWash *carWash): Task(period, carWash) {
    this->UIState = UserInterfaceState::DETECTION_;
}

void UserInterfaceTask::tick() {
    switch (UIState) {
        case UserInterfaceState::DETECTION_:
            carWash->getLed1()->switchLight(false);
            carWash->getLed2()->switchLight(false);
            carWash->getLed3()->switchLight(false);
            if (carWash->getState() == SystemState::WELCOME)
            {
                carWash->getLed1()->switchLight(true);
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Welcome!");
                UIState = WELCOME_;
            }
            break;
        case UserInterfaceState::WELCOME_:
            if (carWash->getState() == SystemState::VEICHLE_WAITING)
            {
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Proceed to the Washing Area!");
            } else if(carWash->getState() == SystemState::DETECTION) {
                UIState = DETECTION_;
            }
            break;
        case UserInterfaceState::CHECK_IN_:
            carWash->getLed2()->blink(100l);
            if (carWash->getState() == SystemState::VEICHLE_WAITING)
            {
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Ready to Wash!");
                carWash->getLed2()->switchLight(true);
                UIState = VEICHLE_WAITING_;
            }
            break;
        case UserInterfaceState::VEICHLE_WAITING_:
            if (carWash->getState() == SystemState::WASHING)
            {
                UIState = WASHING_;
                carWash->getLcd()->clearScreen();
            }
            break;
        case UserInterfaceState::WASHING_:
            carWash->getLed2()->blink(500l);
            buffer = String(T3 - carWash->getGlobalWashingTime(), 0);
            carWash->getLcd()->displayText(buffer.begin());
            if (carWash->getState() == SystemState::WASHING_ERROR)
            {
                UIState = WASHING_ERROR_;
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Detected a Problem - Please Wait!");
            } else if (carWash->getState() == SystemState::CHECK_OUT) {
                UIState = CHECK_OUT_;
                carWash->getLed2()->switchLight(false);
                carWash->getLed3()->switchLight(true);
                carWash->getLcd()->clearScreen();
                carWash->getLcd()->displayText("Washing complete, you can leave the area!");
            }
            break;
        case UserInterfaceState::WASHING_ERROR_:
            if (carWash->getState() == SystemState::WASHING)
            {
                UIState = WASHING_;
                carWash->getLcd()->clearScreen();
            }
            break;
        case UserInterfaceState::CHECK_OUT_:
            if (carWash->getState() == SystemState::DETECTION)
            {
                UIState = DETECTION_;
                carWash->getLed3()->switchLight(false);
                carWash->getLcd()->clearScreen();
            }
            break;
        default:
            break;
    }
}