/*
 * Client.cpp
 *
 *  Created on: 14/10/2017
 *      Author: Sandro Ca
 */
#include "stdafx.h"
#include "Gym.h"
#include <iostream>

using namespace std;


#pragma region EntranceError

//EntranceError constructor
EntranceError::EntranceError(string rz) : reason(rz) {}

//getReason
string EntranceError::getReason() const { return reason; }

//operator << overload
ostream & operator << (ostream &out, EntranceError &error) {
	out << "Error registring client's entry" << endl;
	out << "Reason: " << error.reason << endl;
	return out;
}

#pragma endregion

//Client constructor
Client::Client(string clientName, int program, int clientAge, PersonalTrainer *PT):
	insideGym(false), paymentsUpToDate(true), numLatePayments(0), enrolledProgram(program),
	age(clientAge), responsiblePT(PT){
	//To-do initialize numDays remaining based on the program chosen
}

//Client destructor
Client::~Client() {

}

#pragma region Gets
//getName
string Client::getName() const
{
	return name;
}

//getAge
int Client::getAge() const
{
	return age;
}

//getLocation
bool Client::getLocation() const
{
	return insideGym;
}

//getStatusPaymetns
bool Client::getPaymentStatus() const
{
	return paymentsUpToDate;
}

//getNumLatePayments
int Client::getNumLatePayments() const
{
	return numLatePayments;
}

//getProgram
int Client::getProgram() const
{
	return enrolledProgram;
}

//getDaysRemaining
int Client::getDaysRemaining() const
{
	return numDaysRemaining;
}

//getPT
const PersonalTrainer *Client::getPT() const
{
	return this->responsiblePT;
}
#pragma endregion

#pragma region Sets

//setProgram
void Client::setProgram(int newProgram)
{
	enrolledProgram = newProgram;
}

//setPT
void Client::setPT(PersonalTrainer *PT)
{
	this->responsiblePT = PT;
}

#pragma endregion

void Client::changeLocation()
{
	if (!paymentsUpToDate) throw EntranceError("Payments not up to date");
	else if (numDaysRemaining == 0 && !insideGym) throw EntranceError("Maximum number of entrys excedeed, see our other program offers!");
	else insideGym = !insideGym;
}




