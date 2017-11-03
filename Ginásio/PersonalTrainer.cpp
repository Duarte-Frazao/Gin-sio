#include <iostream>
#include "stdafx.h"
#include "PersonalTrainer.h"

using namespace std;

PersonalTrainer::PersonalTrainer(int age, int wage, string specializedArea, Gym *gym) :
	Staff(age, wage), specializedArea(specializedArea) ,gym(gym){
}

PersonalTrainer::~PersonalTrainer() {

}

#pragma region Gets

vector<Client *> PersonalTrainer::getClients() const {return clients;}

string PersonalTrainer::getSpecializedArea() const {return specializedArea;}

Gym * PersonalTrainer::getGym() const{return gym;}

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

	string options[] = { "1. Edit age", "2. Edit wage", "3. Edit location", 
		"4. Edit specialized area", "5. Edit associated clients", "0. Return" };
	for (size_t i = 0; i < 6; i++) {
		cout << options[i] << endl;
	}

	/* insert function to accept option */
	int option;
	cin >> option;

	return option;
}

void PersonalTrainer::editPersonalTrainer() {

	int option;
	while ((option = editPersonalTrainerMenu()) != 0) {
		switch (option) {
		case 1:
		{
			/* edit age */
			int newAge;
			cout << "Insert age to modify: ";
			cin >> newAge;
			while (cin.fail() || newAge < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Insert age to modify: ";
				cin >> newAge;
			}
			setAge(newAge);
			cout << "Staff's age sucessfully modified!\n";
		}
			break;
		case 2:
		{
			/* edit wage */
			int newWage;
			cout << "Insert wage to modify: ";
			cin >> newWage;
			while (cin.fail() || newWage < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Insert wage to modify: ";
				cin >> newWage;
			}
			setWage(newWage);
			cout << "Staff's wage sucessfully modified!\n";
		}
			break;
		case 3:
			/* edit location */
			changeLocation();
			break;
		case 4:
		{
			/* edit specialized area */
			string area;
			getline(cin, area);
			setSpecializedArea(area);
			cout << "Specialized area modified successfully!\n";
			break;
		}
		case 5:
		{
			/* add or remove clients to personal trainer */
			editAssociatedClients();
			break;
		}
		default:
			cout << "Option unreachable ...\n";
		}
	}
}

/**
Shows the menu of options for editing the personal trainer's
	associated clients and returns the option chosen

	@return Returns the chosen option of the personal trainer's 
	associated clients' edit menu
*/
int editAssociatedClientsMenu() {

	string options[] = { "1. Add client", "2. Remove client", "0. Return" };
	for (size_t i = 0; i < 3; i++) {
		cout << options[i] << endl;
	}

	/* insert function to accept option */
	int option;
	cin >> option;

	return option;
}

void PersonalTrainer::editAssociatedClients() {

	int option;
	while ((option = editAssociatedClientsMenu()) != 0) {
		switch (option) {
		case 1:
		{
			/* add new client to Personal Trainer */
			string name;
			cout << "Insert the name of the client to add: ";
			getline(cin, name);
			int age;
			cout << "Insert client's age: ";
			cin >> age;
			cin.ignore();

			int program;
			cout << "Insert the subscripted gym program: ";
			cin >> program;


			bool clientExist = false;

			//Search if the client already exists
			for(auto pClient : this->getGym()->getClients()){
				if(pClient->getName() == name && pClient->getAge() == age && pClient->getProgram()->getCode() == program){
					pClient->setPT(this);
					clientExist = true;
					break;
				}
			}

			//If the client is new at the gym
			if (!clientExist) {
				Client * newClient = new Client(name, new Program(program), age, this->getGym(), this);
				getGym()->addClient(newClient); //Also add the client to the gym's clients vector
			}

			cout << "Client added successfully to Personal Trainer!\n";
			break;

		}


		case 2:
		{
			/* remove client associated with Personal Trainer, by Id */
			int id;
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
			cout << "Unreachable option ...\n";
			break;
		}
	}
}

#pragma endregion

bool PersonalTrainer::recognizeProf() const
{
	return true;
}

#pragma endregion
