/*
* Staff.h
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/

#ifndef STAFF_H_
#define STAFF_H_

#include <string>
#include "Schedule.h"
using namespace std;

class InvalidWage {
	string reason;
public:

	InvalidWage(string rz);
	string getReason() const;
	friend ostream & operator << (ostream &out, const InvalidWage &error);
};

class Staff {
public:
	Staff(const int id, const int age, int wage);
	virtual ~Staff();
	virtual int getId() const;
	virtual int getAge() const;
	virtual int getWage() const;
	void setSchedule(Schedule workSchedule);
	void setWage(int wage);
	void changeLocation();
private:
	const int id, age;
	int wage;
	bool insideGym;
	Schedule workSchedule;
};

#endif /* STAFF_H_ */