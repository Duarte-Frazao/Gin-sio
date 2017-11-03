#ifndef DATE_H_
#define DATE_H_
#include <utility>
#include <string>


class Date {
friend class Schedule;
public:
	Date(int hour, int min, int weekDay);
	friend bool operator<(const Date & date1, const Date & date2);
	friend bool operator==(const Date & date1, const Date & date2);

private:
	int weekDay, hour, min;
};



#endif /* DATE_H_ */
