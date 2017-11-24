#include <iostream>
#include "stdafx.h"
#include "Staff.h"
#include "colorWin.h"
#include "Input.h"
using namespace std;

//Functions
int filterInput(int inf, int sup, std::string msg = "Selection: ");

int Staff::staffId = 0;

// Staff constructors
Staff::Staff(int age, double wage) : id(++staffId), age(age), wage(wage), insideGym(false), wasPaid(false) {}

Staff::Staff(std::string name, int age, double wage, std::string pwd) : id(++staffId), name(name), age(age),
wage(wage), password(pwd), insideGym(false), wasPaid(false) {}

Staff::Staff(int id, std::string name, int age, double wage, std::string pwd) : id(id), name(name), age(age),
wage(wage), password(pwd), insideGym(false), wasPaid(false) {}

// Staff destructor
Staff::~Staff() {

}

void Staff::incrementStaffId() {
	staffId++;
}

#pragma region Gets

int Staff::getId() const {
	return id;
}

string Staff::getName() const {
	return name;
}
int Staff::getAge() const {
	return age;
}


double Staff::getWage() const {
	return wage;
}


string Staff::getPassword() const {
	return password;
}


bool Staff::isInsideGym() const {
	return insideGym;
}

bool Staff::getWasPaid() const {
	return wasPaid;
}

#pragma endregion

#pragma region Sets

void Staff::setAge(int age) {
	this->age = age;
}

void Staff::setSchedule(Schedule workSchedule) {
	this->workSchedule = workSchedule;
}

void Staff::setWage(double wage) {
	try {
		if (wage < 0) throw InvalidValue("Negative wage inserted!");
		else this->wage = wage;
	}
	catch (InvalidValue &e) {
		cout << e.getReason() << endl;
	}
}

void Staff::setPassword(string pass) {
	password = pass;
}

void Staff::setName(string name) {
	this->name = name;
}

void Staff::changeWasPaid() {
	wasPaid = !wasPaid;
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

#pragma endregion

# pragma region editStaff
/**
Shows the menu of options for editing the staff's information
and returns the option chosen

@return Returns chosen option for the edit staff menu
*/
int editStaffMenu()
{
	cout << "\nSelect what you want to edit" << endl;

	vector<string> options = { "1. Edit name", "2. Edit age", "3. Edit wage", "4. Edit location", "5. Show information", "0. Return" };

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}

void Staff::editStaff(Gym &gym) {

	bool continueInMenu = true;
	string newName;
	int newAge;
	double newWage;
	do
	{
		int option = editStaffMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			cout << "What's the staff's new name?\n" << endl;
			cout << "Previously: " << name << endl;
			cout << "->";
			getline(cin, newName);
			setName(newName);
			cout << sign::success << "Staff's name sucessfully modified!\n";
			break;
		case 2:
			cout << "What's the staff's new age?\n";
			cout << "Previously: " << age << endl;
			getInput(newAge, "->");
			setAge(newAge);
			cout << sign::success << "Staff's age sucessfully modified!\n";
			break;
		case 3:
			cout << "What's the staff's new wage?\n";
			cout << "Previously: " << wage << endl;
			getInput(newWage, "->");
			setWage(newWage);
			cout << sign::success << "Staff's wage sucessfully modified!\n";
			break;
		case 4:
			changeLocation();
			cout << "Staff's location sucessfully modified!\n";
			break;
		case 5:
			cout << *this;
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

#pragma endregion

bool Staff::recognizeProf() const
{
	return false;
}

void Staff::printInfo()
{
	cout << *this;
}

ostream & operator<<(std::ostream & out, const Staff & staff)
{
	out << "\n---------- Staff Information ----------" << endl << endl;
	out << "Staff ID " << staff.id << " information:\n";
	out << "Name: " << staff.name << endl;
	out << "Age: " << staff.age << endl;
	out << "Wage: " << staff.wage << endl;
	out << "Payment status: ";
	if (staff.wasPaid) out << "PAID\n";
	else out << "NOT PAID\n";
	out << "Location: ";
	if (staff.insideGym) out << "INSIDE GYM\n";
	else out << "OUTSIDE GYM\n";
	return out;
}
