#include "stdafx.h"
#include "Gym.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <vector>
#include "termcolor.hpp"




using namespace std;

void mainMenu(Gym &gym);
void gymMenu(Gym &gym);
void clientMenu(Gym &gym);
void staffMenu(Gym &gym);
void personalTrainerMenu(Gym &gym);
void financeMenu(Gym &gym);
void subscriptionsMenu(Gym &gym);
void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);
void inputStaffIdObj(int &optionStaff, Gym &gym, Staff** staff_found);
void inputPtIdObj(int &optionPt, Gym &gym, Staff** staff_found);
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found);
void intervalFuntion();
int filterInput(int inf, int sup,std::string msg = "Selection: ");
void teste(Gym &gym);

void mainMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Gym related", "\t2.	Client related", "\t3.	Staff related", "\t4. Testing Hall",  "\n\t0.	Leave\n" };



	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	MAIN MENU 	" << endl;
		cout << "\t------------------------" << endl << endl;

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			gymMenu(gym);
			break;
		case 2:
			clientMenu(gym);
			break;
		case 3:
			staffMenu(gym);
			break;
		case 4:
			teste(gym);
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);

}

void gymMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Finances", "\t2.	Change Schedule", "\t3.	Change capacity", "\t4.	Manage subscriptions", "\t5.	Display Information",  "\n\t0.	Leave\n" };

	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	GYM MENU 	" << endl;
		cout << "\t----------------------" << endl << endl;

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			financeMenu(gym);
			break;
		case 2:
			//scheduleMenu();
			break;
		case 3:
			//capacityMenu();
			break;
		case 4:
			subscriptionsMenu(gym);
			break;
		case 5:
			cout << gym ;
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);

}

void clientMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Add", "\t2.	Edit", "\t3.	Remove", "\t4.	Display Information", "\n\t0.	Leave\n" };

	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	CLIENT MENU 	" << endl;
		cout << "\t-------------------------" << endl << endl;
		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int optionClient;
		Client *clientToUse = NULL;
		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			gym.addClient();
			break;
		case 2:
			inputClientIdObj(optionClient,gym, &clientToUse);
			clientToUse->editClient(gym);
			break;
		case 3:
			gym.removeClient();
			break;
		case 4: 
			inputClientIdObj(optionClient, gym, &clientToUse);
			clientToUse->informationClient();
			intervalFuntion();
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

void staffMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Professor related", "\t2.	Add", "\t3.	Edit", "\t4.	Remove",  "\t5.	Display Information", "\n\t0.	Leave\n" };

	int optionStaff;
	Staff *staffToUse = NULL;
	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	STAFF MENU 	" << endl;
		cout << "\t-------------------------" << endl << endl;
		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			personalTrainerMenu(gym);
			break;
		case 2:
			gym.addStaff();
			intervalFuntion();
			break;
		case 3:
			inputStaffIdObj(optionStaff, gym, &staffToUse);
			staffToUse->editStaff(gym);
			intervalFuntion();
			break;
		case 4:
			gym.removeStaff();
			intervalFuntion();
			break;
		case 5:
			inputStaffIdObj(optionStaff, gym, &staffToUse);
			staffToUse->printInfo();
			intervalFuntion();
			break;
		default:
			std::cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

void personalTrainerMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Add", "\t2.	Remove", "\t3.	Edit", "\t4.	Display Information", "\n\t0.	Leave\n" };

	int optionProf;
	Staff *profToUse = NULL;
	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	PERSONAL TRAINER MENU 	" << endl;
		cout << "\t--------------------------------------" << endl << endl;
		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			gym.addPersonalTrainer();
			intervalFuntion();
			break;
		case 2:
			gym.removePersonalTrainer();
			intervalFuntion();
			break;
		case 3: 
		{
			inputPtIdObj(optionProf, gym, &profToUse);
			PersonalTrainer* pt = dynamic_cast<PersonalTrainer *> (profToUse);
			if (pt != NULL) pt->editPersonalTrainer(gym);
			intervalFuntion();
			break;
		}
		case 4:
			inputPtIdObj(optionProf, gym, &profToUse);
			profToUse->printInfo();
			intervalFuntion();
			break;
		default:
			std::cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

void financeMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Obtain gym finance extract", "\t2.	Deposit amount ", "\t3.	Make a payment", "\n\t0.	Leave\n" };

	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	FINANCE MENU 	" << endl;
		cout << "\t--------------------------" << endl << endl;

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			cout << gym.getGymFinance();
			break;
		case 2:
			gym.depositAmount();
			break;
		case 3:
			gym.makePayments();
			break;
		default:
			std::cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

void subscriptionsMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Add", "\t2.	Edit", "\t3.	Remove", "\t4.	Display Information", "\n\t0.	Leave\n" };

	bool continueInMenu = true;
	string newName;
	do
	{
		cout << endl << "\t 	SUBSCRIPTION MENU 	" << endl;
		cout << "\t-------------------------------" << endl << endl;
		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		int optionProgram;
		Program *programToUse = NULL;
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			//gym.addProgram();
			break;
		case 2:
			inputProgramIdObj(optionProgram, gym, &programToUse);
			programToUse->editProgram(gym);
			break;
		case 3:
			//gym.removeProgram();
			gym.removeClient();
			break;
		case 4:
			gym.displayProgramOptions();
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

void displayIdHelp(Gym &gym, int option)
{
	/*
	0-Clients
	1-Programs
	2-Staff
	3-Professors
	*/
	
	switch (option)
	{
		case 0:
			gym.displayClientsIds();
			break;
		case 1:
			gym.displayProgramOptions();
			break;
		case 2:
			gym.displayStaffIds();
			break;
		case 3:
			gym.displayProfsIds();
			break;
		default:
			cout << "Algum erro" << endl;
		}
}

void inputClientIdObj(int &optionClient,Gym &gym, Client** client_found)
{
	if(gym.getClients().empty()){
		cerr << "There are no clients in the gym" << std::endl;
		return;
	}

	cout << "----------ID Selection----------" << endl ;


	bool repeat = false;

		do
		{
			repeat = false;
			cout << endl << sign::question<< "Insert client's ID (or h for help): ";

			cin >> optionClient;

			if(std::cin.fail()){
				cin.clear();
				if(toupper(std::cin.peek()) == 'H'){
					displayIdHelp(gym,0);
				}
				else cout << sign::error <<"Insert a number" << endl;

				repeat = true;
				cin.ignore(1000,'\n');
			}

			else if (!gym.findClient(optionClient, client_found)){
				cout << sign::error <<"Insert a valid ID" << endl;
				repeat = true;
			}
		} while (repeat);
}

void inputStaffIdObj(int &optionStaff, Gym &gym, Staff** staff_found)
{
	if (gym.getStaff().empty()) {
		cerr << "There are no staff in the gym" << std::endl;
		return;
	}

	cout << "----------ID Selection----------" << endl;

	bool repeat = false;

		do
		{
			repeat = false;
			cout << endl << sign::question<< "Insert staff's ID (or h for help): ";

			cin >> optionStaff;

			if(std::cin.fail()){
				cin.clear();
				if(toupper(std::cin.peek()) == 'H'){
					displayIdHelp(gym,2);
				}
				else cout << sign::error <<"Insert a number" << endl;
				repeat = true;
				cin.ignore(1000,'\n');
			}

			else if (!gym.findStaff(optionStaff, staff_found)){
				cout << sign::error <<"Insert a valid ID" << endl;
				repeat = true;
			}
		} while (repeat);

}

void inputPtIdObj(int &optionPt, Gym &gym, Staff** staff_found)
{
	if (gym.getPT().empty()) {
		cerr << "There are no personal trainers in the gym" << std::endl;
		return;
	}

	cout << "----------ID Selection----------" << endl;
	bool repeat = false;

		do
		{
			repeat = false;
			cout << endl << sign::question<< "Insert Personal Trainer's ID (or h for help): ";

			cin >> optionPt;

			if(std::cin.fail()){
				cin.clear();
				if(toupper(std::cin.peek()) == 'H'){
					displayIdHelp(gym,3);
				}
				else cout << sign::error <<"Insert a number" << endl;
				repeat = true;
				cin.ignore(1000,'\n');
			}

			else if (!gym.findProf(optionPt, staff_found)){
				cout << sign::error <<"Insert a valid ID" << endl;
				repeat = true;
			}
		} while (repeat);
}


//To-do ver se o id do programa corresponde ao id que o user insere
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found)
{
	if (gym.getPrograms().empty()) {
		cerr << "There are no programs in the gym" << std::endl;
		return;
	}

	cout << "----------ID Selection----------" << endl;
	bool repeat = false;

	do
	{
		repeat = false;
		cout << endl << sign::question<< "Insert Program's ID (or h for help): ";

		cin >> optionProgram;

		if(std::cin.fail()){
			cin.clear();
			if(toupper(std::cin.peek()) == 'H'){
				displayIdHelp(gym,1);
			}
			else cout << sign::error <<"Insert a number" << endl;
			repeat = true;
			cin.ignore(1000,'\n');
		}

		else if (!gym.findProgram(optionProgram, program_found)){
			cout << sign::error <<"Insert a valid ID" << endl;
			repeat = true;
		}
	} while (repeat);
}

void intervalFuntion()
{
	cout << "Press a key to continue...\n";
	cin.clear();
	string temp;
	cin.ignore(1000, '\n');
	getline(cin, temp);
	cout << endl;
}




void teste(Gym &gym)
{
	vector<string> sections = { "\t1.	Teste1" , "\n\t0.	Leave\n" };
	for(uint i=0;i < gym.getClients().size();i++) gym.getClients().at(i)->setPlans();
	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	Testing Hall 	" << endl;
		cout << "\t--------------------------" << endl << endl;

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			for(uint i = 0; i < gym.getClients().at(0)->getPlans().size();i++ ) cout <<  gym.getClients().at(0)->getPlans().at(i) << endl;
			break;
		}
	} while (continueInMenu);

}
