#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "Date.h"
#include <set>
#include <iostream>
#include <vector>
#include <new>


struct APtrComp
{
  bool operator()(const std::pair<Date,Date>* lhs, const std::pair<Date,Date>* rhs) const  {
	  if(lhs->second < rhs->first)
	  		return true;
	  	else return false;
  }
};

class Schedule {
public:
	Schedule();
	virtual ~Schedule();

	/**
	 * @brief Add a date to the schedule
	 * @param dateStart Time interval start date
	 * @param dateStart Time interval finish date
	 *
	 * @return Returns true if the time interval was added successfully and returns false otherwise
	 */
	bool addDate(const Date &dateStart, const Date &dateFinish);

	/**
	 * @brief Prints in a user-friendly way the schedule
	 * @param out Output stream
	 */
	void printSchedule(std::ostream &out);
private:
	std::set<std::pair<Date,Date>*,APtrComp> schedule;
};

#endif /* SCHEDULE_H_ */
