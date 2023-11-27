#include "Task.h"

void Task::init(int period, CarWash *carWash) {
        Task::carWash = carWash;
		myPeriod = period;  
		timeElapsed = 0;
		active = true;
}

bool Task::updateAndCheckTime(int basePeriod){
		timeElapsed += basePeriod;
		if (timeElapsed >= myPeriod){
			timeElapsed = 0;
			return true;
		} else {
			return false; 
		}
}

bool Task::isActive(){
    return active;
}

void Task::setActive(bool active){
    this->active = active;
}