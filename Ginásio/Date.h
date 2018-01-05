#ifndef DATE_H_
#define DATE_H_

#include <iostream>

class Date {
friend std::ostream & operator<<(std::ostream &out , const Date &date);
friend bool operator<(const Date & date1, const Date & date2);
friend bool operator==(const Date & date1, const Date & date2);

int hour, min,weekDay;

public:
	Date(int hour, int min, int weekDay);
	Date();

	int getHour()const{return hour;}
	int getMin()const{return min;}
	int getWeekDay()const{return weekDay;}
};

#endif /* DATE_H_ */
