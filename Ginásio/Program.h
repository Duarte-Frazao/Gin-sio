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
	@brief Returns the number of days a the Program gives
	@return Returns the number of days a the Program gives
	*/
	int getDays() const;

	/**
	@brief Returns the cost of the Program
	@return Returns the cost of the Program
	*/
	float getCost() const;

	/**
	@brief Returns the code of the Program
	@return Returns the code of the Program
	*/
	int getCode() const;

	/**
	@brief Sets number of program's gym days
	@param days Number of program's gym days
	*/
	void setDays(int days);

	/**
	@brief Sets cost of program
	@param cost Program's cost
	*/
	void setCost(float cost);

	/**
	@brief Sets program's code
	@param code Program's code
	*/
	void setCode(int code);

	/**
	@brief Prints the Program information
	@param out ostream
	@param program Program
	*/
	friend std::ostream & operator<<(std::ostream &out, const Program &program);

	/**
	@brief Edits program's information
	@param gym Gym
	*/
	void editProgram(Gym &gym);
};

