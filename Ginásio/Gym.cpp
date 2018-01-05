#include "stdafx.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iomanip>
#include "Gym.h"
#include "Client.h"
#include "colorWin.h"
#include "Input.h"

#ifdef WIN32
#include <conio.h>
#else
int _getch(void);
#endif

using namespace std;

void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);
void inputStaffIdObj(int &optionStaff, Gym &gym, Staff** staff_found);
void inputPtIdObj(int &optionPt, Gym &gym, Staff** staff_found);
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found);

//Functions
int filterInput(int inf, int sup,std::string msg = "Selection: ");

// Gym Constructor
Gym::Gym(string name, vector<Program *> &programs, vector<Client *> &clients,
		vector<Staff *> &staff, priority_queue<PersonalTrainer *, vector<PersonalTrainer*>, CmpPtPointers> &profs,
		Schedule &gymSchedule, int maxNumClients, int maxCapacity,
		Finance &gymFinance) :
		name(name), programs(programs), clients(clients), staff(staff), profs(
				profs), gymSchedule(gymSchedule), maxNumClients(maxNumClients), maxCapacity(
				maxCapacity), gymFinance(gymFinance) {}

// Gym Constructor
Gym::Gym(string name, vector<Program *> &programs, Schedule &gymSchedule,
		int maxNumClients, int maxCapacity, Finance &gymFinance) :
		name(name), programs(programs), gymSchedule(gymSchedule), maxNumClients(
				maxNumClients), maxCapacity(maxCapacity), gymFinance(
				gymFinance) {
}

// Gym Destructor
Gym::~Gym() {

}

#pragma region Gets 

//Get name of the gym
string Gym::getName() const { return name; }

//Returns the vector of client pointers of the gym
vector<Client *> Gym::getClients() const {return clients;}

//Returns the vector of program subscriptions pointers of the gym
vector<Program *> Gym::getPrograms() const {return programs;}

//Returns the number of program subscriptions the gym offers
int Gym::getNumberPrograms() const{return programs.size();}

//Returns the vector of pointers to staff of the gym
vector<Staff *> Gym::getStaff() const {return staff;}

//Returns the vector of pointers to Personal Trainer of the gym
priority_queue<PersonalTrainer *, vector<PersonalTrainer*>, CmpPtPointers> Gym::getPT() const {return profs;}

//Returns the gym schedule
Schedule Gym::getGymSchedule() const {return gymSchedule;}

//Returns the max number of clients the gym can sign
int Gym::getMaxNumClients() const {return maxNumClients;}

//Returns the max capacity of the gym
int Gym::getMaxCapacity() const {return maxCapacity;}

//Returns the finance of the gym
Finance Gym::getGymFinance() const {return gymFinance;}

#pragma endregion




#pragma region Sets


//Sets the vector of clients of the gym
void Gym::setClients(vector<Client *> clients) {
	this->clients = clients;
}


//Sets the vector of staff of the gym
void Gym::setStaff(vector<Staff *> staff) {
	this->staff = staff;
}

void Gym::setPq(PTQUEUE pq)
{
	profs = pq;
}


//Sets the gym schedule
void Gym::setName(string newName) {
	name = newName;
}

void Gym::setGymSchedule(Schedule gymSchedule) {
	this->gymSchedule = gymSchedule;
}

//Sets the max number of clients of the gym
void Gym::setMaxNumClients(int maxNumClients) {
	try {
		if (maxNumClients < 0) throw InvalidValue("Negative number of clients inserted!");
		this->maxNumClients = maxNumClients;
	}
	catch (InvalidValue &e) {
		cout << e.getReason() << endl;
	}
}

//Sets the max capacity of the gym
void Gym::setMaxCapacity(int maxCapacity) {
	try {
		if (maxCapacity < 0) throw InvalidValue("Negative capacity inserted!");
		this->maxCapacity = maxCapacity;
	}
	catch (InvalidValue &e) {
		cout << e.getReason() << endl;
	}
}


//Sets the gym finance
void Gym::setGymFinance(Finance gymFinance) {
	this->gymFinance = gymFinance;
}

#pragma endregion


#pragma region Add

void Gym::addClient(Client * client) {clients.push_back(client);}

void Gym::addStaff(Staff * staff) {this->staff.push_back(staff);}

void Gym::addProgram(Program* program) {programs.push_back(program);}

# pragma endregion



#pragma region Login authentication

