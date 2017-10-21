/*
 * Schedule.h
 *
 *  Created on: 11/10/2017
 *      Author: Windows10
 */
#include <utility>
#include <vector>

#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "Date.h"
using namespace std;

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
	/*
	bool overlapDate(const Date &date){
		if(schedule.empty()) return false;

		for(unsigned int i = 0; i < schedule.size(); i++){
			if(schedule.at(i)->second < date)
				return false;

			else if(schedule.at(i)->first < date && date<schedule.at(i)->second)
		}

	}
*/
	vector<pair<Date,Date>*> schedule;

};

#endif /* SCHEDULE_H_ */
