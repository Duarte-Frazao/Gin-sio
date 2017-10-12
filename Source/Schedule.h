/*
 * Schedule.h
 *
 *  Created on: 11/10/2017
 *      Author: Windows10
 */
#include <utility>
#include <vector>
#include "Date.h"


#ifndef SOURCE_SCHEDULE_H_
#define SOURCE_SCHEDULE_H_

class Schedule {
public:
	Schedule();
	virtual ~Schedule();

	/**
	 * Add a date to the schedule
	 */
	bool addDate(const Date &dateStart, const Date &dateFinish){

	}

private:

	/**
	 * Verifies if the date given as parameter has already something
	 */
	bool overlapDate(const Date &date){
		if(schedule.empty()) return false;

		for(unsigned int i = 0; i < schedule.size(); i++){
			if(schedule.at(i)->second < date)
				return false;

			else if(schedule.at(i)->first < date && date<schedule.at(i)->second)
		}

	}

	std::vector<std::pair<Date,Date>*> schedule;

};

#endif /* SOURCE_SCHEDULE_H_ */
