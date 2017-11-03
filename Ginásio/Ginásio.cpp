// Ginásio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Gym.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void gymMenu(Gym &gym);
void clientMenu(Gym &gym);
void staffMenu(Gym &gym);


int main()
{

	vector <Program *> programs
	{
		new Program(1),
		new Program(2)
	};

	Schedule sched;
	Finance fin;

	Gym GoGym("GoGym", programs, sched, 30, 30, fin);



	vector <PersonalTrainer *> pts
	{
		new PersonalTrainer(30, 500, "Karate", &GoGym),
		new PersonalTrainer(30, 500, "Jogging", &GoGym)
	};

	vector <Client *> clientes
	{
		new Client("Sandro", programs.at(0), 20, &GoGym, pts.at(0)),
		new Client("Duarte", programs.at(1), 20, &GoGym, pts.at(1)),
		new Client("Cesar", programs.at(0), 20, &GoGym, pts.at(1)),
		new Client("Ana", programs.at(1), 20, &GoGym, pts.at(0))
	};

	vector<Staff *> staff
	{
		pts.at(0),
		pts.at(1)
	};

	GoGym.setClients(clientes);
	GoGym.setStaff(staff);
	//Falta um set para os PersonalTrainer


    return 0;
}

void mainMenu(Gym &gym)
{
	cout << "What do you wish to do?" << endl;

	vector<string> sections = { "1 - Gym related", "2 - Client related", "3 - Staff related", "0 - Leave\n" };

	for (unsigned int i = 0; i < sections.size(); i++)
	{
		cout << sections.at(i) << endl;
	}

	bool continueInMenu = true;
	string newName;
	do
	{
		int option = filterInput(1, sections.size());
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

	cout << "What do you wish to do?" << endl;

	vector<string> sections = { "1 - Finances", "2 - Change Schedule", "3 - Change capacity", "4 - Manage subscriptions", "0 - Leave\n" };

	for (unsigned int i = 0; i < sections.size(); i++)
	{
		cout << sections.at(i) << endl;
	}

	bool continueInMenu = true;
	string newName;
	do
	{
		int option = filterInput(1, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			//financesMenu();
			break;
		case 2:
			//scheduleMenu();
			break;
		case 3:
			//capacityMenu();
			break;
		case 4:
			//subscriptionsMenu();
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);

}

void clientMenu(Gym &gym)
{
	cout << "What do you wish to do?" << endl;

	vector<string> sections = { "1 - Add", "2 - Edit", "3 - Remove", "4 - Display Information", "0 - Leave\n" };

	for (unsigned int i = 0; i < sections.size(); i++)
	{
		cout << sections.at(i) << endl;
	}

	bool continueInMenu = true;
	string newName;
	do
	{
		int option = filterInput(1, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			//addClient();
			break;
		case 2:
			//editClient();
			break;
		case 3:
			//removeClient();
			break;
		case 4:
			//clientInformation();
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);

}

void staffMenu(Gym &gym)
{
	cout << "What do you wish to do?" << endl;

	vector<string> sections = { "1 - Professor related", "2 - Add ", "3 - Edit", "4 - Remove",  "5 - Display Information", "0 - Leave\n" };

	for (unsigned int i = 0; i < sections.size(); i++)
	{
		cout << sections.at(i) << endl;
	}

	bool continueInMenu = true;
	string newName;
	do
	{
		int option = filterInput(1, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			//professorsMenu();
			break;
		case 2:
			//addStaff();
			break;
		case 3:
			//editStaff();
			break;
		case 4:
			//removeStaff();
			break;
		case 5:
			//staffInformation();
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}
