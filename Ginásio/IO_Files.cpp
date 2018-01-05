#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <iomanip>

#include "Gym.h"
#include "Program.h"
#include "Staff.h"
#include "PersonalTrainer.h"
#include "Client.h"
#include "Schedule.h"
#include "Finance.h"


Schedule * readSchedule(std::ifstream &inFile){
	int schedule_day;
	int schedule_hour;
	int schedule_min;
	char brackets;
	std::string desc;

	Schedule * schedule = new Schedule;

	while(inFile.peek() != ';' ){
		inFile >> brackets >> schedule_day >> schedule_hour >> brackets >> schedule_min;
		Date date1(schedule_hour,schedule_min,schedule_day);

		inFile >> schedule_day >> schedule_hour >> brackets >> schedule_min;
		Date date2(schedule_hour,schedule_min,schedule_day);

		inFile.ignore();
		getline(inFile, desc);
		desc = desc.substr(1, desc.length() - 4);
		schedule->addTask(date1,date2,desc);
	}
	inFile.get();

	return schedule;
}



void writeSchedule(std::ofstream &outFile, const Schedule & schedule){
	for(auto pTask : schedule.getScheduleSet()){
		outFile << "[ " << pTask->start.getWeekDay() << " ";
		outFile << std::setfill('0') << std::setw(2) << pTask->start.getHour() << ":" << std::setw(2)<<pTask->start.getMin();
		outFile << " " << pTask->end.getWeekDay() << " ";
		outFile << std::setfill('0') << std::setw(2) << pTask->end.getHour() << ":" << std::setw(2)<<pTask->end.getMin();
		outFile << " " << "\"" << pTask->desc << "\"";
		outFile << " ]\n";
	}
	outFile << ";\n";
}

Gym * readInformationFile(std::string fileName){

	std::ifstream inFile(fileName);

	if(!inFile.is_open()){
		std::cerr << "Erro a abrir o ficheiro " << fileName << ". " <<std::endl;
		throw InvalidValue("File Inexistent!");
	}

	std::string controlWord;
	char brackets;


	//GYM
	//---------------------
	std::string gym_name;
	int gym_maxNumClients;
	int gym_maxCapacity;

	inFile >> controlWord;
	if(controlWord != "Gym"); //throw error

	inFile >> brackets >> gym_name >> gym_maxNumClients >> gym_maxCapacity >> brackets;
	//---------------------



	//Finance
	//---------------------
	std::string transaction_type;
	std::string transaction_description;
	double transaction_amount;
	std::string transaction_dateTransaction;

	inFile >> controlWord;
	if(controlWord != "Finance"); //throw error

	Finance *finance = new Finance();

	while(inFile.peek() != ';' ){

		inFile >> brackets >> transaction_type >> transaction_amount;

		std::string line;
		getline(inFile, line);

		transaction_description = line.substr(line.find_first_of("\"")+1, line.find_last_of("\"")-line.find_first_of("\"")-1);
		transaction_dateTransaction = line.substr(line.find_first_of("\'")+1, line.find_last_of("\'")-line.find_first_of("\'")-1);

		Transaction temp(transaction_type, transaction_description, transaction_amount, transaction_dateTransaction);
		finance->addTransaction(temp);
	}
	inFile.get();

	//---------------------

	//Programs
	//----------------------------
	int program_code;
	int program_days;
	float program_cost;

	inFile >> controlWord;
	if(controlWord != "Programs"); //throw error


	std::vector<Program *> programs;

	while(inFile.peek() != ';' ){
		inFile >> brackets >> program_code >> program_days >> program_cost >> brackets;

		programs.push_back(new Program(program_code, program_days, program_cost));
		inFile.get();
	}
	inFile.get();
	//----------------------------


	//Staff
	//----------------------------
	int staff_id;
	std::string staff_name;
	int staff_age;
	int staff_wage;
	std::string staff_pwd;

	inFile >> controlWord;
	if(controlWord != "Staff"); //throw error
	std::vector<Staff *> staff;

	while(inFile.peek() != ';'){
		inFile >> brackets >> staff_id >> staff_name >> staff_age >> staff_wage >> staff_pwd >> brackets; //Only accepts one word name
		staff.push_back(new Staff(staff_id, staff_name, staff_age, staff_wage, staff_pwd));
		staff.at(staff.size() - 1)->incrementStaffId();
		inFile.get();
	}
	inFile.get();
	//----------------------------


	//Personal Trainer
	//----------------------------
	std::string profs_specializedArea;
	inFile >> controlWord;
	if (controlWord != "PersonalTrainer"); //throw error

	std::vector<PersonalTrainer *> profs;

	while (inFile.peek() != ';') {
		//Only accepts one word name and one word Area
		inFile >> brackets >> staff_id >> staff_name >> staff_age >> staff_wage
				>> staff_pwd >> profs_specializedArea >> brackets;
		

		PersonalTrainer * PT = new PersonalTrainer(staff_id,staff_name, staff_age, staff_wage, staff_pwd, profs_specializedArea);
		staff.push_back(PT);
		profs.push_back(PT);
		staff.at(staff.size() - 1)->incrementStaffId();
		inFile.get();
	}

	inFile.get();
	//----------------------------

	//Clients
	//----------------------------
	std::string client_name;
	int client_enrolledProgram_code;
	int client_age;
	int client_responsiblePT_id;



	inFile >> controlWord;
	if (controlWord != "Clients"); //throw error

	std::vector<Client *> clients;

	while (inFile.peek() != ';') {
		inFile >> brackets >> client_name >> client_enrolledProgram_code
				>> client_age >> client_responsiblePT_id >> brackets;

		Program *enrolledProgram;
		PersonalTrainer *responsiblePT = NULL;

		for(auto pProgram : programs){
			if(pProgram->getCode() == client_enrolledProgram_code)
				enrolledProgram = pProgram;
		}

		for(auto pPT : profs){
			if(pPT->getId() == client_responsiblePT_id)
				responsiblePT = pPT;
		}
		clients.push_back(new Client(client_name, enrolledProgram, client_age, responsiblePT));

		inFile.get();
	}

	inFile.get();

	inFile >> controlWord;
	if(controlWord != "Schedule"); //throw error


	inFile >> controlWord;
	if(controlWord != "Gym"); //throw error

	Schedule * schedule = readSchedule(inFile);
	int id;

	inFile >> controlWord;
	if(controlWord != "Staff"); //throw error


	Schedule * workSchedule;
	//----------------------------
	while (inFile.peek() != ';') {

		inFile >> controlWord >> id;
		if(controlWord != "ID:"); //throw error

		workSchedule = readSchedule(inFile);

		staff.at(id-1)->setSchedule(*workSchedule);
		inFile.get();
	}
	inFile.get();


	inFile >> controlWord;
	if (controlWord != "end"); //throw error




	return new Gym(gym_name, programs, clients, staff, profs,*schedule,
			gym_maxNumClients, gym_maxCapacity, *finance);

}

