/*
* PersonalTrainer.cpp
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/
#include <iostream>
#include "stdafx.h"
#include "PersonalTrainer.h"

// PersonalTrainer constructor
PersonalTrainer::PersonalTrainer(int age, int wage, string specializedArea) :
	Staff(age, wage), specializedArea(specializedArea) { /* vector<Client *> ? */
}

// PersonalTrainer destructor
PersonalTrainer::~PersonalTrainer() {

}

#pragma region Gets
/**
	Returns the vector of clients of the personal trainer

	@return Returns vector of pointers to clients of the personal trainer
*/
vector<Client *> PersonalTrainer::getClients() const {
	return clients;
}

/**
	Returns the specialized area of the personal trainer

	@return Returns the specialized area as a string
*/
string PersonalTrainer::getSpecializedArea() const {
	return specializedArea;
}

#pragma endregion

# pragma region Sets

/**
	Sets the working schedule of the personal trainer

	@param The working schedule of the personal trainer
*/
void PersonalTrainer::setSchedule(Schedule workSchedule) {
	Staff::setSchedule(workSchedule);
}

/**
	Sets the clients of the personal trainer

	@param Vector of pointers to clients
*/
void PersonalTrainer::setClients(vector<Client *> clients) {
	this->clients = clients;
}

/**
	Sets the specialized area of the personal trainer

	@param The specialized area of the personal trainer
*/
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

/**
	Handles the editing of the personal trainer's information
*/
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

/**
	Handles the editing of the personal trainer's associated clients
*/
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

			//clients.push_back(new Client(name,program,age,this));
			cout << "Client added successfully to Personal Trainer!\n";
		}
			break;
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
					cout << "Client with id " << id << " erased sucessfully!\n";
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