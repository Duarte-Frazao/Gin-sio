#pragma once
class Program
{
public:
	Program(int code);
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
	Prints the Program information
	*/
	void displayProgram() const;

private:
	int code;
	int days;
	float cost;
};

