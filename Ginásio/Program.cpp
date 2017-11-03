#include "stdafx.h"
#include "Program.h"
#include <iostream>

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


Program::~Program(){}

int Program::getDays() const  { return days; }

float Program::getCost() const { return cost; }

int Program::getCode() const { return code; }

void Program::displayProgram() const{
	cout << "Program " << code << "\n\n";
	cout << "Monthly price: " << cost << "\n";
	cout << "Number of times allowed to enter the gym: " << days << "\n\n\n";

}
