#ifndef PERSONALTRAINER_H_
#define PERSONALTRAINER_H_

#include <vector>
#include <string>
#include <queue>
#include "Staff.h"

class Client;
class Gym;


class PersonalTrainer : public Staff {
	std::vector<Client *> clients;
	std::string specializedArea;

public:
	PersonalTrainer(int age, double wage, std::string specializedArea);
	PersonalTrainer(std::string name, int age, double wage, std::string pwd, std::string specializedArea);
	PersonalTrainer(int id, std::string name, int age, double wage, std::string pwd, std::string specializedArea); //For file initialization

	virtual ~PersonalTrainer();

	/**
	@brief Returns the vector of clients of the personal trainer
	@return Returns vector of pointers to clients of the personal trainer
	*/
	std::vector<Client *> getClients() const;

	/**
	@brief Returns the specialized area of the personal trainer
	@return Returns the specialized area as a string
	*/
	std::string getSpecializedArea() const;

	/**
	@brief Sets the working schedule of the personal trainer
	@param workSchedule The working schedule of the personal trainer
	*/
	void setSchedule(Schedule workSchedule);

	/**
	@brief Adds new client to the personal trainer.
	@param client The client to be added
	*/
	void addClient(Client* client);

	/**
	@brief Sets the clients of the personal trainer
	@param clients Vector of pointers to clients
	*/
	void setClients(std::vector<Client *> clients);

	/**
	@brief Sets the specialized area of the personal trainer
	@param area The specialized area of the personal trainer
	*/
	void setSpecializedArea(std::string area);

	/**
	@brief Handles the editing of the personal trainer's information
	@param gym Gym
	*/
	void editPersonalTrainer(Gym &gym);

	/**
	@brief Handles the editing of the personal trainer's associated clients
	@param gym Gym
	*/
	void editAssociatedClients(Gym &gym);

	/**
	@brief Overload of operator << for derived class Personal Trainer
	@param out ostream
	@param staff Staff
	@return ostream
	*/
	friend std::ostream& operator<<(std::ostream& out, const PersonalTrainer& staff);

	/**
	@brief Displays information about Personal Trainer
	*/
	void printInfo();
};

class CmpPtPointers {
public:
	/**
	@brief Comparison operator for PTQUEUE
	@param p1 First personal trainer
	@param p2 Second personal trainer
	@return Returns the result of the comparison, true or false
	*/
	bool operator()(const PersonalTrainer* p1, const PersonalTrainer* p2) {
		return p1->getClients().size() > p2->getClients().size();
	}
};

#endif /* PERSONALTRAINER_H_ */