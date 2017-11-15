#include <iostream>
#include "stdafx.h"
#include "PersonalTrainer.h"

using namespace std;

//Functions
int filterInput(int inf, int sup, std::string msg = "Selection: ");

PersonalTrainer::PersonalTrainer(int age, int wage, string specializedArea) :
	Staff(age, wage), specializedArea(specializedArea) {}

PersonalTrainer::PersonalTrainer(std::string name, int age, int wage, std::string pwd, std::string specializedArea) :
	Staff(name, age, wage, pwd), specializedArea(specializedArea) {}

PersonalTrainer::PersonalTrainer(int id, std::string name, int age, int wage, std::string pwd, std::string specializedArea) :
	Staff(id, name, age, wage, pwd), specializedArea(specializedArea) {

}

PersonalTrainer::~PersonalTrainer() {

}

#pragma region Gets

vector<Client *> PersonalTrainer::getClients() const { return clients; }

string PersonalTrainer::getSpecializedArea() const { return specializedArea; }


#pragma endregion

# pragma region Sets


void PersonalTrainer::setSchedule(Schedule workSchedule) {
	Staff::setSchedule(workSchedule);
}


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
			cout << "PT's specialized area sucessfully modified!\n";
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
	int id, age;
	bool continueInMenu = true;
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
			/* add new client to Personal Trainer */
			cout << "Insert the name of the client to add: ";
			cin.ignore(1000, '\n');
			getline(cin, name);
			cout << "Insert client's age: ";
			cin >> age;
			cin.ignore();

			int program;
			cout << "Insert the subscripted gym program: ";
			cin >> program;


			bool clientExist = false;
			//Search if the client already exists
			for (auto pClient : gym.getClients()) {
				if (pClient->getName() == name && pClient->getAge() == age && pClient->getProgram()->getCode() == program) {
					pClient->setPT(this);
					clients.push_back(pClient);
					clientExist = true;
					break;
				}
			}

			//If the client is new at the gym
			if (!clientExist) {
				Client * newClient = new Client(name, new Program(program), age, this);
				gym.addClient(newClient); //Also add the client to the gym's clients vector
			}

			cout << "Client added successfully to Personal Trainer!\n";
			break;
		}
		case 2:
		{
			/* remove client associated with Personal Trainer, by Id */
			cout << "Insert the id of the client to remove: ";
			cin >> id;
			cin.ignore();
			vector<Client *>::iterator it_clients;
			for (it_clients = clients.begin(); it_clients != clients.end(); it_clients++) {
				if ((*it_clients)->getId() == id) {
					clients.erase(it_clients);
					cout << "Client with id " << id << " erased successfully!\n";
				}
				if (it_clients == clients.end()) {
					cout << "Client with id " << id << " does not exist!\n";
				}
			}
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
	for (auto client : pt.getClients())
		out << *client << endl;
	return out;
}