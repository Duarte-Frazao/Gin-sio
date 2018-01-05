#include <iostream>
#include "stdafx.h"
#include "PersonalTrainer.h"
#include "colorWin.h"
#include "Input.h"

using namespace std;

//Functions
int filterInput(int inf, int sup, std::string msg = "Selection: ");
void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found);

PersonalTrainer::PersonalTrainer(int age, double wage, string specializedArea) :
	Staff(age, wage), specializedArea(specializedArea) {}

PersonalTrainer::PersonalTrainer(std::string name, int age, double wage, std::string pwd, std::string specializedArea) :
	Staff(name, age, wage, pwd), specializedArea(specializedArea) {}

PersonalTrainer::PersonalTrainer(int id, std::string name, int age, double wage, std::string pwd, std::string specializedArea) :
	Staff(id, name, age, wage, pwd), specializedArea(specializedArea) {

}

PersonalTrainer::~PersonalTrainer() {

}

#pragma region Gets

vector<Client *> PersonalTrainer::getClients() const { return clients; }

string PersonalTrainer::getSpecializedArea() const { return specializedArea; }


#pragma endregion

# pragma region Sets


void PersonalTrainer::setClients(vector<Client *> clients) {
	this->clients = clients;
}


void PersonalTrainer::setSpecializedArea(string area) {
	specializedArea = area;
}

#pragma endregion

#pragma region editPersonalTrainer

/**
Shows the menu of options for editing the personal trainer
and returns the option chosen

@return Returns the chosen option of the personal trainer's edit menu
*/
int editPersonalTrainerMenu() {

	cout << "\nSelect what you want to edit" << endl;

	vector<string> options = { "1. Edit specialized area", "2. Edit associated clients", "3. Show information", "0. Return" };

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}

void PersonalTrainer::editPersonalTrainer(Gym &gym) {

	bool continueInMenu = true;
	string newSpecializedArea;
	do
	{
		int option = editPersonalTrainerMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			cout << "What's the PT's new specialized area? " << endl;
			cout << "Previously: " << specializedArea << endl;
			cout << "->";
			cin.ignore(1000, '\n');
			getline(cin, newSpecializedArea);
			setSpecializedArea(newSpecializedArea);
			cout << sign::success <<"PT's specialized area sucessfully modified!\n";
			break;
		case 2:
			editAssociatedClients(gym);
			break;
		case 3:
			cout << *this;
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

/**
Shows the menu of options for editing the personal trainer's
associated clients and returns the option chosen

@return Returns the chosen option of the personal trainer's
associated clients' edit menu
*/
int editAssociatedClientsMenu() 
{
	cout << "\nSelect what you want to edit" << endl;

	vector<string> options = { "1. Add client", "2. Remove client", "0. Return" };
	
	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}

void PersonalTrainer::editAssociatedClients(Gym &gym) {

	string name;
	int age;
	bool continueInMenu = true;
	Client *clientToAdd = NULL;
	Client *clientToErase = NULL;
	Program *programFound = NULL;
	int optionClient;
	int optionProgram;
	do
	{
		int option = editAssociatedClientsMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
		{
			string answer_str;
			char answer;

			cin.ignore();
			cout << sign::question << "Willing to insert existent client (y/n)? ";
			getline(cin, answer_str);
			answer = tolower(answer_str.at(0));
			while ((answer != 'y' && answer != 'n') || answer_str.length() > 1) {
				cout << sign::error << "Please insert a valid input! ";
				getline(cin, answer_str);
				answer = tolower(answer_str.at(0));
			}
			cout << endl;

			if (answer == 'y') {
				bool alreadyExists;
				do {
					alreadyExists = false;
					inputClientIdObj(optionClient, gym, &clientToAdd);
					for (auto client : clients) {
						if (client->getId() == clientToAdd->getId()) {
							alreadyExists = true;
							cout << sign::error << "Client already exists related to this personal trainer!\n\n";
						}
					}
				} while (alreadyExists);
				cout << endl;

				inputProgramIdObj(optionProgram, gym, &programFound);
				clientToAdd->setPT(this);
				clients.push_back(clientToAdd);
			}
			else {
				/* add new client to Personal Trainer */
				cout << "Insert the name of the client to add: ";
				getline(cin, name);
				cout << "Insert client's age: ";
				getInput(age);

				cout << endl << endl;
				inputProgramIdObj(optionProgram, gym, &programFound);

				//If the client is new at the gym
				Client * newClient = new Client(name, new Program(optionProgram), age, this);
				gym.addClient(newClient); //Also add the client to the gym's clients vector
				clients.push_back(newClient);
			}

			cout << endl << sign::success << "Client added successfully to Personal Trainer!\n";
			break;
		}
		case 2:
		{
			if (gym.getClients().empty()) {
				cerr << "There are no clients in the gym" << std::endl;
				return;
			}

			cout << "----------ID Selection----------" << endl;
			bool badInput = false;
			for (auto client : clients) {
				cout << setw(10) << left << client->getName() << " ID: " << client->getId() << endl;
			}

			cout << endl << sign::question << "Insert client's ID: ";
			do
			{
				if (badInput)
				{
					cout << sign::error << "Insert a valid ID" << endl;
					for (auto client : clients)
						cout << setw(10) << left << client->getName() << " ID: " << client->getId() << endl;
				}
				cin >> optionClient;
				badInput = true;

			} while (!gym.findClient(optionClient, &clientToErase));

			vector<Client *>::iterator it_clients;
			for (it_clients = clients.begin(); it_clients != clients.end(); it_clients++) {
				if ((*it_clients)->getId() == clientToErase->getId()) {
					clients.erase(it_clients);
					cout << sign::success << "Client with id " << clientToErase->getId() << " erased successfully!\n";
					return;
				}
			}
			cout << sign::error << "Client with id " << clientToErase->getId() << " does not exist!\n";
			break;
		}
		default:
			cout << "Algum erro";
			break;
		}

	} while (continueInMenu);
}

#pragma endregion

bool PersonalTrainer::recognizeProf() const
{
	return true;
}

void PersonalTrainer::printInfo() 
{
	cout << *this;
}

ostream& operator<<(ostream& out, const PersonalTrainer& pt) {
	out << static_cast<const Staff &>(pt);
	out << "Specialized area: " << pt.specializedArea << endl;
	out << "Clients by whom it is responsible: ";
	if (pt.getClients().size() == 0) out << "NONE" << endl;
	cout << endl;
	for (auto client : pt.getClients())
		out << "-> ID: " << client->getId() << " | Name: " << client->getName() << endl;
	return out;
}
