#include <iostream>
#include "stdafx.h"
#include "Gym.h"
#include "Staff.h"
using namespace std;

int Staff::staffId = 0;


// Staff constructor
Staff::Staff(int age, int wage) : id(++staffId), age(age), wage(wage), insideGym(false) {}

// Staff destructor
Staff::~Staff() {

}

#pragma region Gets

int Staff::getId() const {
	return id;
}


int Staff::getAge() const {
	return age;
}


int Staff::getWage() const {
	return wage;
}


string Staff::getPassword() const {
	return password;
}


bool Staff::isInsideGym() const {
	return insideGym;
}

#pragma endregion

#pragma region Sets


void Staff::setAge(int age) {
	this->age = age;
}


void Staff::setSchedule(Schedule workSchedule) {
	this->workSchedule = workSchedule;
}

void Staff::setWage(int wage) {
	if (wage < 0) throw InvalidValue("Negative wage inserted!");
	else this->wage = wage;
}


void Staff::setPassword(string pass) {
	password = pass;
}

#pragma endregion

#pragma region Staff authentication 


bool Staff::auth(string pass)
{
	if (password == pass)
		return true;
	return false;
}
#pragma endregion


void Staff::changeLocation() {
	insideGym = !insideGym;
	// TO_DO: verify if hour of entry is in between this staff's schedule
}

# pragma region editStaff
/**
	Shows the menu of options for editing the staff's information
	and returns the option chosen

	@return Returns chosen option for the edit staff menu
*/
int editStaffMenu() {
	
	string options[] = { "1. Edit age", "2. Edit wage", "3. Edit location", "0. Return" };
	for (size_t i = 0; i < 4; i++) {
		cout << options[i] << endl;
	}

	/* insert function to accept option */
	int option;
	cin >> option;

	return option;
}


void Staff::editStaff() {

	int option;
	while ((option = editStaffMenu()) != 0) {
		switch (option) {
		case 1:
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
			break;
		case 2:
			/* edit wage */
			int newWage;
			cout << "Insert wage to modify: ";
			cin >> newWage;
			while (cin.fail() || newWage < 0) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Insert wage to modify: ";
				cin >> newAge;
			}
			setWage(newWage);
			cout << "Staff's wage sucessfully modified!\n";
			break;
		case 3:
			/* edit location */
			changeLocation();
			break;
		default:
			cout << "Unreachable option ...\n";
		}
	}
}

bool Staff::recognizeProf() const
{
	return false;
}


#pragma endregion
