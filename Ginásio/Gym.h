/*
* Gym.h
*/

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

#include <conio.h>
using namespace std;


class Client;
class PersonalTrainer;

class Gym {
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
	Gym(string name, vector<Program *> &programs, vector<Client *> &clients, vector<Staff *> &staff, vector<PersonalTrainer *> &profs, Schedule &gymSchedule, int maxNumClients, int maxCapacity, Finance &gymFinance);
	
	/**
	Gym destructor

	@return 
	*/
	~Gym();

	/**
	Get name of the gym

	@return Returns the name of the gym
	*/
	string getName() const;

	/**
	Returns the vector of client pointers of the gym

	@return Returns vector of pointers to clients of the gym
	*/
	vector<Client *> getClients() const;

	/**
	Returns the vector of pointers to staff of the gym

	@return Returns the vector of pointers to staff of the gym
	*/
	vector<Staff *> getStaff() const;

	/**
	Returns the vector of program subscriptions pointers of the gym

	@return Returns the vector of program subscriptions pointers of the gym
	*/
	vector<Program *> getPrograms() const;

	/**
	Returns the Schedule of the gym

	@return Returns the Schedule of the gym
	*/
	Schedule getGymSchedule() const;

	/**
	Returns the max number of clients the gym can sign

	@return Returns the max number of clients the gym can sign
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

	void displayPrograms() const;

	/**
	Sets the vector of clients of the gym

	@param The vector of client pointers of the gym
	*/
	void setClients(vector<Client *>);

	/**
	Sets the vector of staff of the gym

	@param The vector of staff pointers of the gym
	*/
	void setStaff(vector<Staff *>);

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


	void setName(string newName);

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
	bool findStaff(int staffId, Staff* staff_found);

	/**
	Performs the login process for a certain staff's id

	@param Staff's Id to be logged on
	*/
	void login(int staffId);

	/**
	Handles the editing of the staff in the gym
	*/
	void menuStaff();

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

	void gymMenu(Gym &gym);
private:
	string name;
	vector<Client *> clients;
	vector<Staff *> staff;
	vector<PersonalTrainer *> profs;
	Schedule gymSchedule;
	int maxNumClients;
	int maxCapacity;
	Finance gymFinance;
	vector<Program*> programs;
};

#endif /* GYM_H_ */