//Performs the login process for a certain staff's id
void Gym::login() {
	cout << "    Welcome to " << name << " !      \n"
		<< "--- AUTHENTICATION PORTAL ---\n";


	Staff* staff_found = NULL;
	bool staffFound = 0;
	do
	{
		int staffId;
		cout << sign::question << "Login ID: ";
		getInput(staffId);

		if (findStaff(staffId, &staff_found))
		{
			staffFound = 1;
			bool access = 0;
			char ch;
			do
			{
				string pass;
				cout << sign::question << "Password: ";
				ch = _getch();
				while (ch != 13)
				{
					if (ch == 8)
					{
						if (pass.size() != 0)
						{
							pass.pop_back();
							cout << "\b \b";
						}
					}
					else
					{
						pass.push_back(ch);
						cout << "*";
					}
					ch = _getch();
				}

				if (staff_found->auth(pass))
				{
					cout << endl << endl << sign::success << "ACCESS GRANTED!\n" 
						<< "WELCOME STAFF NUMBER " << staff_found->getId() << "!\n\n";
					access = 1;
				}
				else {
					cout << endl << endl << sign::error << "ACCESS DENIED!\n";
					cout << "Try again: press 0 or Exit: press 1\n";
					int incorrect_option = filterInput(0, 1);
					if (incorrect_option) exit(0);
				}

			} while (!access);
		}
		else
		{
			cout << endl << sign::error << "STAFF NOT FOUND!" << endl;
			cout << "Try again: press 0 or Exit: press 1\n";
			int incorrect_option2 = filterInput(0, 1);
			if (incorrect_option2) exit(0);
		}

	} while (!staffFound);
}


#pragma endregion

#pragma region Search algorithms
bool Gym::findStaff(int staffId, Staff **staff_found) {

	for (const auto staff_pointer : staff)
	{
		if (staff_pointer->getId() == staffId)
		{
			*staff_found = staff_pointer;
			return true;
		}
	}

	staff_found = NULL;
	return false;
}


//Finds gym's professor with a certain Id
bool Gym::findProf(int profId, Staff** prof_found) {

	priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp(profs);
	while (!temp.empty()) 
	{
		if (temp.top()->getId() == profId) 
		{
			*prof_found = temp.top();
			return true;
		}

		temp.pop();
	}

	prof_found = NULL;
	return false;
}


//Finds gym's client with a certain Id
bool Gym::findClient(int clientId, Client** client_found) {
	for (const auto client_pointer : clients)
	{
		if (client_pointer->getId() == clientId)
		{
			*client_found = client_pointer;
			return true;
		}
	}

	client_found = NULL;
	return false;
}

//Finds gym's program with a certain Id
bool Gym::findProgram(int programId, Program** program_found) {
	for (const auto program_pointer : programs)
	{
		if (program_pointer->getCode() == programId)
		{
			*program_found = program_pointer;
			return true;
		}
	}

	program_found = NULL;
	return false;
}
#pragma endregion


//Shows gym's clients id's
void Gym::displayClientsIds()
{
	for (size_t i = 0; i < clients.size(); i++)
	{

		cout << std::setw(10) << std::left << std::setfill(' ') << clients.at(i)->getName() << " ID: " << clients.at(i)->getId() << endl;
	}
}

//Prints the staff the gym has contracted
void Gym::displayStaffIds() const
{
	for (size_t i = 0; i < staff.size(); i++)
	{
		cout << std::setw(10) << std::left << std::setfill(' ') << staff.at(i)->getName() << " ID: " << staff.at(i)->getId() << endl;
	}
}

//Prints the profs the gym has contracted
void Gym::displayProfsIds() const
{
	cout << "Personal Trainers displayed in descending availability\n";
	priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers>temp(profs);
	while (!temp.empty())
	{
		cout << std::setw(10) << std::left << std::setfill(' ') << temp.top()->getName() << " ID: " << temp.top()->getId() << endl;
		temp.pop();
	}
}

//Prints the programs the gym has to offer, as well as the conditions
void Gym::displayPrograms() const
{
	cout << name << " has the following programs to offer:\n\n";
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		cout << *programs.at(i);
	}
}


//Returns the gym's program subscription that has the id code
Program* Gym::codeToProgram(int code)
{
	for (unsigned int i = 0; i < programs.size(); i++)
		if (code == programs.at(i)->getCode())
			return programs.at(i);

	return NULL;

}

//Prints the programs the gym has to offer, as well as the conditions
void Gym::displayProgramOptions()
{
	cout << "---Available program subscriptions---" << endl<<endl;
	for (unsigned int i = 0; i < programs.size(); i++)
		cout << *(this->getPrograms().at(i));
}

