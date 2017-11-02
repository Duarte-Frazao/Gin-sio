/*
* Staff.cpp
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/
#include <iostream>
#include "stdafx.h"
#include "Gym.h"
#include "Staff.h"
using namespace std;

int Staff::staffId = 0;

#pragma region InvalidValue

//InvalidWage constructor
InvalidValue::InvalidValue(string rz) : reason(rz) {}

//getReason
string InvalidValue::getReason() const { return reason; }

//operator << overload
ostream & operator << (ostream &out, const InvalidValue &error) {
	out << "Error registring staff's wage!" << endl;
	out << "Reason: " << error.reason << endl;
	return out;
}

#pragma endregion

// Staff constructor
Staff::Staff(int age, int wage) : id(++staffId), age(age), wage(wage), insideGym(false) {}

// Staff destructor
Staff::~Staff() {

}

#pragma region Gets
/**
	Returns staff's id

	@return Returns staff's id
*/
int Staff::getId() const {
	return id;
}

/**
	Returns staff's age

	@return Returns staff's age
*/
int Staff::getAge() const {
	return age;
}

/**
	Returns staff's wage

	@return Returns staff's wage
*/
int Staff::getWage() const {
	return wage;
}

/**
	Returns staff's log-in password

	@return Returns staff's password
*/
string Staff::getPassword() const {
	return password;
}

/**
	Returns staff's location

	@return Returns 1 if insideGym, 0 otherwise
*/
bool Staff::isInsideGym() const {
	return insideGym;
}

#pragma endregion

#pragma region Sets

/**
	Sets staff's age

	@param Staff's age
*/
void Staff::setAge(int age) {
	this->age = age;
}

/**
	Sets staff's working schedule

	@param Staff's working schedule
*/
void Staff::setSchedule(Schedule workSchedule) {
	this->workSchedule = workSchedule;
}

/**
	Sets staff's wage and throws an InvalidWage
	if the wage passed as the parameter is negative

	@param Staff's wage
*/
void Staff::setWage(int wage) {
	if (wage < 0) throw InvalidValue("Negative wage inserted!");
	else this->wage = wage;
}

/**
	Sets staff's password to the one
	passed as the function's parameter

	@param Staff's password
*/
void Staff::setPassword(string pass) {
	password = pass;
}

#pragma endregion

#pragma region Staff authentication 

/**
	Verifies if password is correct for the staff invoking the function

	@param Staff's password
	@return Returns true if password coincides, false otherwise
*/
bool Staff::auth(string pass)
{
	if (password == pass)
		return true;
	return false;
}
#pragma endregion

/**
	Changes staff's location only if the hour of entrance
	is in between staff's working hours 
*/
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

/**
	Handles the editing of the staff's information
*/
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

#pragma endregion