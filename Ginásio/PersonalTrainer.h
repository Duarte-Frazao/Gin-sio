#ifndef PERSONALTRAINER_H_
#define PERSONALTRAINER_H_

#include <vector>
#include <string>
#include "Staff.h"
#include "Client.h"
#include "Gym.h"

class Client;
class Gym;

class PersonalTrainer : public Staff {
	std::vector<Client *> clients;
	std::string specializedArea;
	Gym *gym;

public:
	PersonalTrainer(int age, int wage, std::string specializedArea,Gym *gym);
	virtual ~PersonalTrainer();

	/**
	Returns the vector of clients of the personal trainer

	@return Returns vector of pointers to clients of the personal trainer
	*/
	std::vector<Client *> getClients() const;

	/**
	Returns the gym of the personal trainer

	@return Returns the gym of the personal trainer
	*/
	Gym * getGym() const;

	/**
	Returns the specialized area of the personal trainer

	@return Returns the specialized area as a string
	*/
	std::string getSpecializedArea() const;

	/**
	Sets the working schedule of the personal trainer
	@param The working schedule of the personal trainer
	*/
	void setSchedule(Schedule workSchedule);

	/**
	Sets the clients of the personal trainer

	@param Vector of pointers to clients
	*/
	void setClients(std::vector<Client *> clients);

	/**
	Sets the specialized area of the personal trainer

	@param The specialized area of the personal trainer
	*/
	void setSpecializedArea(std::string area);

	/**
	Handles the editing of the personal trainer's information
	*/
	void editPersonalTrainer();

	/**
	Handles the editing of the personal trainer's associated clients
	*/
	void editAssociatedClients();
};

#endif /* PERSONALTRAINER_H_ */
