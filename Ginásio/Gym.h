#ifndef GYM_H_
#define GYM_H_

#include "Client.h"
#include "Staff.h"
#include "Finance.h"
#include "Schedule.h"
#include "Program.h"
#include <string>
#include <vector>
#include <iostream>
#include "PersonalTrainer.h"

class Client;
class PersonalTrainer;

class Gym {

	std::string name;
	std::vector<Program*> programs;
	std::vector<Client *> clients;
	std::	vector<Staff *> staff;
	std::vector<PersonalTrainer *> profs;
	Schedule gymSchedule;
	int maxNumClients;
	int maxCapacity;
	Finance gymFinance;


public:
	/**
	Gym Constructor
	@param name Name of the gym
	@param programs Vector of pointers to program subscriptions
	@param clients Vector of pointers to clients of the gym
	@param staff Vector of pointers to gym's staff
	@param profs Vector of pointers to gym's profs
	@param profs Vector of pointers to gym's profs

	@param schedule Schedule of the gym
	@param maxNumClients Max number of clients subscribed to the gym
	@param maxCapacity Max number of people inside the gym
	@param gymFinance Finances of the gym
	@return
	*/
	Gym(std::string name, std::vector<Program *> &programs,
			std::vector<Client *> &clients, std::vector<Staff *> &staff,
			std::vector<PersonalTrainer *> &profs, Schedule &gymSchedule,
			int maxNumClients, int maxCapacity, Finance &gymFinance);
	
	
	Gym(std::string name, std::vector<Program *> &programs, Schedule &gymSchedule,
			int maxNumClients, int maxCapacity, Finance &gymFinance);

	/**
	Gym destructor

	@return 
	*/
	~Gym();



	/**
	Get name of the gym

	@return Returns the name of the gym
	*/
	std::string getName() const;
	
	/**
	Returns the vector of client pointers of the gym

	@return Returns vector of pointers to clients of the gym
	*/
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


	/**
	Returns the number of program subscriptions the gym offers

	@return Returns the number of program subscriptions the gym offers
	*/
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

	/**
	Returns the gym's program subscription that has the id code

	@param	code Program subscription id code
	@return Returns the gym's program subscription that has the id code
	*/
	Program* codeToProgram(int code);

	/**
	Finds gym's staff with a certain Id
	@param
	- staffId is the staff's Id
	- staff_found is a pointer to the found staff
	@return Returns true if staff was found, false otherwise
	*/
	bool findStaff(int staffId, Staff** staff_found);

	/**
	Finds gym's client with a certain Id
	@param
	- clientId is the client's Id
	- client_found is a pointer to the found client
	@return Returns true if client was found, false otherwise
	*/
	bool findClient(int clientId, Client** client_found);

	/**
	Performs the login process for a certain staff
	*/
	void login();


	/**
	Adds a client to the gym
	*/
	void addClient();


	/**
	Prints the programs the gym has to offer, as well as the conditions

	@param
	@return
	*/
	void displayProgramOptions();

	/**
	Removes a client
	*/
	void removeClient();

	/**
	Handles the editing of the Client in the gym
	*/
	void menuClient();

};

#endif /* GYM_H_ */
