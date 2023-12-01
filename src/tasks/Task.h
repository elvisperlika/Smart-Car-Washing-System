#ifndef __TASK_H__
#define __TASK_H__

#include "model/CarWash.h"

class Task {
	protected:
		CarWash *carWash;
		int myPeriod;
		int timeElapsed;
		bool active;
		String name;
	
	public:
		Task(int period, CarWash *carWash);

		virtual void tick() = 0;

		bool updateAndCheckTime(int basePeriod);

		bool isActive();

		void setActive(bool active);

		String getName();

		void setName(String name);
  
};

#endif
