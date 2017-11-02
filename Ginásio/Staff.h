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

class InvalidValue {
	string reason;
public:

	InvalidValue(string rz);
	string getReason() const;
	friend ostream & operator << (ostream &out, const InvalidValue &error);
};

class Staff {
public:
	Staff(int age, int wage);
	virtual ~Staff();
	virtual int getId() const;
	virtual int getAge() const;
	virtual int getWage() const;
	string getPassword() const;
	bool isInsideGym() const;
	void setAge(int age);
	void setSchedule(Schedule workSchedule);
	void setWage(int wage);
	void setPassword(string pass);
	void changeLocation();
	void editStaff();
	bool auth(string pass);
private:
	int id, age;
	int wage;
	bool insideGym;
	Schedule workSchedule;
	static int staffId;
	string password;
};

#endif /* STAFF_H_ */