#ifndef __TASK__
#define __TASK__

#include "../model/CarWash.h"

class Task {
	protected:
		CarWash *carWash;
		int myPeriod;
		int timeElapsed;
		bool active;		
	
	public:
		void init(int period, CarWash *carWash);

		virtual void tick() = 0;

		bool updateAndCheckTime(int basePeriod);

		bool isActive();

		void setActive(bool active);
  
};

#endif