/* Changes gym's capacity */
void Gym::changeCapacity()
{
	int newMaxCapacity;
	cout << "What is the new gym's capacity? ";
	getInput(newMaxCapacity);
	setMaxCapacity(newMaxCapacity);
	cout << sign::success << "Maximum capacity changed successfully!\n";
}

/* Changes gym's max number of clients */
void Gym::changeMaxNumClients()
{
	int newMaxNumClients;
	cout << "What is the new gym's maximum number of clients? ";
	getInput(newMaxNumClients);
	setMaxNumClients(newMaxNumClients);
	cout << sign::success << "Maximum number of clients changed successfully!\n";
}


//Adds a client to the gym
void Gym::addClient()
{
	//To-do alterar mecanismo de assgn de pt
	string name;
	int age, program;
	cout << "Add new client:" << endl << endl;

	//Name
	cout << "Name: ";
	getline(cin, name);
	cout << endl;

	//age
	cout << "Age: ";
	getInput(age);
	cout << endl;

	//Program subscription
	displayProgramOptions();
	program = filterInput(1, programs.size());

	//To-do arranjar maneira de em vez de usar staff ser um professor, porque pode dar errado
	int rand_index = rand() % profs.size();

	priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp(profs);
	while (!temp.empty() && rand_index >= 0)
	{
		rand_index--;
		temp.pop();
	}
	PersonalTrainer *professor = temp.top();

	Client * newClient = new Client(name, codeToProgram(program), age, professor);

	clients.push_back(newClient);
	cout << sign::success << "Client added sucessfully!" << endl << endl << endl;
	cout << "New client's information:" << endl;
	cout << *newClient;
}


/**
Removes a client
*/
void Gym::removeClient()
{
	int optionClient;
	Client *clientToEdit;
	inputClientIdObj(optionClient, *this, &clientToEdit);

	//algo que mostre ids + fun��o que check ids
	
	vector<Client *>::iterator it_client;
	for (it_client = clients.begin(); it_client != clients.end(); it_client++) {
		if ((*it_client)->getId() == optionClient) {
			clients.erase(it_client);
			cout << sign::success << "Client with id " << optionClient << " erased successfully!\n";
			return;
		}
	}
	cout << sign::error << "Client with id " << optionClient << " does not exist!\n";
}

/**
Adds a staff to the gym
*/
void Gym::addStaff()
{
	int age; double wage;
	string name, pass;

	cout << "Insert new staff's name: ";
	do {
		getline(cin, name);
		if (name.length() == 0)
			cout << sign::error << "Insert a name! ";
	} while (name.length() == 0);

	cout << "Insert new staff's age: ";
	getInput(age);

	cout << "Insert new staff's wage: ";
	getInput(wage);

	cout << "Insert new staff's password: ";
	do {
		getline(cin, pass);
		if (pass.length() == 0)
			cout << sign::error << "Insert a password! ";
	} while (pass.length() == 0);

	staff.push_back(new Staff(name, age, wage, pass));
	cout << sign::success << "Staff added successfully!\n";
}

/**
Removes a staff from the gym
*/
void Gym::removeStaff() 
{
	int optionStaff;
	Staff *staffToEdit;
	inputStaffIdObj(optionStaff, *this, &staffToEdit);
	
	vector<Staff *>::iterator it_staff;
	for (it_staff = staff.begin(); it_staff != staff.end(); it_staff++) {
		if ((*it_staff)->getId() == optionStaff) {
			staff.erase(it_staff);
			cout << sign::success << "Staff with id " << optionStaff << " erased sucessfully!\n";
			return;
		}
	}
	cout << sign::error << "Staff with id " << optionStaff << " does not exist!\n";
}

/**
Adds a personal trainer to the gym
*/
void Gym::addPersonalTrainer()
{
	int age; double wage;
	string name, pass, specializedArea;

	cout << "Insert new personal trainer's name: ";
	do {
		getline(cin, name);
		if (name.length() == 0)
			cout << sign::error << "Insert a name! ";
	} while (name.length() == 0);

	cout << "Insert new personal trainer's age: ";
	getInput(age);

	cout << "Insert new pt's specialized area: ";
	getline(cin, specializedArea);

	cout << "Insert new personal trainer's wage: ";
	getInput(wage);

	cout << "Insert new pt's password: ";
	do {
		getline(cin, pass);
		if (pass.length() == 0)
			cout << sign::error << "Insert a password! ";
	} while (pass.length() == 0);

	PersonalTrainer* pt = new PersonalTrainer(name, age, wage, pass, specializedArea);
	staff.push_back(pt);
	profs.push(pt);
	cout << sign::success << "Personal trainer added successfully!\n";
}

