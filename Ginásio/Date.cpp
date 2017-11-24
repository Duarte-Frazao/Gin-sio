#include "stdafx.h"
#include "Date.h"

Date::Date(int hour, int min, int weekDay){
	try {
		if (weekDay < 1 || weekDay > 7 || hour < 0 || hour > 24 || min < 0 || min > 60)
			throw ErrorDate("Invalid date inserted");

		this->hour = hour;
		this->min = min;
		this->weekDay = weekDay;
	}
	catch (ErrorDate &e) {
		std::cout << e.getReason() << std::endl;
	}
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

std::string weekDay_to_string(int weekDay){
	switch (weekDay){
	case 1: return "Monday";
	case 2: return "Tuesday";
	case 3: return "Wednesday";
	case 4: return "Thursday";
	case 5: return "Friday";
	case 6: return "Saturday";
	case 7: return "Sunday";
	default: return "";
	}
}

std::ostream & operator<<(std::ostream &out , const Date &date){

		out << weekDay_to_string(date.weekDay) << "\t" << date.hour << ":" << date.min;
		return out;
}
