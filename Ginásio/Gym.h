/*
 * Gym.h
 */
#include <vector>
#include "Client.h"
#include "Staff.h"
#include "Finance.h"
#include "Schedule.h"

#ifndef GYM_H_
#define GYM_H_

class Gym {
public:
	Gym();
	virtual ~Gym();
private:
	std::vector<Client *> clients;
	std::vector<Staff *> staff;
	Schedule gymSchedule;
	int maxNumClients;
	int maxCapacity;
	Finance gymFinance;
};

#endif /* GYM_H_ */