/**
Removes a personal trainer from the gym
*/
void Gym::removePersonalTrainer()
{
	bool pt_found = false;
	int optionProf;
	Staff *profToEdit;
	inputPtIdObj(optionProf, *this, &profToEdit);
	
	priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp(profs);
	while (!profs.empty()) {
		if (profs.top()->getId() != optionProf) {
			temp.push(profs.top());
		}
		pt_found = true;
		profs.pop();
	}
	profs = temp;

	if (pt_found) {
		vector<Staff *>::iterator it_staff;
		for (it_staff = staff.begin(); it_staff != staff.end(); it_staff++) {
			if ((*it_staff)->getId() == optionProf) {
				staff.erase(it_staff);
				cout << sign::success << "Personal trainer with id " << optionProf << " erased sucessfully!\n";
				return;
			}
		}
	}
	
	cout << "Personal trainer with id " << optionProf << " does not exist!\n";
}

void Gym::popPqElem()
{
	profs.pop();
}

/**
Adds a program to the gym
*/
void Gym::addProgram()
{
	int programCode, gymDays;
	float cost;
	Program *programFound = NULL;

	cout << "Insert new program's code: ";
	do {
		getInput(programCode);
		if (findProgram(programCode, &programFound))
			cout << sign::error << "Insert a non-existent program! ";
	} while (findProgram(programCode, &programFound));

	cout << "Insert program number of gym days: ";
	do {
		getInput(gymDays);
		if (gymDays > 365)
			cout << sign::error << "Please insert a valid value! ";
	} while (gymDays > 365);

	cout << "Insert program's monthly cost: ";
	getInput(cost);

	programs.push_back(new Program(programCode, gymDays, cost));
	cout << sign::success << "New program added successfully!\n";
}

/**
Removes a program from the gym
*/
void Gym::removeProgram()
{
	int optionProgram;
	Program *programToErase;
	inputProgramIdObj(optionProgram, *this, &programToErase);

	vector<Program *>::iterator it_prog;
	for (it_prog = programs.begin(); it_prog != programs.end(); it_prog++) {
		if ((*it_prog)->getCode() == optionProgram) {
			programs.erase(it_prog);
			cout << sign::success << "Program with code " << optionProgram << " erased sucessfully!\n";
			return;
		}
	}
	cout << sign::error << "Program with code " << optionProgram << " does not exist!\n";
}

/**
Deposits amount
*/
void Gym::depositAmount()
{
	cout << "What is the amount to deposit to gym's account ? ";
	double amount;
	getInput(amount);

	Transaction newTransaction("DEPOSIT", amount);
	newTransaction.setDescription("BANK TRANSFER");

	gymFinance.addTransaction(newTransaction);
	cout << sign::success << "Transaction performed successfully!\n\n";
}

/**
Makes payments for every staff who hasn't been paid yet
*/
void Gym::makePayments()
{
	cout << "------------ Paid workers ------------ \n";
	if (staff.size() == 0) {
		cout << "No workers to be paid!\n\n";
	}
	else {
		bool someonePaid = false, allPaid = true;
		for (auto worker : staff) {
			if (!worker->getWasPaid()) {
				Transaction payment("WITHDRAWAL", worker->getWage());
				payment.setDescription("MONTHLY PAYMENT");
				if (gymFinance.addTransaction(payment)) {
					someonePaid = true;
					worker->changeWasPaid();
					cout << "ID: " << worker->getId() << " | Name: " << worker->getName() << endl;
				}
				else allPaid = false;
			}
		}
		if (allPaid && !someonePaid) cout << "Every worker is already paid!\n";
		else if (!someonePaid) cout << "Insufficient balance to pay any salary!\n";
	}
	cout << endl;
}

//To-do falta dar overload de operator << no schedule para substituir printSchedule
std::ostream &operator<<(ostream &out, const Gym &gym)
{	out << string(gym.name.length()+2,'-')<<endl;
	out << "|" <<gym.name << "|" << endl;
	out << string(gym.name.length()+2,'-')<<endl<<endl;
	gym.displayPrograms();
	out << gym.clients.size() << " Clients" << endl<< endl;
	out << gym.staff.size() << " Staff Members" << endl<< endl;
	out << gym.profs.size() << " Professors" << endl<< endl;
	out << gym.gymSchedule << endl<<endl;
	out << "Maximum number of clients: " << gym.maxNumClients << endl<< endl;
	out << "Maximum gym capacity: " << gym.maxCapacity << endl<< endl<< endl;
	return out;
}