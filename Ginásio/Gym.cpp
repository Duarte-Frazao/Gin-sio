#include <iostream>
#include "stdafx.h"
#include "Gym.h"

using namespace std;

Gym::Gym(string name, vector<Program *> programs, vector<Client *> clients,
		vector<Staff *> staff, Schedule gymSchedule, int maxNumClients,
		int maxCapacity, Finance gymFinance) :
		name(name), programs(programs), clients(clients), staff(staff), gymSchedule(
				gymSchedule), maxNumClients(maxNumClients), maxCapacity(
				maxCapacity), gymFinance(gymFinance) {
}


Gym::~Gym() {}


#pragma region Gets 

string Gym::getName() const { return name; }

vector<Client *> Gym::getClients() const {return clients;}

vector<Program *> Gym::getPrograms() const {return programs;}

int Gym::getNumberPrograms() const{return (int)programs.size();}

vector<Staff *> Gym::getStaff() const {return staff;}

Schedule Gym::getGymSchedule() const {return gymSchedule;}

int Gym::getMaxNumClients() const {return maxNumClients;}

int Gym::getMaxCapacity() const {return maxCapacity;}

Finance Gym::getGymFinance() const {return gymFinance;}

#pragma endregion




#pragma region Sets

void Gym::setClients(vector<Client *> clients) {this->clients = clients;}

void Gym::setStaff(vector<Staff *> staff) {	this->staff = staff;}

void Gym::setName(string newName){name = newName;}

void Gym::setGymSchedule(Schedule gymSchedule) {this->gymSchedule = gymSchedule;}

void Gym::setMaxNumClients(int maxNumClients) {this->maxNumClients = maxNumClients;}

void Gym::setMaxCapacity(int maxCapacity) {this->maxCapacity = maxCapacity;}

void Gym::setGymFinance(Finance gymFinance) {this->gymFinance = gymFinance;}

# pragma endregion



#pragma region Add

void Gym::addClient(Client * client) {clients.push_back(client);}

void Gym::addStaff(Staff * staff) {this->staff.push_back(staff);}

void Gym::addProgram(Program* program) {programs.push_back(program);}

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
					cout << "Staff with id " << id << " erased successfully!\n";
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


void Gym::displayPrograms() const
{
	cout << name << " has the following programs to offer\n\n\n";
	for (size_t i = 0; i < programs.size(); i++)
	{
		programs.at(i)->displayProgram();
	}
}
