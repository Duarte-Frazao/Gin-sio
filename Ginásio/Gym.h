#ifndef GYM_H_
#define GYM_H_

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include "Program.h"
#include "Client.h"
#include "PersonalTrainer.h"
#include "Finance.h"
#include "Schedule.h"
#include <unordered_set>

typedef std::priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> PTQUEUE;


class Gym {
	
	std::string name;
	std::vector<Program*> programs;
	std::vector<Client *> clients;
	std::vector<Staff *> staff;
	PTQUEUE profs;
	Schedule gymSchedule;
	int maxNumClients;
	int maxCapacity;
	Finance gymFinance;


public:
	/**
	@brief Gym Constructor

	@param name Name of the gym
	@param programs Vector of pointers to program subscriptions
	@param clients Vector of pointers to clients of the gym
	@param staff Vector of pointers to gym's staff
	@param profs Priority queue of pointers to gym's profs

	@param schedule Schedule of the gym
	@param maxNumClients Max number of clients subscribed to the gym
	@param maxCapacity Max number of people inside the gym
	@param gymFinance Finances of the gym
	@return
	*/
	Gym(std::string name, std::vector<Program *> &programs,
		std::vector<Client *> &clients, std::vector<Staff *> &staff,
		PTQUEUE &profs,
		Schedule &gymSchedule, int maxNumClients, int maxCapacity, Finance &gymFinance);


	Gym(std::string name, std::vector<Program *> &programs, Schedule &gymSchedule,
		int maxNumClients, int maxCapacity, Finance &gymFinance);

	/**
	@brief Gym destructor
	*/
	~Gym();


	/**
	@brief Get name of the gym
	@return Returns the name of the gym
	*/
	std::string getName() const;

	/**
	@brief Returns the vector of client pointers of the gym
	@return Returns vector of pointers to clients of the gym
	*/
	std::vector<Client *> getClients() const;

	/**
	@brief Returns the vector of staff pointers of the gym
	@return Returns vector of pointers to staff of the gym
	*/
	std::vector<Staff *> getStaff() const;

	/**
	@brief Returns the priority queue of pointers to personal trainers of the gym
	@return Returns priority queue of pointers to personal trainers of the gym
	*/
	PTQUEUE getPT() const;

	/**
	@brief Returns vector of pointers to programs of the gym
	@return Returns vector of pointers to programs of the gym
	*/
	std::vector<Program *> getPrograms() const;

	/**
	@brief Returns the gym schedule
	@return Returns the gym schedule
	*/
	Schedule getGymSchedule() const;


	/**
	@brief Returns the max number of clients of the gym
	@return Returns the max number of clients of the gym
	*/
	int getMaxNumClients() const;


	/**
	@brief Returns the number of program subscriptions the gym offers
	@return Returns the number of program subscriptions the gym offers
	*/
	int getNumberPrograms() const;

	/**
	@brief Returns the max capacity of the gym
	@return Returns the max capacity of the gym
	*/
	int getMaxCapacity() const;

	/**
	@brief Returns the finance of the gym
	@return Returns the finance of the gym
	*/
	Finance getGymFinance() const;

	/**
	@brief Sets the vector of clients of the gym
	@param The vector of client pointers of the gym
	*/
	void setClients(std::vector<Client *>);

	/**
	@brief Sets the vector of staff of the gym
	@param The vector of staff pointers of the gym
	*/
	void setStaff(std::vector<Staff *>);

	/**
	@brief Sets the priority queue of personal trainers
	@param Priority queue of personal trainers
	*/
	void setPq(PTQUEUE pq);

	/**
	@brief Sets the gym's new name
	@param newName Gym's new name
	*/
	void setName(std::string newName);

	/**
	@brief Sets the gym schedule
	@param The gym schedule
	*/
	void setGymSchedule(Schedule);

	/**
	@brief Sets the max number of clients of the gym
	@param The max number of clients of the gym
	*/
	void setMaxNumClients(int);

	/**
	@brief Sets the max capacity of the gym
	@param The max capacity of the gym
	*/
	void setMaxCapacity(int);

	/**
	@brief Sets the gym finance
	@param The gym finance
	*/
	void setGymFinance(Finance);


	/**
	@brief Adds a client to the vector
	@param Client pointer
	*/
	void addClient(Client * client);

	/**
	@brief Adds a staff to the vector
	@param Staff pointer
	*/
	void addStaff(Staff * staff);

	/**
	@brief Adds a program to the vector
	@param Program pointer
	*/
	void addProgram(Program* program);

	/**
	@brief Prints the programs the gym has to offer, as well as the conditions
	*/
	void displayPrograms() const;

	/**
	@brief Returns the gym's program subscription that has the id code
	@param code Program subscription id code
	@return Returns the gym's program subscription that has the id code
	*/
	Program* codeToProgram(int code);

	/**
	@brief Finds gym's staff with a certain Id
	@param staffId Staff's Id
	@param staff_found Pointer to the found staff
	@return Returns true if staff was found, false otherwise
	*/
	bool findStaff(int staffId, Staff** staff_found);

	/**
	@brief Finds gym's client with a certain Id
	@param clientId Client's Id
	@param client_found Pointer to the found client
	@return Returns true if client was found, false otherwise
	*/
	bool findClient(int clientId, Client** client_found);

	/**
	@brief Performs the login process for a certain staff
	*/
	void login();

	/**
	@brief Changes gym's capacity
	*/
	void changeCapacity();

	/**
	@brief Changes gym's max number of clients
	*/
	void changeMaxNumClients();

	/**
	@brief Adds a client to the gym
	*/
	void addClient();

	/**
	@brief Prints the programs the gym has to offer, as well as the conditions
	*/
	void displayProgramOptions();

	/**
	@brief Removes a client
	*/
	void removeClient();

	/**
	@brief Adds a staff to the gym
	*/
	void addStaff();

	/**
	@brief Removes a staff from the gym
	*/
	void removeStaff();

	/**
	@brief Adds a personal trainer to the gym
	*/
	void addPersonalTrainer();

	/**
	@brief Removes a personal trainer from the gym
	*/
	void removePersonalTrainer();

	/**
	@brief Pops personal trainer from priority queue
	*/
	void popPqElem();

	/**
	@brief Adds a program to the gym
	*/
	void addProgram();

	/**
	@brief Removes a program from the gym
	*/
	void removeProgram();

	/**
	@brief Prints the gym's clients ids
	*/
	void displayClientsIds();

	/**
	@brief Prints the gym's staff ids
	*/
	void displayStaffIds() const;

	/**
	@brief Prints the gym's personal trainer's ids
	*/
	void displayProfsIds() const;

	/**
	@brief Overload of operator << for class Gym
	@return ostream
	*/
	friend std::ostream & operator<<(std::ostream & out, const Gym &gym);

	/**
	@brief Finds gym's program with a certain Id
	@param programId Id of program to be searched 
	@param program_found Pointer to return the program found
	@return Returns true if found, false otherwise
	*/
	bool findProgram(int programId, Program** program_found);

	/**
	@brief Finds gym's personal trainer with a certain Id
	@param profId Id of personal trainer to be searched
	@param prof_found Pointer to return the personal trainer found
	@return Returns true if found, false otherwise
	*/
	bool findProf(int profId, Staff** prof_found);

	/**
	@brief Deposits amount to gym's account
	*/
	void depositAmount();

	/**
	@brief Makes payments from the gym's account
	*/
	void makePayments();
};

#endif /* GYM_H_ */
