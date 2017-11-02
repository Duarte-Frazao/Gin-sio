/*
* Gym.cpp
*/
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

#pragma endregion

#pragma region Login authentication

/**
	Performs the login process for a certain staff's id

	@param Staff's Id to be logged on
*/
void Gym::login(int staffId) {
	cout << "    Welcome to Go Gym!      \n"
		<< "--- AUTHENTICATION PORTAL ---\n";

	Staff* staff_found;
	bool staffFound = 0;
	do
	{
		string staffName;
		cout << "Login: ";
		getline(cin, staffName);

		if (findStaff(staffId, staff_found))
		{
			staffFound = 1;
			bool access = 0;
			do
			{
				string pass;
				cout << "Password: ";
				char ch = _getch();
				while (ch != 13)
				{
					if (ch == 8)
					{
						if (pass.size() != 0)
						{
							pass.pop_back();
							cout << "\b \b";
						}
					}
					else
					{
						pass.push_back(ch);
						cout << "*";
					}
					ch = _getch();
				}

				if (staff_found->auth(pass))
				{
					cout << "\n\nACCESS GRANTED!\n" << "WELCOME STAFF NUMBER " << staff_found->getId() << "!\n\n";
					access = 1;
				}
				else {
					cout << "\n\nACESS DENIED!\n";
					cout << "Try again: press 0 or Exit: press 1\n" << "--> ";
					int incorrect_option;
					cin >> incorrect_option;
					while (incorrect_option != 0 && incorrect_option != 1) {
						cout << "Enter a correct command ...\n";
						cin >> incorrect_option;
					}
					if (incorrect_option) exit(0);
					cin.ignore();
				}

			} while (!access);
		}
		else
		{
			cout << endl << "STAFF NOT FOUND!" << endl;
			cout << "Try again: press 0 or Exit: press 1\n" << "--> ";
			int incorrect_option2;
			cin >> incorrect_option2;
			while (incorrect_option2 != 0 && incorrect_option2 != 1) {
				cout << "Enter a correct command ...\n";
				cin >> incorrect_option2;
			}
			if (incorrect_option2) exit(0);
			cin.ignore();
		}

	} while (!staffFound);
}

#pragma endregion

#pragma region Search algorithms

/**
	Finds gym's staff with a certain Id

	@param 
	- staffId is the staff's Id
	- staff_found is a pointer to the found staff
	@return Returns true if staff was found, false otherwise
*/
bool Gym::findStaff(int staffId, Staff* staff_found) {
	for (auto staff_pointer : staff)
	{
		if (staff_pointer->getId() == staffId)
		{
			staff_found = staff_pointer;
			return true;
		}
	}
	return false;
}

#pragma endregion

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