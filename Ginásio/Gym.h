/*
* Gym.h
*/
#include <vector>
#include "Client.h"
#include "Staff.h"
#include "Finance.h"
#include "Schedule.h"
using namespace std;

#ifndef GYM_H_
#define GYM_H_

class Gym {
public:
	Gym(vector<Client *> clients, vector<Staff *> staff, Schedule gymSchedule,
		int maxNumClients, int maxCapacity, Finance gymFinance);
	virtual ~Gym();
	vector<Client *> getClients() const;
	vector<Staff *> getStaff() const;
	Schedule getGymSchedule() const;
	int getMaxNumClients() const;
	int getMaxCapacity() const;
	Finance getGymFinance() const;
	void setClients(vector<Client *>);
	void setStaff(vector<Staff *>);
	void setGymSchedule(Schedule);
	void setMaxNumClients(int);
	void setMaxCapacity(int);
	void setGymFinance(Finance);
private:
	vector<Client *> clients;
	vector<Staff *> staff;
	Schedule gymSchedule;
	int maxNumClients;
	int maxCapacity;
	Finance gymFinance;
};

#endif /* GYM_H_ */