#pragma once

class Program
{
public:
	Program(int code, int programDays, float programCost);
	~Program();
	int getDays() const;
	float getCost() const;
	int getCode() const;
	void displayProgram() const;

private:
	int code;
	int days;
	float cost;
};

