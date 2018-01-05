#include <iomanip>
#include "Schedule.h"
#include "ErrorClasses.h"
#include "colorWin.h"

int filterInput(int inf, int sup, std::string msg = "Selection: ");
std::string weekDay_to_string(int weekDay);


Schedule::Schedule() {}
Schedule::~Schedule() {}

/**
Shows the menu of options for editing the staff's information
and returns the option chosen

@return Returns chosen option for the edit staff menu
*/
int scheduleMenu()
{
	std::cout << std::endl << "\t	SCHEDULE MENU 	" << std::endl;
	std::cout << "\t---------------------------" << std::endl << std::endl;

	std::vector<std::string> options = { "\t1.	Add task", "\t2.	Edit task", "\t3.	Delete task", "\t4.	List tasks","\n\t0.	Leave\n" };

	for (unsigned int i = 0; i < options.size(); i++)
		std::cout << options.at(i) << std::endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}


void Schedule::editScheduleMenu(){

	bool continueInMenu = true;
	do
	{
		int option = scheduleMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			addTask();
			break;
		case 2:
			changeTask();
			break;
		case 3:
			deleteTask();
			break;

		case 4:
			listTaskMenu();
			break;
		default: break;
		}
	} while (continueInMenu);
}


void Schedule::removeInInterval(const Date &dateStart, const Date &dateFinish){

	for(std::set<Task *,Task::TaskPtrCmp>::iterator it = schedule.begin(); it != schedule.end(); it++){
		if( !((*it)->start < dateStart) && !(dateFinish < (*it)->end))
			schedule.erase(it);

		else if( ((*it)->start < dateStart) &&  (dateStart < (*it)->end)){
			Date d1 = (*it)->start;
			Date d2 = (*it)->end;
			std::string desc = (*it)->desc;
			deleteTask(d1,d2);
			addTask(d1, dateStart, desc);
		}

		else if((*it)->start < dateFinish && dateFinish < (*it)->end){
			Date d1 = (*it)->start;
			Date d2 = (*it)->end;
			std::string desc = (*it)->desc;
			deleteTask(d1,d2);
			addTask(dateFinish, d2, desc);
		}
	}
}


bool Schedule::addTask(const Date &dateStart, const Date &dateFinish, std::string description){

	//New element to be added
	Task * task;

	//Prevents unordered or equal dates
	if (dateStart < dateFinish)
		task = new Task(dateStart, dateFinish, description);

	else if (dateStart == dateFinish)
		throw ErrorDate("Dates are equal");

	else task = new Task(dateFinish, dateStart, description);


	//auto rVal = schedule.insert(pairDate); //Also valid
	std::pair<std::set<Task *,Task::TaskPtrCmp>::iterator, bool> rVal = schedule.insert(task);

	return rVal.second;
}

bool Schedule::changeTask(const Date &dateStart, const Date &dateFinish, std::string description){

	Task task(dateStart, dateFinish, "");

	std::set<Task *,Task::TaskPtrCmp>::iterator rVal = schedule.find(&task);


	if(rVal == schedule.end())
			return false;

	else {
		if(task.start == (*rVal)->start && task.end == (*rVal)->end){
		(*rVal)->desc = description;
		return true;
		}
		else return false;
	}
}

bool Schedule::deleteTask(const Date &dateStart, const Date &dateFinish){
	Task task(dateStart, dateFinish, "");
	std::set<Task *,Task::TaskPtrCmp>::iterator rVal = schedule.find(&task);

	if(rVal == schedule.end())
		return false;
	else {
		if(task.start == (*rVal)->start && task.end == (*rVal)->end){
		schedule.erase(rVal);
		return true;
		}
		else return false;
	}
}



