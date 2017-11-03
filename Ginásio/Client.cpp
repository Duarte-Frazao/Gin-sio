//Library
#include "Gym.h"
#include <iostream>
#include "Client.h"
#include "ErrorClasses.h"

//Functions
int filterInput(int inf, int sup);

using namespace std;


int Client::clientId = 0;

Client::Client(string clientName, Program *program, int clientAge,Gym *gym,PersonalTrainer *PT = NULL) :
		name(clientName), enrolledProgram(program), age(clientAge),gym(gym), responsiblePT(
				PT), id(++clientId), insideGym(false), paymentsUpToDate(
				true), numLatePayments(0) {
	//To-do initialize numDays remaining based on the program chosen
	numDaysRemaining = program->getDays();
}


Client::~Client() {}

#pragma region Gets

int Client::getId() const {
	return id;
}

string Client::getName() const
{
	return name;
}

int Client::getAge() const
{
	return age;
}

bool Client::getLocation() const
{
	return insideGym;
}

bool Client::getPaymentStatus() const
{
	return paymentsUpToDate;
}

int Client::getNumLatePayments() const
{
	return numLatePayments;
}

const Program *Client::getProgram() const
{
	return this->enrolledProgram;
}

int Client::getDaysRemaining() const
{
	return numDaysRemaining;
}

const PersonalTrainer *Client::getPT() const
{
	return this->responsiblePT;
}

const Gym *Client::getGym() const { return this->gym; }

#pragma endregion



#pragma region Sets

void Client::setProgram(Program *newProgram)
{
	enrolledProgram = newProgram;
}

void Client::setPT(PersonalTrainer *PT)
{
	this->responsiblePT = PT;
}

void Client::setGym(Gym *programGym)
{
	gym = programGym;
}

void Client::setName(string newName)
{
	name = newName;
}

#pragma endregion



void Client::changeLocation()
{
	if(insideGym)  insideGym = !insideGym; //Can always get out of the gym

	else{//But can only enter under some conditions
		if (!paymentsUpToDate) throw EntranceError("Payments not up to date");
		else if (numDaysRemaining == 0 && !insideGym) throw EntranceError("Maximum number of entries exceeded, see our other program offers!");
		else insideGym = !insideGym;
	}
}

void Client::problems(vector<string> &problems) const
{
	if (problems.size() != 0) problems.clear();
	if (insideGym) problems.push_back("Client is still inside gym");
	if (!paymentsUpToDate) problems.push_back("Payments not up to date");
}



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
			
			for (unsigned int i = 0; i < gym->getPrograms().size(); i++)
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
	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;



	int option = filterInput(0, (int) options.size() -1);

	return option;
}



