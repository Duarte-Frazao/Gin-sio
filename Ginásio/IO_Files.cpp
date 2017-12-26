#include <iostream>
#include <string>
#include <vector>
#include <queue>
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

Gym * readInformationFile(std::string fileName) {

	std::ifstream inFile(fileName);

	if (!inFile.is_open())
		std::cerr << "Erro a abrir";

	std::string controlWord;
	char brackets;


	//GYM
	//---------------------
	std::string gym_name;
	int gym_maxNumClients;
	int gym_maxCapacity;

	inFile >> controlWord;
	if (controlWord != "Gym"); //throw error

	inFile >> brackets >> gym_name >> gym_maxNumClients >> gym_maxCapacity >> brackets;
	//---------------------



	//Finance
	//---------------------
	std::string transaction_type;
	std::string transaction_description;
	double transaction_amount;
	std::string transaction_dateTransaction;

	inFile >> controlWord;
	if (controlWord != "Finance"); //throw error

	Finance *finance = new Finance();

	while (inFile.peek() != ';') {

		inFile >> brackets >> transaction_type >> transaction_amount;

		std::string line;
		getline(inFile, line);

		transaction_description = line.substr(line.find_first_of("\"") + 1, line.find_last_of("\"") - line.find_first_of("\"") - 1);
		transaction_dateTransaction = line.substr(line.find_first_of("\'") + 1, line.find_last_of("\'") - line.find_first_of("\'") - 1);

		Transaction temp(transaction_type, transaction_description, transaction_amount, transaction_dateTransaction);
		finance->addTransaction(temp);
	}
	inFile.get();

	//---------------------


	//Schedule
	//---------------------
	int schedule_day;
	int schedule_hour;
	int schedule_min;

	inFile >> controlWord;
	if (controlWord != "Schedule"); //throw error

	Schedule * schedule = new Schedule;

	while (inFile.peek() != ';') {
		inFile >> brackets >> schedule_day >> schedule_hour >> brackets >> schedule_min;
		Date date1(schedule_hour, schedule_min, schedule_day);

		inFile >> schedule_hour >> brackets >> schedule_min >> brackets;
		Date date2(schedule_hour, schedule_min, schedule_day);

		schedule->addDate(date1, date2);

		inFile.get();
	}
	inFile.get();

	//---------------------

	//Programs
	//----------------------------
	int program_code;
	int program_days;
	float program_cost;

	inFile >> controlWord;
	if (controlWord != "Programs"); //throw error


	std::vector<Program *> programs;

	while (inFile.peek() != ';') {
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
	if (controlWord != "Staff"); //throw error
	std::vector<Staff *> staff;

	while (inFile.peek() != ';') {
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

	std::priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> profs;

	while (inFile.peek() != ';') {
		//Only accepts one word name and one word Area
		inFile >> brackets >> staff_id >> staff_name >> staff_age >> staff_wage
			>> staff_pwd >> profs_specializedArea >> brackets;


		PersonalTrainer * PT = new PersonalTrainer(staff_id, staff_name, staff_age, staff_wage, staff_pwd, profs_specializedArea);
		staff.push_back(PT);
		profs.push(PT);
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

		for (auto pProgram : programs) {
			if (pProgram->getCode() == client_enrolledProgram_code)
				enrolledProgram = pProgram;
		}

		std::priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp(profs);
		while (!temp.empty()) {
			if (temp.top()->getId() == client_responsiblePT_id)
				responsiblePT = temp.top();

			temp.pop();
		}
		clients.push_back(new Client(client_name, enrolledProgram, client_age, responsiblePT));

		inFile.get();
	}

	inFile.get();

	//----------------------------

	inFile >> controlWord;
	if (controlWord != "end"); //throw error




	return new Gym(gym_name, programs, clients, staff, profs, *schedule,
		gym_maxNumClients, gym_maxCapacity, *finance);

}

void writeInformationFile(std::string fileName, Gym & gym) {

	std::ofstream outFile(fileName);

	if (!outFile.is_open())
		std::cerr << "Erro a abrir";


	//GYM
	//---------------------
	outFile << "Gym" << std::endl;
	outFile << "[ " << gym.getName() << " " << gym.getMaxNumClients() << " " << gym.getMaxCapacity() << " ]\n\n";
	//---------------------


	//Schedule
	//----------------------------
	outFile << "Finance" << std::endl;

	for (auto transaction : gym.getGymFinance().getTransactions()) {
		outFile << "[ " << std::setw(10) << std::left << transaction.getType() << " ";
		outFile << std::setw(6) << std::right << transaction.getAmount() << " ";
		outFile << std::setw(20) << std::left << "\"" + transaction.getDescription() + "\"" << " ";
		outFile << std::setw(26) << std::right << "\'" + transaction.getDateTransaction() + "\'";
		outFile << " ]\n";
	}

	outFile << ";\n\n";
	//----------------------------

	//Schedule
	//----------------------------
	outFile << "Schedule" << std::endl;

	for (auto pPar : gym.getGymSchedule().getScheduleSet()) {
		outFile << "[ " << pPar->first.weekDay << " ";
		outFile << std::setfill('0') << std::setw(2) << pPar->first.hour << ":" << std::setw(2) << pPar->first.min;
		outFile << " ";
		outFile << std::setfill('0') << std::setw(2) << pPar->second.hour << ":" << std::setw(2) << pPar->second.min;
		outFile << " ]\n";
	}

	outFile << ";\n\n";
	//----------------------------


	//Programs
	//----------------------------
	outFile << "Programs" << std::endl;

	for (auto pProgram : gym.getPrograms()) {
		outFile << "[ " << pProgram->getCode() << " " << pProgram->getDays() << " "
			<< pProgram->getCost() << " ]\n";
	}

	outFile << ";\n\n";
	//----------------------------


	//Staff
	//----------------------------
	outFile << "Staff" << std::endl;

	for (auto pStaff : gym.getStaff()) {
		if (dynamic_cast<PersonalTrainer *> (pStaff) == NULL) {
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

	std::priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp(gym.getPT());
	while (!temp.empty()) {
		outFile << "[ " << temp.top()->getId() << " " << temp.top()->getName() << " "
			<< temp.top()->getAge() << " " << temp.top()->getWage() << " "
			<< temp.top()->getPassword() << " "
			<< temp.top()->getSpecializedArea() << " ]\n";

		temp.pop();
	}

	outFile << ";\n\n";
	//----------------------------


	//Clients
	//----------------------------
	outFile << "Clients" << std::endl;

	for (auto pClient : gym.getClients()) {
		outFile << "[ " << pClient->getName() << " " << pClient->getProgram()->getCode() << " "
			<< pClient->getAge() << " " << pClient->getPT()->getId() << " ]\n";
	}

	outFile << ";\n\n";


	//----------------------------


	outFile << "end";


}
