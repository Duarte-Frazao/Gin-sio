#include "stdafx.h"
#include "Schedule.h"
#include <iomanip>
#include "Schedule.h"

std::string weekDay_to_string(int weekDay);

Schedule::Schedule() {}

/*
Schedule::Schedule(const Schedule &source){
	std::cout << "COpy constructor"<< std::endl;
	for(auto pPar : source.schedule)
		schedule.insert(new std::pair<Date, Date>(*pPar));
}

Schedule::~Schedule() {
	std::cout << "Destruction"<<std::endl;
	for(auto pPar : schedule)
		delete pPar;
}*/
Schedule::~Schedule() {}

bool Schedule::addDate(const Date &dateStart, const Date &dateFinish){

	try {
		//New element to be added to set of dates
		std::pair<Date, Date> * pairDate;

		//Prevents unordered or equal dates
		if (dateStart < dateFinish)
			pairDate = new std::pair<Date, Date>(dateStart, dateFinish);

		else if (dateStart == dateFinish)
			throw ErrorDate("Dates are equal");

		else
			pairDate = new std::pair<Date, Date>(dateFinish, dateStart);


		//auto rVal = schedule.insert(pairDate); //Also valid
		std::pair<std::set<std::pair<Date, Date>*>::iterator, bool> rVal = schedule.insert(pairDate);

		return rVal.second;
	}
	catch (ErrorDate &e) {
		std::cout << e.getReason() << std::endl;
	}
}

std::set<std::pair<Date,Date>*,APtrComp> Schedule::getScheduleSet(){
	return schedule;
}



//PRINT : In development
std::ostream & operator<<(std::ostream &out, const Schedule &schedule){

	std::set<std::pair<Date,Date>*>::iterator it;
	out << "Week schedule: " <<std::endl;


	for(it = schedule.schedule.begin(); it != schedule.schedule.end(); ++it){
		out << std::setfill(' ');
		out << std::setw(10)<< std::left <<weekDay_to_string((*it)->first.weekDay) << ": " << std::right;
		out << std::setfill('0') << std::setw(2) << (*it)->first.hour << ":" << std::setw(2)<<(*it)->first.min << " To ";
		out << std::setfill('0') << std::setw(2) << (*it)->second.hour << ":" << std::setw(2) << (*it)->second.min;
		out << std::endl;
	}

	return out;
}

//End print functions



