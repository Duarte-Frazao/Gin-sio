/*
* Staff.cpp
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/
#include "stdafx.h"
#include "Staff.h"

#pragma region InvalidWage

//InvalidWage constructor
InvalidWage::InvalidWage(string rz) : reason(rz) {}

//getReason
string InvalidWage::getReason() const { return reason; }

//operator << overload
ostream & operator << (ostream &out, const InvalidWage &error) {
	out << "Error registring staff's wage!" << endl;
	out << "Reason: " << error.reason << endl;
	return out;
}

#pragma endregion

// Staff constructor
Staff::Staff(int id, int age, int wage) : id(id), age(age), wage(wage), insideGym(false) {}

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

#pragma endregion

#pragma region Sets

void Staff::setSchedule(Schedule workSchedule) {
	this->workSchedule = workSchedule;
}

void Staff::setWage(int wage) {
	if (wage < 0) throw InvalidWage("Negative wage inserted!");
	else this->wage = wage;
}

#pragma endregion

void Staff::changeLocation() {
	insideGym = !insideGym;
	// verify if hour of entry is in between this staff's schedule
}