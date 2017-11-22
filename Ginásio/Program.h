#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Gym;

class Program
{
	int code;
	int days;
	float cost;


public:
	Program(int code);
	Program(int code, int days, float cost);
	~Program();

	/**
	Returns the number of days a the Program gives

	@param
	@return Returns the number of days a the Program gives
	*/
	int getDays() const;

	/**
	Returns the cost of the Program

	@param
	@return Returns the cost of the Program
	*/
	float getCost() const;

	/**
	Returns the code of the Program

	@param
	@return Returns the code of the Program
	*/
	int getCode() const;

	/**
	Sets number of program's gym days

	@param number of program's gym days
	*/
	void setDays(int days);

	/**
	Sets cost of program

	@param program's cost
	*/
	void setCost(float cost);

	/**
	Sets program's code

	@param program's code
	*/
	void setCode(int code);

	/**
	Prints the Program information
	*/
	friend std::ostream & operator<<(std::ostream &out, const Program &program);

	/**
	Edits program's information
	*/
	void editProgram(Gym &gym);
};

