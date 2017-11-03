#ifndef DATE_H_
#define DATE_H_

#include <utility>
#include <string>
using namespace std;

class ErrorDate{
private:
	string reason;

public:
	ErrorDate(std::string reason) : reason(reason){};
	friend ostream & operator<<(ostream & out, const ErrorDate & errorDate);
};

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
