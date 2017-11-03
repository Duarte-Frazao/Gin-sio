#ifndef GYM_H_
#define GYM_H_

#include "Client.h"
#include "Staff.h"
#include "Finance.h"
#include "Schedule.h"
#include "Program.h"

#include <vector>
#include <string>
#include <iostream>

class Client;
class Program;
class Gym {

	std::string name;
	std::vector<Program*> programs;
	std::vector<Client *> clients;
	std::vector<Staff *> staff;
	Schedule gymSchedule;
	int maxNumClients;
	int maxCapacity;
	Finance gymFinance;

public:
	Gym(std::string name, std::vector<Program *> programs,
			std::vector<Client *> clients, std::vector<Staff *> staff,
			Schedule gymSchedule, int maxNumClients, int maxCapacity,
			Finance gymFinance);
	virtual ~Gym();

	/**
	Returns the vector of client pointers of the gym

	@return Returns vector of pointers to clients of the gym
	*/
	std::string getName() const;

	std::vector<Client *> getClients() const;

	/**
	Returns the vector of staff pointers of the gym

	@return Returns vector of pointers to staff of the gym
	*/
	std::vector<Staff *> getStaff() const;

	std::vector<Program *> getPrograms() const;

	/**
	Returns the gym schedule

	@return Returns the gym schedule
	*/
	Schedule getGymSchedule() const;

	/**
	Returns the max number of clients of the gym

	@return Returns the max number of clients of the gym
	*/
	int getMaxNumClients() const;

	int getNumberPrograms() const;

	/**
	Returns the max capacity of the gym

	@return Returns the max capacity of the gym
	*/
	int getMaxCapacity() const;

	/**
	Returns the finance of the gym

	@return Returns the finance of the gym
	*/
	Finance getGymFinance() const;

	/**
	Sets the vector of clients of the gym

	@param The vector of client pointers of the gym
	*/
	void setClients(std::vector<Client *>);

	/**
	Sets the vector of staff of the gym

	@param The vector of staff pointers of the gym
	*/
	void setStaff(std::vector<Staff *>);

	void setName(std::string newName);

	/**
	Sets the gym schedule

	@param The gym schedule
	*/
	void setGymSchedule(Schedule);

	/**
	Sets the max number of clients of the gym

	@param The max number of clients of the gym
	*/
	void setMaxNumClients(int);

	/**
	Sets the max capacity of the gym

	@param The max capacity of the gym
	*/
	void setMaxCapacity(int);

	/**
	Sets the gym finance

	@param The gym finance
	*/
	void setGymFinance(Finance);


	/**
	Adds a client to the vector

	@param Client pointer
	*/
	void addClient(Client * client);

	/**
	Adds a staff to the vector

	@param Staff pointer
	*/
	void addStaff(Staff * staff);

	/**
	Adds a program to the vector

	@param Program pointer
	 */
	void addProgram(Program* program);



	/**
	Prints the programs the gym has to offer, as well as the conditions
	*/
	void displayPrograms() const;

	/**
	Handles the editing of the staff in the gym
	*/
	void menuStaff();
};

#endif /* GYM_H_ */
