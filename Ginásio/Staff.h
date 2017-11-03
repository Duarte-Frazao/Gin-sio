#ifndef STAFF_H_
#define STAFF_H_

#include <string>
#include "Schedule.h"

class InvalidValue {
	std::string reason;
public:

	InvalidValue(std::string rz);
	std::string getReason() const;
	friend std::ostream & operator << (std::ostream &out, const InvalidValue &error);
};

class Staff {
	int id, age;
	int wage;
	bool insideGym;
	Schedule workSchedule;
	static int staffId;


public:
	Staff(int age, int wage);
	virtual ~Staff();

	/**
	Returns staff's id

		@return Returns staff's id
	*/
	virtual int getId() const;

	/**
	Returns staff's age

		@return Returns staff's age
	*/
	virtual int getAge() const;

	/**
	Returns staff's wage

		@return Returns staff's wage
	*/
	virtual int getWage() const;

	/**
	Returns staff's location

		@return Returns 1 if insideGym, 0 otherwise
	*/
	bool isInsideGym() const;

	/**
	Sets staff's age

		@param Staff's age
	*/
	void setAge(int age);

	/**
	Sets staff's working schedule

		@param Staff's working schedule
	*/
	void setSchedule(Schedule workSchedule);

	/**
	Sets staff's wage and throws an InvalidWage
		if the wage passed as the parameter is negative

		@param Staff's wage
	*/
	void setWage(int wage);

	/**
	Changes staff's location only if the hour of entrance
		is in between staff's working hours
	*/
	void changeLocation();

	/**
	Handles the editing of the staff's information
	*/
	void editStaff();
};

#endif /* STAFF_H_ */
