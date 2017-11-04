#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>


#include "Gym.h"
#include "Program.h"
#include "Staff.h"
#include "PersonalTrainer.h"
#include "Client.h"
#include "Schedule.h"
#include "Finance.h"


Gym * readInformationFile(std::string fileName){

	std::ifstream inFile(fileName);

	if(!inFile.is_open())
		std::cerr << "Erro a abrir";

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

	//----------------------------

	inFile >> controlWord;
	if (controlWord != "end"); //throw error

	Schedule *schedule = new Schedule();
	Finance *finance = new Finance();


	return new Gym(gym_name, programs, clients, staff, profs,*schedule,
			gym_maxNumClients, gym_maxCapacity, *finance);

}

void writeInformationFile(std::string fileName, Gym & gym){

	std::ofstream outFile(fileName);

	if(!outFile.is_open())
		std::cerr << "Erro a abrir";


	//GYM
	//---------------------
	outFile << "Gym" << std::endl;
	outFile << "[ " << gym.getName() << " " << gym.getMaxNumClients() << " " << gym.getMaxCapacity() << " ]\n\n";
	//---------------------


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


	outFile << "end";


}
