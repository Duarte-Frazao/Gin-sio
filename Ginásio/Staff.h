#ifndef STAFF_H_
#define STAFF_H_

#include <string>
#include "Schedule.h"
#include "ErrorClasses.h"

class Gym;

class Staff {
	int id;
	std::string name;
	int age;
	double wage;
	bool insideGym;
	bool wasPaid;
	Schedule workSchedule;
	std::string password;
	static int staffId;

public:
	Staff(int age, double wage);
	Staff(std::string name, int age, double wage, std::string pwd);
	Staff(int id, std::string name, int age, double wage, std::string pwd); //For file initialization
	virtual ~Staff();

	/**
	@brief Increments staff's static Id during file reading
	*/
	void incrementStaffId();

	/**
	@brief Returns staff's id
	@return Returns staff's id
	*/
	virtual int getId() const;

	/**
	@brief Returns staff's name
	@return Returns staff's name
	*/
	virtual std::string getName() const;

	/**
	@brief Returns staff's age
	@return Returns staff's age
	*/
	virtual int getAge() const;

	/**
	@brief Returns staff's wage
	@return Returns staff's wage
	*/
	virtual double getWage() const;
	virtual bool recognizeProf() const;

	/**
	@brief Returns staff's log-in password
	@return Returns staff's password
	*/
	std::string getPassword() const;

	/**
	@brief Returns staff's location
	@return Returns 1 if insideGym, 0 otherwise
	*/
	bool isInsideGym() const;

	/**
	@brief Returns staff's payment situation
	@return Returns 1 if was already paid, 0 otherwise
	*/
	bool getWasPaid() const;

	/**
	@brief Sets staff's name
	@param Staff's name
	*/
	void setName(std::string name);

	/**
	@brief Sets staff's age
	@param Staff's age
	*/
	void setAge(int age);

	/**
	@brief Sets staff's working schedule
	@param Staff's working schedule
	*/
	void setSchedule(Schedule workSchedule);


	/**
	@brief Sets staff's wage
	
	Sets age and throws an InvalidWage if the wage
	passed as the parameter is negative.

	@param Staff's wage
	*/
	void setWage(double wage);

	/**
	@brief Sets staff's password 
	
	Sets staff's password to the one
	passed as the function's parameter.

	@param Staff's password
	*/
	void setPassword(std::string pass);

	/**
	@brief Changes staff's payment situation
	*/
	void changeWasPaid();

	/**
	@brief Changes staff's location 
	
	Changes location only if the hour of entrance
	is in between staff's working hours.
	*/
	void changeLocation();

	/**
	@brief Handles the editing of the staff's information
	*/
	void editStaff(Gym &gym);

	/**
	@brief Verifies if password is correct for the staff invoking the function
	@param Staff's password
	@return Returns true if password coincides, false otherwise
	*/
	bool auth(std::string pass);

	/**
	@brief Overload of operator << for class Staff
	@return ostream
	*/
	friend std::ostream& operator<<(std::ostream& out, const Staff& staff);

	/**
	@brief Displays information about Staff
	@param
	@return
	*/
	virtual void printInfo();
};

#endif /* STAFF_H_ */