void Schedule::addTask(){

	try{
		std::cout << "Start date: "<<std::endl;
		Date d1;
		std::cout << "End date: "<<std::endl;
		Date d2;
		std::string desc;
		std::cout << "Description: " ;
		std::cin.ignore();
		getline(std::cin, desc);

		bool success = addTask(d1,d2,desc);

		char answer;
		if(success)
			std::cout << "Task: Added successfully" << std::endl;
		else{
			std::cout << "Task: Overlapped time intervals" << std::endl;
			std::cout << "Do you want to overwrite? (Y/N): " << std::endl;
			std::cin >> answer;

			if(toupper(answer) == 'Y'){
				removeInInterval(d1,d2);
				success = addTask(d1,d2,desc);

				if(success) std::cout << "Task: Added successfully" << std::endl;
				else std::cout << "Task: Overlapped time intervals" << std::endl;
			}
		}
	}
	catch(ErrorDate &e){
		std::cout << e.getReason() << std::endl;
	}
}


void Schedule::changeTask(){

	try{
		std::cout << "Start date: "<<std::endl;
		Date d1;
		std::cout << "End date: "<<std::endl;
		Date d2;
		std::string desc;
		std::cout << "Description: " ;
		std::cin.ignore();
		getline(std::cin, desc);

		bool success = changeTask(d1,d2,desc);

		if(success)
			std::cout << "Task: Changed successfully" << std::endl;
		else
			std::cout << "Task: Time interval not found " << std::endl;
	}
	catch(ErrorDate &e){
		std::cout << e.getReason() << std::endl;
	}
}

void Schedule::deleteTask(){
	try{
		Date d1;
		Date d2;

		bool success = deleteTask(d1,d2);
		char answer;
		if(success)
			std::cout << "Task: Deleted successfully" << std::endl;
		else{
			std::cout << "Task: Time interval specified is not a full task. " << std::endl;
			std::cout << "Do you want to erase anyway? (Y/N): " << std::endl;
			std::cin >> answer;

			if(toupper(answer) == 'Y'){
				removeInInterval(d1,d2);
				std::cout << "Task: Deleted successfully" << std::endl;
			}
		}
	}
	catch(ErrorDate &e){
		std::cout << e.getReason() << std::endl;
	}
}


void Schedule::listTaskMenu() const{

	std::cout << "	    List Tasks by: \n";
	std::cout << "	---------------------------\n\n";
	std::cout << "	1.	Date and hour\n";
	std::cout << "	2.	Description\n";
	std::cout << "	0. 	Leave\n\n";
	unsigned char op = filterInput(0,2);


	switch(op)
	{
	case 0:
		return;

	case 1:
		listTaskbyTime();
		break;

	case 2:
		listTaskbyDesc();
		break;

	case 3:
		//listingByDuration();
		break;
	}
}


bool Schedule::listTaskbyDesc() const{

	//Creates new schedule with a different order
	std::set<Task *,Task::TaskPtrCmpDesc> scheduleDesc;

	for(auto pTask : schedule)
		scheduleDesc.insert(new Task(*pTask));

	if (scheduleDesc.size() == 0)
		return false;


	std::set<Task *,Task::TaskPtrCmp>::iterator it_start = scheduleDesc.begin();
	std::set<Task *,Task::TaskPtrCmp>::iterator it_end = scheduleDesc.end();
	std::set<Task *,Task::TaskPtrCmp>::iterator it_last = it_end; it_last--;

	std::cout << "Minimum value available: " << (*it_start)->start << std::endl;
	std::cout << "Maximum value available: " << (*it_last)->end << std::endl<<std::endl;
	std::cout << "Between which values: " << std::endl;

	std::string init, final;
	bool all = false;

	std::cout << "Between which values (-1 for all): " << std::endl;
	std::cout << "Minimum: "; std::cin >> init;

	try{
		if(std::stoi(init) == -1)
			all=true;
	}
	catch(...){
		all = false;
	}

	if(!all){
		std::cout << "Maximum: "; std::cin >>final;
	}
	else{
		init = (*it_start)->desc;
		final = (*it_last)->desc;
	}


	bool found = false;

	for(auto it = it_start; it !=it_end; it++){
		if( (init <= (*it)->desc)  &&  (*it)->desc <= final){
			std::cout << *(*it) << std::endl;
			found = true;
		}
	}


	if(!found) std::cout << std::endl << sign::error << "No description found" << std::endl;

	return found;
}


