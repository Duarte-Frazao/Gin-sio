#include "stdafx.h"
#include "Program.h"
#include "Gym.h"
#include "termcolor.hpp"

using namespace std;

//Functions
int filterInput(int inf, int sup, std::string msg = "Selection: ");

Program::Program(int code) : code(code) {
	switch(code){
	case 1:
		days = 31;
		cost = 10;
		break;

	case 2:
		days = 62;
		cost = 15;
		break;

	//default:
		//throw Invalid Code;
	}
}

Program::Program(int code, int days, float cost) : code(code), days(days), cost(cost){}


Program::~Program(){}

int Program::getDays() const  { return days; }

float Program::getCost() const { return cost; }

int Program::getCode() const { return code; }

void Program::setDays(int days) {
	this->days = days;
}

void Program::setCost(float cost) {
	this->cost = cost;
}

void Program::setCode(int code) {
	this->code = code;
}

ostream & operator<<(ostream &out, const Program &program)
{
	cout << "Program " << program.code << endl;
	cout << "Monthly price: " << program.cost << endl;
	cout << "Number of times allowed to enter the gym: " << program.days << "\n\n";

	return out;
}

/**
Shows the menu of options for editing the program's information
and returns the option chosen

@return Returns chosen option for the edit program menu
*/
int editProgramMenu()
{
	cout << "\nSelect what you want to edit" << endl << endl;

	vector<string> options = { "1. Edit code", "2. Edit days", "3. Edit cost", "0. Return" };

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);
	
	return option;
}


void Program::editProgram(Gym &gym)
{
	bool continueInMenu = true;
	int newProgramCode, newGymDays;
	Program *programFound = NULL;
	float newCost;
	do
	{
		int option = editProgramMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			cout << "What's the program's new code? " << endl;
			cout << "Previously: " << code << endl;
			cout << "->";
			cin >> newProgramCode;
			while (cin.fail() || newProgramCode < 0 || gym.findProgram(newProgramCode, &programFound)) {
				if (cin.fail() || newProgramCode < 0) {
					cout << sign::error << "Insert a valid value! ";
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else cout << sign::error << "Insert a non-existent program code! ";
				cin >> newProgramCode;
			}
			setCode(newProgramCode);
			break;
		case 2:
			cout << "What's the program's new number of gym days? " << endl;
			cout << "Previously: " << days << endl;
			cout << "->";
			cin >> newGymDays;
			while (cin.fail() || newGymDays < 0 || newGymDays > 365) {
				cout << sign::error << "Insert a valid value! ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> newGymDays;
			}
			setDays(newGymDays);
			break;
		case 3:
			cout << "What's the program's new monthly cost? " << endl;
			cout << "Previously: " << cost << endl;
			cout << "->";
			cin >> newCost;
			while (cin.fail() || newCost < 0) {
				cout << sign::error << "Insert a valid value! ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> newCost;
			}
			setCost(newCost);
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}
