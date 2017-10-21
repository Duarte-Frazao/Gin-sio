/*
* Gym.cpp
*/
#include "stdafx.h"
#include "Gym.h"


// Gym Constructor
Gym::Gym(string name,vector<Program *> programs, vector<Client *> clients, vector<Staff *> staff, Schedule gymSchedule,
	int maxNumClients, int maxCapacity, Finance gymFinance) :name(name), programs(programs), clients(clients),
	staff(staff), gymSchedule(gymSchedule), maxNumClients(maxNumClients),
	maxCapacity(maxCapacity), gymFinance(gymFinance) {}

// Gym Destructor
Gym::~Gym() {

}

#pragma region Gets 

string Gym::getName() const { return name; }

vector<Client *> Gym::getClients() const {
	return clients;
}

vector<Program *> Gym::getPrograms() const {
	return programs;
}

int Gym::getNumberPrograms() const
{
	return (int)programs.size();
}

vector<Staff *> Gym::getStaff() const {
	return staff;
}

Schedule Gym::getGymSchedule() const {
	return gymSchedule;
}

int Gym::getMaxNumClients() const {
	return maxNumClients;
}

int Gym::getMaxCapacity() const {
	return maxCapacity;
}

Finance Gym::getGymFinance() const {
	return gymFinance;
}

#pragma endregion

#pragma region Sets

void Gym::setClients(vector<Client *> clients) {
	this->clients = clients;
}

void Gym::setStaff(vector<Staff *> staff) {
	this->staff = staff;
}

void Gym::setName(string newName)
{
	name = newName;
}

void Gym::setGymSchedule(Schedule gymSchedule) {
	this->gymSchedule = gymSchedule;
}

void Gym::setMaxNumClients(int maxNumClients) {
	this->maxNumClients = maxNumClients;
}

void Gym::setMaxCapacity(int maxCapacity) {
	this->maxCapacity = maxCapacity;
}

void Gym::setGymFinance(Finance gymFinance) {
	this->gymFinance = gymFinance;
}

# pragma endregion

/**
Prints the programs the gym has to offer, as well as the conditions

@param
@return
*/
void Gym::displayPrograms() const
{
	cout << name << " has the following programs to offer\n\n\n";
	for (size_t i = 0; i < programs.size(); i++)
	{
		programs.at(i)->displayProgram();
	}
}