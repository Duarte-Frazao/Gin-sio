/*
* Gym.cpp
*/
#include <iostream>
#include "stdafx.h"
#include "Gym.h"


// Gym Constructor
Gym::Gym(string name,vector<Program *> programs, vector<Client *> clients, vector<Staff *> staff, Schedule gymSchedule,
	int maxNumClients, int maxCapacity, Finance gymFinance) :name(name), programs(programs), clients(clients),
	staff(staff), gymSchedule(gymSchedule), maxNumClients(maxNumClients),
	maxCapacity(maxCapacity), gymFinance(gymFinance) {}

// Gym Destructor
Gym::~Gym() {

}

#pragma region Gets 

/**
	Returns the vector of client pointers of the gym

	@return Returns vector of pointers to clients of the gym
*/
string Gym::getName() const { return name; }

vector<Client *> Gym::getClients() const {
	return clients;
}

/**
	Returns the vector of staff pointers of the gym

	@return Returns vector of pointers to staff of the gym
*/
vector<Program *> Gym::getPrograms() const {
	return programs;
}

int Gym::getNumberPrograms() const
{
	return (int)programs.size();
}

vector<Staff *> Gym::getStaff() const {
	return staff;
}

/**
	Returns the gym schedule

	@return Returns the gym schedule
*/
Schedule Gym::getGymSchedule() const {
	return gymSchedule;
}

/**
	Returns the max number of clients of the gym

	@return Returns the max number of clients of the gym
*/
int Gym::getMaxNumClients() const {
	return maxNumClients;
}

/**
	Returns the max capacity of the gym

	@return Returns the max capacity of the gym
*/
int Gym::getMaxCapacity() const {
	return maxCapacity;
}

/**
	Returns the finance of the gym

	@return Returns the finance of the gym
*/
Finance Gym::getGymFinance() const {
	return gymFinance;
}

#pragma endregion

#pragma region Sets

/**
	Sets the vector of clients of the gym

	@param The vector of client pointers of the gym
*/
void Gym::setClients(vector<Client *> clients) {
	this->clients = clients;
}

/**
	Sets the vector of staff of the gym

	@param The vector of staff pointers of the gym
*/
void Gym::setStaff(vector<Staff *> staff) {
	this->staff = staff;
}

/**
	Sets the gym schedule

	@param The gym schedule 
*/
void Gym::setName(string newName)
{
	name = newName;
}

void Gym::setGymSchedule(Schedule gymSchedule) {
	this->gymSchedule = gymSchedule;
}

/**
	Sets the max number of clients of the gym

	@param The max number of clients of the gym
*/
void Gym::setMaxNumClients(int maxNumClients) {
	this->maxNumClients = maxNumClients;
}

/**
	Sets the max capacity of the gym

	@param The max capacity of the gym
*/
void Gym::setMaxCapacity(int maxCapacity) {
	this->maxCapacity = maxCapacity;
}

/**
	Sets the gym finance

	@param The gym finance
*/
void Gym::setGymFinance(Finance gymFinance) {
	this->gymFinance = gymFinance;
}

# pragma endregion

# pragma region staffMenu

/**
	Shows the menu of options for adding or removing staff

	@return Returns the chosen option of the staff's menu
*/
int staffMenu() {

	string options[] = { "1. Add Staff", "2. Remove staff"};
	for (size_t i = 0; i < 3; i++) {
		cout << options[i] << endl;
	}

	/* insert function to accept option */
	int option;
	cin >> option;

	return option;
}

/**
	Handles the editing of the staff in the gym
*/
void Gym::menuStaff() {

	int option;
	while ((option = staffMenu()) != 0) {
		switch (option) {
		case 1:
		{
			/* add staff */
			int age, wage;
			do {
				cout << "Insert new staff's age: ";
				cin >> age;
				cin.ignore();
			} while (age < 0);
			do {
				cout << "Insert new staff's wage: ";
				cin >> wage;
				cin.ignore();
			} while (wage < 0);

			staff.push_back(new Staff(age, wage));
			cout << "Staff added sucessfully!\n";
		}
			break;
		case 2:
		{
			/* remove staff by Id*/
			int id;
			cout << "Insert staff's id to remove: ";
			cin >> id;
			cin.ignore();
			vector<Staff *>::iterator it_staff;
			for (it_staff = staff.begin(); it_staff != staff.end(); it_staff++) {
				if ((*it_staff)->getId() == id) {
					staff.erase(it_staff);
					cout << "Staff with id " << id << " erased sucessfully!\n";
				}
			}
			if (it_staff == staff.end()) {
				cout << "Staff with id " << id << " does not exist!\n";
			}
		}
			break;
		default:
			cout << "Unreachable option ...\n";
		}
	}
}

#pragma endregion

/**
Prints the programs the gym has to offer, as well as the conditions

@param
@return
*/
void Gym::displayPrograms() const
{
	cout << name << " has the following programs to offer\n\n\n";
	for (size_t i = 0; i < programs.size(); i++)
	{
		programs.at(i)->displayProgram();
	}
}