//Library
#include "stdafx.h"
#include "Gym.h"
#include <iostream>
#include "Client.h"
#include "ErrorClasses.h"

//Functions
int filterInput(int inf, int sup,std::string msg = "Selection: ");

using namespace std;


int Client::clientId = 0;


//Client constructor
Client::Client(string clientName, Program *program, int clientAge,PersonalTrainer *PT = NULL) :
		name(clientName), enrolledProgram(program), age(clientAge), responsiblePT(
				PT), id(++clientId), insideGym(false), paymentsUpToDate(
				true), numLatePayments(0) {
	//To-do initialize numDays remaining based on the program chosen
	numDaysRemaining = program->getDays();
}


//Client destructor
Client::~Client() {

}

#pragma region Gets
//getId
int Client::getId() const {
	return id;
}

//getName
string Client::getName() const
{
	return name;
}

//Returns the age of a Client
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

//Returns the status of the payments

bool Client::getPaymentStatus() const
{
	return paymentsUpToDate;
}

//Returns the number of months not yet payed
int Client::getNumLatePayments() const
{
	return numLatePayments;
}

//Returns the enrolled Program

const Program *Client::getProgram() const
{
	return this->enrolledProgram;
}

//Returns the number of days remaining
int Client::getDaysRemaining() const
{
	return numDaysRemaining;
}

//Returns the personal trainer that is responsible for the Client
const PersonalTrainer *Client::getPT() const
{
	return this->responsiblePT;
}


#pragma endregion

#pragma region Sets

//Sets a new subscription to Client
void Client::setProgram(Program *newProgram)
{
	enrolledProgram = newProgram;
}

//Sets a new PersonalTrainer to Client
void Client::setPT(PersonalTrainer *PT)
{
	this->responsiblePT = PT;
}


//Sets a new name to Client
void Client::setName(string newName)
{
	name = newName;
}

#pragma endregion

//Changes the current location of Client.
void Client::changeLocation()
{
	if(insideGym)  insideGym = !insideGym; //Can always get out of the gym

	else{//But can only enter under some conditions
		if (!paymentsUpToDate) throw EntranceError("Payments not up to date");
		else if (numDaysRemaining == 0 && !insideGym) throw EntranceError("Maximum number of entries exceeded, see our other program offers!");
		else insideGym = !insideGym;
	}
}


//Returns in the argument vector problems the reasons for not being able to edit the Client
void Client::problems(vector<string> &problems) const
{
	if (problems.size() != 0) problems.clear();
	if (insideGym) problems.push_back("Client is still inside gym");
	if (!paymentsUpToDate) problems.push_back("Payments not up to date");
}

//Edits a Client
void Client::editClient(Gym &gym)
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
			cout << "Previously: " << name << endl;
			cout << "->";
			cin >> newName;
			setName(newName);
			break;
		case 2:
			//Error checking
			problems(clientProblems);
			if (clientProblems.size() != 0) throw EditingError(clientProblems);

			cout << "What's the subscription you want to enroll?\n" << endl;
			gym.displayProgramOptions();

			//Selection of the new program
			newProgramCode = filterInput(1,gym.getNumberPrograms(),"Select a new program: ");

			//Checks if the program is the current one
			if (newProgramCode == enrolledProgram->getCode())  throw EditingError(vector<string>{"Trying to change program to the current one"});

			//Gets the respective program of the code
			setProgram(gym.codeToProgram(newProgramCode));

			//Updates days, as there were changes to the program
			updateNumDaysRemaining();

			cout << "Program successfully changed to program number " << enrolledProgram->getCode() << endl << endl;
			break;
			
		case 3:
			cout << *this;
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
	//setProgram(int newProgram);
	//setPT(PersonalTrainer *PT);
}

//Menu for editing client
int Client::editClientMenu() const
{
	cout << "\nSelect what you want to edit" << endl<< endl;

	vector<string> options = { "1 - Change name", "2 - Set a new program subscription", "3 - Show information", "0 - Sair\n" };

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}

//Updates the number of days remaining after setting a new program
void Client::updateNumDaysRemaining()
{
	if (numDaysRemaining > enrolledProgram->getDays()) numDaysRemaining = enrolledProgram->getDays();
}


std::ostream & operator<<(std::ostream & out, const Client &client)
{
	out << "\n---------- Client Information ----------" << endl << endl;
	out << "Client " << client.id << " information\n";
	out << "Name: " << client.name<< "\n";
	out << "Age: " << client.age << "\n";
	out << "Location: ";
	if (client.insideGym) out << "inside gym\n";
	else out << "outside gym\n";
	out << "Payment Status: ";
	if (client.paymentsUpToDate) out << "Up-to-date\n";
	else out << client.numDaysRemaining << " late payments\n";
	out << "Responsible professor: " << client.responsiblePT->getId() << endl << endl;
	out << *(client.getProgram())<<endl;
	return out;
}

void Client::informationClient()
{
	//Pode-se adicionar mais op��es como mostrar plano de treino
	cout << *this;
}




