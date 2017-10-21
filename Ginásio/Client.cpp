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

/**
Filters an option by giving two limits, makes the user input and integer between them

@param inf Inferior Limit
@param sup Superior Limit
@return
*/
int filterInput(int inf, int sup);

#pragma region EntranceError

//EntranceError constructor
EntranceError::EntranceError(string rz) : reason(rz) {}

//getReason
string EntranceError::getReason() const { return reason; }

//operator << overload
ostream & operator << (ostream &out, const EntranceError &error) {
	out << "Error registring client's entry" << endl;
	out << "Reason: " << error.reason << endl;
	return out;
}

#pragma endregion

#pragma region EditingError

//EntranceError constructor
EditingError::EditingError(vector<string> rz) : reasons(rz) {}

//getReason
vector<string> EditingError::getReasons() const { return reasons; }

//operator << overload
ostream & operator << (ostream &out, const EditingError &error) {
	out << "Error editing client" << endl;

	if (error.reasons.size() == 1)out << "Reason: " << error.reasons.at(0) << endl;
	else
	{
		out << "Reasons: " << endl;
		for (size_t i = 0; i < error.reasons.size() - 1; i++)
		{
			out << error.reasons.at(i) << endl;
		}
	}
	return out;
}

#pragma endregion

//Client constructor
Client::Client(string clientName, Program *program, int clientAge, PersonalTrainer *PT):
	name(clientName), insideGym(false), paymentsUpToDate(true), numLatePayments(0), enrolledProgram(program),
	age(clientAge), responsiblePT(PT){
	//To-do initialize numDays remaining based on the program chosen
}

//Client destructor
Client::~Client() {

}

#pragma region Gets
/**
Returns the name of a Client

@param 
@return Name of Client
*/
string Client::getName() const
{
	return name;
}

/**
Returns the age of a Client

@param 
@return returns the age of a Client
*/
int Client::getAge() const
{
	return age;
}

/**
Returns if the Client is inside or outside the gym

@param 
@return Returns true if Client is inside the gym and false if outside
*/
bool Client::getLocation() const
{
	return insideGym;
}

/**
Returns the status of the payments

@param 
@return Returns true if Client's payments are up to date, false if not
*/
bool Client::getPaymentStatus() const
{
	return paymentsUpToDate;
}

/**
Returns the number of months not yet payed

@param
@return Returns the number of months not yet payed
*/
int Client::getNumLatePayments() const
{
	return numLatePayments;
}

/**
Returns the enrolled Program

@param
@return Returns the enrolled Program 
*/
const Program *Client::getProgram() const
{
	return this->enrolledProgram;
}

/**
Returns the number of days remaining

@param
@return Returns the number of days remaining
*/
int Client::getDaysRemaining() const
{
	return numDaysRemaining;
}

/**
Returns the personal trainer that is responsible for the Client

@param
@return Returns the personal trainer that is responsible for the Client
*/
const PersonalTrainer *Client::getPT() const
{
	return this->responsiblePT;
}

const Gym *Client::getGym() const { return this->gym; }

#pragma endregion

#pragma region Sets

/**
Sets a new subscription to Client

@param newProgram The new subscription the Client has choosen to replace the current one
@return 
*/
void Client::setProgram(Program *newProgram)
{
	enrolledProgram = newProgram;
}

/**
Sets a new PersonalTrainer to Client

@param PT New Personal Trainer choosen to replace the current one
@return
*/
void Client::setPT(PersonalTrainer *PT)
{
	this->responsiblePT = PT;
}

void Client::setGym(Gym *programGym)
{
	gym = programGym;
}

/**
Sets a new name to Client

@param newName New name for Client
@return
*/
void Client::setName(string newName)
{
	name = newName;
}

#pragma endregion

/**
Changes the current location of Client.
Checks if he's allowed to enter, if not throws an exception 

@param
@return
*/
void Client::changeLocation()
{
	if (!paymentsUpToDate) throw EntranceError("Payments not up to date");
	else if (numDaysRemaining == 0 && !insideGym) throw EntranceError("Maximum number of entrys excedeed, see our other program offers!");
	else insideGym = !insideGym;
}

/**
Returns in the argument vector problems the reasons for not being able to edit the Client
If the vector wasn't empty it resets the vector to display only the current problems

@param problems A vector to return the problems
@return 
*/
void Client::problems(vector<string> &problems) const
{
	if (problems.size() != 0) problems.clear();
	if (insideGym) problems.push_back("Client is still inside gym");
	if (!paymentsUpToDate) problems.push_back("Payments not up to date");
}

/**
Edits a Client

@param
@return
*/
void Client::editClient()
{
	bool continueInMenu = true;
	string newName; 
	vector<string> clientProblems;
	int newProgramCode;
	do
	{
		int option = editClientMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			cout << "What's the new Client's name? " << endl;
			cin >> newName;
			setName(newName);
			break;
		case 2:

			//Error checking
			problems(clientProblems);
			if (clientProblems.size() != 0) throw EditingError(clientProblems);
			cout << "What's the subscription you want to enrol?\n" << endl;

			//Selection of the new program
			
			newProgramCode = filterInput(1,(int)this->getGym()->getNumberPrograms());

			//Checks if the program is the current one
			if (newProgramCode == enrolledProgram->getCode())  throw EditingError(vector<string>{"Trying to change program to the current one"});
			
			for (int i = 0; i < gym->getPrograms().size(); i++)
			{
				if (newProgramCode == gym->getPrograms().at(i)->getCode()) cout << "hell";
			}
			//setProgram(newProgram);
			//updateNumDaysRemaining(newProgram.getDays());
			break;
		case 3:
			//viewInfo();
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
	//setProgram(int newProgram);
	//setPT(PersonalTrainer *PT);
}

int Client::editClientMenu() const 
{
	cout << "Select what you want to edit" << endl;

	vector<string> options = { "1 - Change name", "2 - Set a new program subscription", "3 - Choose another responsible Personal Trainer", "0 - Sair\n" };

	for (int i = 0; i < options.size(); i++)
	{
		cout << options.at(i) << endl;
	}


	int option = filterInput(0, (int)options.size() -1);

	return option;
}

//Filters an option by giving two limits, makes the user input and integer between them
int filterInput(int inf, int sup)
{
	int option;
	bool validValue = true;

	do
	{
		cin >> option;
		if (cin.fail() || option< inf || option > sup)
		{
			cout << "Please enter a valid value\n";
			cin.clear();
			cin.ignore(100, '\n');
			validValue = false;
		}
		else if(validValue == false) validValue = true;

	} while (!validValue);

	return option;

}

