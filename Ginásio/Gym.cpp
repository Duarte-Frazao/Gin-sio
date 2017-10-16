/*
* Gym.cpp
*/
#include "stdafx.h"
#include "Gym.h"
using namespace std;

// Gym Constructor
Gym::Gym(vector<Client *> clients, vector<Staff *> staff, Schedule gymSchedule,
	int maxNumClients, int maxCapacity, Finance gymFinance) : clients(clients),
	staff(staff), gymSchedule(gymSchedule), maxNumClients(maxNumClients),
	maxCapacity(maxCapacity), gymFinance(gymFinance) {}

// Gym Destructor
Gym::~Gym() {

}

#pragma region Gets 

vector<Client *> Gym::getClients() const {
	return clients;
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