/*
* PersonalTrainer.cpp
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/
#include "stdafx.h"
#include "PersonalTrainer.h"

// PersonalTrainer constructor
PersonalTrainer::PersonalTrainer(int id, int age, int wage, string specializedArea) :
	Staff(id, age, wage), specializedArea(specializedArea) { /* vector<Client *> ? */
}

// PersonalTrainer destructor
PersonalTrainer::~PersonalTrainer() {

}

#pragma region Gets

vector<Client *> PersonalTrainer::getClients() const {
	return clients;
}

string PersonalTrainer::getSpecializedArea() const {
	return specializedArea;
}

#pragma endregion

# pragma region Sets

void PersonalTrainer::setSchedule(Schedule workSchedule) {
	Staff::setSchedule(workSchedule);
}

void PersonalTrainer::setClients(vector<Client *> clients) {
	this->clients = clients;
}

#pragma endregion