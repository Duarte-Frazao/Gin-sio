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
		Client *clientToEdit;
		int option = filterInput(1, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			gym.addClient();
			break;
		case 2:
			cout << "Insira o id do cliente a alterar" << endl;
			do
			{
				cin >> optionClient;
			} while (!gym.findClient(optionClient, clientToEdit));
			clientToEdit->editClient();
			break;
		case 3:
			gym.removeClient();
			break;
		case 4:
			cout << "Insira o id do cliente" << endl;
			do
			{
				cin >> optionClient;
			} while (!gym.findClient(optionClient, clientToEdit));
			clientToEdit->informationClient();
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
			std::cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

