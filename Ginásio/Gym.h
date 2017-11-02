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
#include <conio.h>
using namespace std;

class Client;

class Gym {
public:
	Gym(string name, vector<Program *> programs, vector<Client *> clients, vector<Staff *> staff, Schedule gymSchedule, int maxNumClients, int maxCapacity, Finance gymFinance);
	virtual ~Gym();
	string getName() const;
	vector<Client *> getClients() const;
	vector<Staff *> getStaff() const;
	vector<Program *> getPrograms() const;
	Schedule getGymSchedule() const;
	int getMaxNumClients() const;
	int getNumberPrograms() const;
	int getMaxCapacity() const;
	Finance getGymFinance() const;
	void displayPrograms() const;
	void setClients(vector<Client *>);
	void setStaff(vector<Staff *>);
	void setGymSchedule(Schedule);
	void setMaxNumClients(int);
	void setMaxCapacity(int);
	void setGymFinance(Finance);
	void setName(string newName);
	bool findStaff(int staffId, Staff* staff_found);
	void login(int staffId);
	void menuStaff();
private:
	string name;
	vector<Client *> clients;
	vector<Staff *> staff;
	Schedule gymSchedule;
	int maxNumClients;
	int maxCapacity;
	Finance gymFinance;
	vector<Program*> programs;
};

#endif /* GYM_H_ */