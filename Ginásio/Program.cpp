#include "stdafx.h"
#include "Program.h"

using namespace std;

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


ostream & operator<<(ostream &out, const Program &program)
{
	cout << "Program " << program.code << endl;
	cout << "Monthly price: " << program.cost << endl;
	cout << "Number of times allowed to enter the gym: " << program.days << "\n\n";

	return out;
}


void Program::editProgram(Gym &gym)
{

}
