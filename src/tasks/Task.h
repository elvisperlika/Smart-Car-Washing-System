#ifndef __TASK_H__
#define __TASK_H__

#include "model/CarWash.h"

class Task {
	protected:
		CarWash *carWash;
		int myPeriod;
		int timeElapsed;
		const char* name;
	
	public:
		Task(int period, CarWash *carWash);

		virtual void tick() = 0;

		virtual int getState() = 0;

		bool updateAndCheckTime(int basePeriod);

		const char* getName();

		void setName(const char* name);
  
};

#endif
