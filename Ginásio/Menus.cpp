#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "colorWin.h"
#include "ListElements.h"
#include "Menus.h"

using namespace std;


void mainMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Gym related", "\t2.	Client related", "\t3.	Staff related", "\n\t0.	Leave\n" };

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
		case 2:{
			Schedule schedule = gym.getGymSchedule();
			schedule.editScheduleMenu();
			gym.setGymSchedule(schedule);
			break;}
		case 3:
			capacityMenu(gym);
			break;
		case 4:
			subscriptionsMenu(gym);
			break;
		case 5:
			cout << gym;
			break;
		default:
			break;
		}
	} while (continueInMenu);

}

void clientMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Add", "\t2.	Edit", "\t3.	Remove", "\t4.	Display Information", "\t5.	List Clients" ,"\n\t0.	Leave\n" };

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
		case 5:
			listClient(gym);
			intervalFuntion();
			break;
		default:
			break;
		}
	} while (continueInMenu);
}

void staffMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Professor related", "\t2.	Add", "\t3.	Edit", "\t4.	Remove",  "\t5.	Display Information", "\t6.	List Staff", "\n\t0.	Leave\n" };

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

		case 6:
			listStaff(gym);
			intervalFuntion();
			break;
		default:
			break;
		}
	} while (continueInMenu);
}

void personalTrainerMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Add", "\t2.	Remove", "\t3.	Edit", "\t4.	Display Information", "\t5.	List Personal Trainers" ,"\n\t0.	Leave\n" };

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

		case 5:
			listPT(gym);
			intervalFuntion();
			break;

		default:
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
			gym.addProgram();
			break;
		case 2:
			inputProgramIdObj(optionProgram, gym, &programToUse);
			programToUse->editProgram(gym);
			break;
		case 3:
			gym.removeProgram();
			break;
		case 4:
			gym.displayProgramOptions();
			break;
		default:
			break;
		}
	} while (continueInMenu);
}

void capacityMenu(Gym &gym)
{
	vector<string> sections = { "\t1.	Change maximum capacity", "\t2.	Change maximum number of clients", "\n\t0.	Leave\n" };

	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	CAPACITY MENU 	" << endl;
		cout << "\t-------------------------------" << endl << endl;
		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			gym.changeCapacity();
			break;
		case 2:
			gym.changeMaxNumClients();
			break;
		default:
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

void listClient(Gym &gym){

	cout << "	    List Clients by: \n";
	cout << "	---------------------------\n\n";
	cout << "	1.	ID\n";
	cout << "	2.	Name\n";
	cout << "	3.	Age\n\n";
	cout << "	0. 	Leave\n\n";
	unsigned char op = filterInput(0,3);


	switch(op)
	{
	case 0:
		return;

	case 1:
		listingByID(gym.getClients());
		break;

	case 2:
		listingByName(gym.getClients());
		break;

	case 3:
		listingByAge(gym.getClients());
		break;
	}

}

void listStaff(Gym &gym){

	cout << "	    List Staff by: \n";
	cout << "	---------------------------\n\n";
	cout << "	1.	ID\n";
	cout << "	2.	Name\n";
	cout << "	3.	Age\n";
	cout << "	4.	Wage\n\n";
	cout << "	0. 	Leave\n\n";
	unsigned char op = filterInput(0,4);


	switch(op)
	{
	case 0:
		return;

	case 1:
		listingByID(gym.getStaff());
		break;

	case 2:
		listingByName(gym.getStaff());
		break;

	case 3:
		listingByAge(gym.getStaff());
		break;
	case 4:
		listingByWage(gym.getStaff());
		break;
	}

}

void listPT(Gym &gym){

	cout << "	    List Personal Trainers by: \n";
	cout << "	---------------------------\n\n";
	cout << "	1.	ID\n";
	cout << "	2.	Name\n";
	cout << "	3.	Age\n";
	cout << "	4.	Wage\n\n";
	cout << "	0. 	Leave\n\n";
	
	unsigned char op = filterInput(0,4);

	switch(op)
	{
	case 0:
		return;

	case 1:
		listingByID(gym.getPT());
		break;

	case 2:
		listingByName(gym.getPT());
		break;

	case 3:
		listingByAge(gym.getPT());
		break;

	case 4:
		listingByWage(gym.getPT());
		break;
	}
}

void intervalFuntion()
{
	cout << "Press a key to continue...\n";
	cin.clear();
	string temp;
	getline(cin, temp);
	cout << endl;
}
