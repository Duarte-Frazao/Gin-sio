#include "stdafx.h"
#include "Program.h"
#include <iostream>

using namespace std;

Program::Program(int code, int programDays, float programCost): code(code), days(programDays), cost(programCost)
{
}

Program::~Program()
{
}

/**
Returns the number of days a the Program gives

@param
@return Returns the number of days a the Program gives
*/
int Program::getDays() const  { return days; }

/**
Returns the cost of the Program 

@param
@return Returns the cost of the Program 
*/
float Program::getCost() const { return cost; }

/**
Returns the code of the Program

@param
@return Returns the code of the Program
*/
int Program::getCode() const { return code; }

/**
Prints the Program information

@param
@return 
*/
void Program::displayProgram() const
{
	cout << "Program " << code << "\n\n";
	cout << "Monthly price: " << cost << "\n";
	cout << "Number of times allowed to enter the gym: " << days << "\n\n\n";
}

ostream & operator<<(ostream & out, const Program & program)
{
	out << "Program " << program.getCode() << "\n\n";
	out << "Monthly price: " << program.getCost() << "\n";
	out << "Number of times allowed to enter the gym: " << program.getDays() << "\n\n\n";
	return out;
}