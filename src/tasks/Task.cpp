#include "Task.h"

Task::Task(int period, CarWash *carWash) {
	Task::carWash = carWash;
	myPeriod = period;
	timeElapsed = 0;
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

const char* Task::getName() {
	return name;
}

void Task::setName(const char* name) {
	this->name = name;
}