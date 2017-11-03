#include "Schedule.h"
#include "ErrorClasses.h"

Schedule::Schedule() {}

Schedule::~Schedule() {
	//Delete all set's dynamic allocated variables
	for(auto f : schedule){
		delete f;
	}
}


bool Schedule::addDate(const Date &dateStart, const Date &dateFinish){

	//New element to be added to set of dates
	std::pair<Date, Date> * pairDate;

	//Prevents unordered or equal dates
	if(dateStart < dateFinish)
		pairDate = new std::pair<Date, Date>(dateStart, dateFinish);

	else if(dateStart == dateFinish)
		throw ErrorDate("Dates are equal");

	else
		pairDate = new std::pair<Date, Date>(dateFinish, dateStart);


	//auto rVal = schedule.insert(pairDate); //Also valid
	std::pair<std::set<std::pair<Date,Date>*>::iterator, bool> rVal = schedule.insert(pairDate);

	return rVal.second;
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


//PRINT : In development

void Schedule::printSchedule(std::ostream &out){

	std::set<std::pair<Date,Date>*>::iterator it;

	for(it = schedule.begin(); it != schedule.end(); ++it){
		out << weekDay_to_string((*it)->first.weekDay) << "\t" << (*it)->first.hour << ":" << (*it)->first.min << std::endl;
		out << weekDay_to_string((*it)->second.weekDay) << "\t" << (*it)->second.hour << ":" << (*it)->second.min << std::endl;
		out << std::endl;
	}



}

//End print functions

