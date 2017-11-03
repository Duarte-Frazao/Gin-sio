#ifndef STAFF_H_
#define STAFF_H_

#include <string>
#include "Schedule.h"
#include "ErrorClasses.h"




class Staff {
	int id, age;
	int wage;
	bool insideGym;
	Schedule workSchedule;
	static int staffId;
	std::string password;

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
	virtual bool recognizeProf() const;

	/**
		Returns staff's log-in password

		@return Returns staff's password
	*/
	std::string getPassword() const;

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
		Sets staff's password to the one
		passed as the function's parameter

		@param Staff's password
	*/
	void setPassword(std::string pass);

	/**
		Changes staff's location only if the hour of entrance
		is in between staff's working hours
	*/
	void changeLocation();

	/**
		Handles the editing of the staff's information
	*/
	void editStaff();

	/**
		Verifies if password is correct for the staff invoking the function

		@param Staff's password
		@return Returns true if password coincides, false otherwise
	*/
	bool auth(std::string pass);

private:
};

#endif /* STAFF_H_ */
