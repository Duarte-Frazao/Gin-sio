#pragma once
using namespace std;

#include <utility>
#include <string>

class Program
{
public:
	Program(int code, int programDays, float programCost);
	~Program();
	int getDays() const;
	float getCost() const;
	int getCode() const;
	void displayProgram() const;
	friend ostream & operator<<(ostream & out, const Program & program);


private:
	int code;
	int days;
	float cost;
};

