#ifndef DATE_H_
#define DATE_H_
#include <utility>
#include <string>
#include "ErrorClasses.h"

class Date {
friend class Schedule;
friend std::ostream & operator<<(std::ostream &out , const Date &date);
public:
	Date(int hour, int min, int weekDay);
	friend bool operator<(const Date & date1, const Date & date2);
	friend bool operator==(const Date & date1, const Date & date2);
	int hour, min,weekDay;

private:

};



#endif /* DATE_H_ */