void writeInformationFile(std::string fileName, Gym & gym){

	std::ofstream outFile(fileName);

	if(!outFile.is_open())
		std::cerr << "Erro a abrir o ficheiro "<< fileName << ". "<<std::endl;


	//GYM
	//---------------------
	outFile << "Gym" << std::endl;
	outFile << "[ " << gym.getName() << " " << gym.getMaxNumClients() << " " << gym.getMaxCapacity() << " ]\n\n";
	//---------------------


	//Finance
	//----------------------------
	outFile << "Finance" << std::endl;

	for(auto transaction : gym.getGymFinance().getTransactions()) {
		outFile << "[ " << std::setw(10) << std::left <<transaction.getType() << " ";
		outFile  << std::setw(6) << std::right << transaction.getAmount() << " ";
		outFile  << std::setw(20) << std::left << "\"" + transaction.getDescription() + "\"" << " ";
		outFile  << std::setw(26) << std::right << "\'" + transaction.getDateTransaction() + "\'";
		outFile << " ]\n";
	}

	outFile << ";\n\n";
	//----------------------------


	//Programs
	//----------------------------
	outFile << "Programs" << std::endl;

	for(auto pProgram : gym.getPrograms()){
		outFile << "[ " << pProgram->getCode() << " " <<  pProgram->getDays() << " "
				<< pProgram->getCost() << " ]\n";
	}

	outFile << ";\n\n";
	//----------------------------


	//Staff
	//----------------------------
	outFile << "Staff" << std::endl;

	for(auto pStaff : gym.getStaff()){
		if(dynamic_cast<PersonalTrainer *> (pStaff) == NULL){
		outFile << "[ " << pStaff->getId() << " " << pStaff->getName() << " "
				<< pStaff->getAge() << " " << pStaff->getWage() << " "
				<< pStaff->getPassword() << " ]\n";
		}
	}
	outFile << ";\n\n";
	//----------------------------

	
	//Personal Trainer
	//----------------------------
	outFile << "PersonalTrainer" << std::endl;

	for(auto pPT : gym.getPT()){
	outFile << "[ " <<  pPT->getId( )<< " " << pPT->getName() << " "
			<< pPT->getAge() << " " << pPT->getWage() << " "
			<< pPT->getPassword() << " "
			<< pPT->getSpecializedArea() << " ]\n";
	}

	outFile << ";\n\n";
	//----------------------------


	//Clients
	//----------------------------
	outFile << "Clients" << std::endl;

	for(auto pClient : gym.getClients()){
	outFile << "[ " << pClient->getName() << " " << pClient->getProgram()->getCode() << " "
			<< pClient->getAge() << " " << pClient->getPT()->getId() <<" ]\n";
	}

	outFile << ";\n\n";
	//----------------------------


	//Schedule
	//----------------------------
	outFile << "Schedule" << std::endl<<std::endl;

	outFile << "Gym" << std::endl;
	writeSchedule(outFile, gym.getGymSchedule());

	outFile << "Staff" << std::endl;

	for(unsigned int i = 0; i < gym.getStaff().size(); i++){
		Staff * staff = gym.getStaff().at(i);
		outFile << "ID: " << staff->getId() << std::endl;
		writeSchedule(outFile, staff->getSchedule());

		if(i + 1 == gym.getStaff().size())
			outFile << ";\n";
		else outFile << "\n";
	}
	//----------------------------

	outFile << "end";

}
