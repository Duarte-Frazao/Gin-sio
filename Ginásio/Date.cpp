#include "Date.h"

Date::Date(int hour, int min, int weekDay){
	if(weekDay < 1 || weekDay > 7 || hour < 0 || hour > 24 || min < 0 || min > 60)
		throw ErrorDate("Invalid date inserted");

	this->hour = hour;
	this->min = min;
	this->weekDay = weekDay;
}

bool operator<(const Date & date1, const Date & date2){
	if(date1.weekDay < date2.weekDay ||
			(date1.weekDay == date2.weekDay && date1.hour < date2.hour) ||
					(date1.weekDay == date2.weekDay && date1.hour == date2.hour && date1.min < date2.min))
		return true;

	else return false;
}

bool operator==(const Date & date1, const Date & date2){
	if(date1.weekDay == date2.weekDay && date1.hour == date2.hour && date1.min == date2.min)
		return true;

	else return false;
}

ostream & operator<<(ostream & out, const ErrorDate & errorDate) {
	out << errorDate.reason;
	return out;
}