bool Schedule::listTaskbyTime() const{

	if (schedule.size() == 0)
		return false;

	int wd1, hrs1, min1;
	int wd2, hrs2, min2;

	std::set<Task *,Task::TaskPtrCmp>::iterator it_start = schedule.begin();
	std::set<Task *,Task::TaskPtrCmp>::iterator it_end = schedule.end();
	std::set<Task *,Task::TaskPtrCmp>::iterator it_last = it_end; it_last--;

	std::cout <<"Minimum value available: " << (*it_start)->start << std::endl;
	std::cout << "Maximum value available: " << (*it_last)->end << std::endl<<std::endl;

	bool all = false;

	std::cout << "Between which values (-1 for all): " << std::endl;
	std::cout << "Minimum Date (weekday hour minute): ";
	std::cin >> wd1;

	if(wd1 != -1){
		std::cin >> hrs1 >> min1;
	}
	else all=true;


	if(!all){
		std::cout << "Maximum Date (weekday hour minute): "; std::cin >> wd2 >> hrs2 >> min2;
	}
	else{
		 wd1 = (*it_start)->start.getWeekDay();
		 hrs1 = (*it_start)->start.getHour();
		 min1 = (*it_start)->start.getMin();

		 wd2 = (*it_last)->end.getWeekDay();
		 hrs2 = (*it_last)->end.getHour();
		 min2 = (*it_last)->end.getMin();
	}


	try{
		Date d1(hrs1,min1,wd1);
		Date d2(hrs2,min2,wd2);


	bool found = false;

	for(auto it = it_start; it !=it_end; it++){
		if( !((*it)->start  < d1)  &&  !(d2 < (*it)->end)){
			std::cout << *(*it);
			found = true;
		}
	}


	if(!found) std::cout << std::endl << sign::error << "No Task Found" << std::endl;


	return found;

	}
	catch (ErrorDate &e) {
		std::cout << e.getReason() << std::endl;
		return false;
	}
}



std::set<Task *, Task::TaskPtrCmp> Schedule::getScheduleSet() const{
	return schedule;
}

bool Task::operator==(const Task &task){
	return (start == task.start && end == task.end);
}

std::ostream & operator<<(std::ostream &out, const Task &task){

	out  << std::setfill(' ') << std::setw(10)<< std::left <<weekDay_to_string(task.start.getWeekDay()) << ": " << std::right;
	out << std::setfill('0') << std::setw(2) << task.start.getHour() << ":" << std::setw(2)<<task.start.getMin() << " To ";

	for(unsigned int i = task.start.getWeekDay(); i < task.end.getWeekDay(); i++){
		out << std::setfill('0') << std::setw(2) << 23 << ":" << std::setw(2) << 59;
		out << "\tDescription: " << task.desc <<std::endl;

		out  << std::setfill(' ') << std::setw(10)<< std::left <<weekDay_to_string(i+1) << ": " << std::right;
		out << std::setfill('0') << std::setw(2) << 00 << ":" << std::setw(2)<< 00 << " To ";
	}

	out << std::setfill('0') << std::setw(2) << task.end.getHour() << ":" << std::setw(2) << task.end.getMin();
	out << "\tDescription: " << task.desc <<std::endl;

	return out;
}


std::ostream & operator<<(std::ostream &out, const Schedule &schedule){

	std::set<Task *,Task::TaskPtrCmp>::iterator it;
	out << "Week schedule: " <<std::endl;

	for(it = schedule.schedule.begin(); it != schedule.schedule.end(); ++it)
		out << *(*it);

	return out;
}
