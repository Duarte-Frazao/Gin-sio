#include "stdafx.h"
#include "Gym.h"
#include "Client.h"
#include <string>
#include <iostream>
#include <vector>


using namespace std;

void mainMenu(Gym &gym);
void gymMenu(Gym &gym);
void clientMenu(Gym &gym);
void staffMenu(Gym &gym);
void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);
void inputClientId(int &optionClient, Gym &gym);
void intervalFuntion();
int filterInput(int inf, int sup,std::string msg = "Selection: ");
void subscriptionsMenu(Gym &gym);


void mainMenu(Gym &gym)
{

	bool continueInMenu = true;
	string newName;
	do
	{
		cout << "What do you wish to do?" << endl;
		vector<string> sections = { "1 - Gym related", "2 - Client related", "3 - Staff related", "0 - Leave\n" };
		for (unsigned int i = 0; i < sections.size(); i++)
		{
			cout << sections.at(i) << endl;
		}

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



	bool continueInMenu = true;
	string newName;
	do
	{

		cout << "What do you wish to do?" << endl;

		vector<string> sections = { "1 - Finances", "2 - Change Schedule", "3 - Change capacity", "4 - Manage subscriptions", "5 - Display Information",  "0 - Leave\n" };

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
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

	bool continueInMenu = true;
	string newName;
	do
	{
		cout << "What do you wish to do?" << endl;

		vector<string> sections = { "1 - Add", "2 - Edit", "3 - Remove", "4 - Display Information", "0 - Leave\n" };

		for (unsigned int i = 0; i < sections.size(); i++)
		{
			cout << sections.at(i) << endl;
		}
		int optionClient;
		Client *clientToUse = NULL;
		int option = filterInput(0, sections.size());
		bool badInput = false;
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
			gym.removeClient(gym);
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
	std::cout << "What do you wish to do?" << std::endl;

	std::vector<std::string> sections = { "1 - Professor related", "2 - Add ", "3 - Edit", "4 - Remove",  "5 - Display Information", "0 - Leave\n" };

	for (unsigned int i = 0; i < sections.size(); i++)
	{
		std::cout << sections.at(i) << std::endl;
	}

	bool continueInMenu = true;
	std::string newName;
	do
	{
		int option = filterInput(0, sections.size());
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
			std::cout << "Algum erro";
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

	string temp;
	cout << "Enter 'h' if you don't know the ID, anything else to proceed: ";
	cin.ignore(100, '\n');
	getline(cin, temp);
	cout << endl;
	
	if (temp == "h" || temp == "H" || temp == "help" || temp == "Help" || temp == "HELP")
	{
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
	}

void inputClientIdObj(int &optionClient,Gym &gym, Client** client_found)
{
	if(gym.getClients().empty()){
		cerr << "There are no clients in the gym" << std::endl;
		return;
	}

	cout << "----------ID Selection----------" << endl ;
	bool badInput = false;
	displayIdHelp(gym, 0);

	cout << endl << "Insira o id do cliente: ";
	do
	{
		if (badInput)
		{
			cout << "Insira um id valido" << endl;
			displayIdHelp(gym, 0);
		}
		cin >> optionClient;
		badInput = true;
	} while (!gym.findClient(optionClient, client_found));
}



//To-do ver se o id do programa corresponde ao id que o user insere
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found)
{
	cout << "----------ID Selection----------" << endl;
	bool badInput = false;
	displayIdHelp(gym, 1);
	cout << endl << "Insira o id do programa a alterar: ";
	do
	{
		if (badInput)
		{
			cout << "Insira um id valido" << endl;
			displayIdHelp(gym, 1);
		}
		cin >> optionProgram;
		badInput = true;
	} while (!gym.findProgram(optionProgram, program_found));
}



void inputClientId(int &optionClient, Gym &gym)
{
	Client** client_found = NULL;
	bool badInput = false;
	cout << "Insira o id do cliente: " << endl;
	do
	{
		if (badInput)
		{
			cout << "Insira um id valido" << endl;
			displayIdHelp(gym, 0);
		}
		cin >> optionClient;
		badInput = true;
	} while (!gym.findClient(optionClient, client_found));
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


void subscriptionsMenu(Gym &gym)
{

	bool continueInMenu = true;
	string newName;
	do
	{
		cout << "What do you wish to do?" << endl;

		vector<string> sections = { "1 - Add", "2 - Edit", "3 - Remove", "4 - Display Information", "0 - Leave\n" };

		for (unsigned int i = 0; i < sections.size(); i++)
		{
			cout << sections.at(i) << endl;
		}
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
			gym.removeClient(gym);
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

