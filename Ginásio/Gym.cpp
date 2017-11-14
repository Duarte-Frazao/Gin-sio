#include "stdafx.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Gym.h"
#include "Client.h"

#ifdef WIN32
#include <conio.h>
#else
int _getch(void);
#endif

using namespace std;

void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);
void inputClientId(int &optionClient, Gym &gym);



// Gym Constructor
Gym::Gym(string name, vector<Program *> &programs, vector<Client *> &clients,
		vector<Staff *> &staff, vector<PersonalTrainer *> &profs,
		Schedule &gymSchedule, int maxNumClients, int maxCapacity,
		Finance &gymFinance) :
		name(name), programs(programs), clients(clients), staff(staff), profs(
				profs), gymSchedule(gymSchedule), maxNumClients(maxNumClients), maxCapacity(
				maxCapacity), gymFinance(gymFinance) {
}

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
vector<PersonalTrainer *> Gym::getPT() const {return profs;}

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


//Sets the gym schedule
void Gym::setName(string newName)
{
	name = newName;
}

void Gym::setGymSchedule(Schedule gymSchedule) {
	this->gymSchedule = gymSchedule;
}

//Sets the max number of clients of the gym
void Gym::setMaxNumClients(int maxNumClients) {
	this->maxNumClients = maxNumClients;
}

//Sets the max capacity of the gym
void Gym::setMaxCapacity(int maxCapacity) {
	this->maxCapacity = maxCapacity;
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
	cout << "    Welcome to Go Gym!      \n"
		<< "--- AUTHENTICATION PORTAL ---\n";

	Staff* staff_found = NULL;
	bool staffFound = 0;
	do
	{
		int staffId;
		cout << "Login ID: ";
		cin >> staffId;
		cin.ignore();

		if (findStaff(staffId, &staff_found))
		{
			staffFound = 1;
			bool access = 0;
			char ch;
			do
			{
				string pass;
				cout << "Password: ";
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
					cout << "\n\nACCESS GRANTED!\n" << "WELCOME STAFF NUMBER " << staff_found->getId() << "!\n\n";
					access = 1;
				}
				else {
					cout << "\n\nACESS DENIED!\n";
					cout << "Try again: press 0 or Exit: press 1\n" << "--> ";
					int incorrect_option;
					cin >> incorrect_option;
					while (incorrect_option != 0 && incorrect_option != 1) {
						cout << "Enter a correct command ...\n";
						cin >> incorrect_option;
					}
					if (incorrect_option) exit(0);
					cin.ignore();
				}

			} while (!access);
		}
		else
		{
			cout << endl << "STAFF NOT FOUND!" << endl;
			cout << "Try again: press 0 or Exit: press 1\n" << "--> ";
			int incorrect_option2;
			cin >> incorrect_option2;
			while (incorrect_option2 != 0 && incorrect_option2 != 1) {
				cout << "Enter a correct command ...\n";
				cin >> incorrect_option2;
			}
			if (incorrect_option2) exit(0);
			cin.ignore();
		}

	} while (!staffFound);

	delete staff_found;
}

#pragma endregion

#pragma region Search algorithms

//Finds gym's staff with a certain Id
bool Gym::findStaff(int staffId, Staff** staff_found) {
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
	for (const auto prof_pointer : profs)
	{
		if (prof_pointer->getId() == profId)
		{
			*prof_found = prof_pointer;
			return true;
		}
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


# pragma region staffMenu

//Shows the menu of options for adding or removing staff
int staffMenu() {

	string options[] = { "1. Add Staff", "2. Remove staff" };
	for (size_t i = 0; i < 3; i++) {
		cout << options[i] << endl;
	}

	/* insert function to accept option */
	int option = filterInput(1,options->size());

	return option;
}


//Handles the editing of the staff in the gym
void Gym::menuStaff() {

	int option;
	while ((option = staffMenu()) != 0) {
		switch (option) {
		case 1:
		{
			/* add staff */
			int age, wage;
			string name;
			do {
				cout << "Insert new staff's age: ";
				cin >> age;
				cin.ignore();
			} while (age < 0);
			do {
				cout << "Insert new staff's wage: ";
				cin >> wage;
				cin.ignore();
			} while (wage < 0);

			staff.push_back(new Staff(age, wage));
			cout << "Staff added sucessfully!\n";
		}
		break;
		case 2:
		{
			/* remove staff by Id*/
			int id;
			cout << "Insert staff's id to remove: ";
			cin >> id;
			cin.ignore();
			vector<Staff *>::iterator it_staff;
			for (it_staff = staff.begin(); it_staff != staff.end(); it_staff++) {
				if ((*it_staff)->getId() == id) {
					staff.erase(it_staff);
					cout << "Staff with id " << id << " erased sucessfully!\n";
				}
			}
			if (it_staff == staff.end()) {
				cout << "Staff with id " << id << " does not exist!\n";
			}
		}
		break;
		default:
			cout << "Unreachable option ...\n";
		}
	}
}

#pragma endregion

//Prints the programs the gym has to offer, as well as the conditions
void Gym::displayPrograms() const
{
	cout << name << " has the following programs to offer\n\n\n";
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		cout << programs.at(i);
	}
}

//Prints the staff the gym has contracted
void Gym::displayStaffIds() const
{
	for (size_t i = 0; i < clients.size(); i++)
	{
		cout << staff.at(i)->getName() << " ID: " << staff.at(i)->getId() << endl;
	}
}

//Prints the profs the gym has contracted
void Gym::displayProfsIds() const
{
	for (size_t i = 0; i < profs.size(); i++)
	{
		cout << profs.at(i)->getName() << " ID: " << profs.at(i)->getId() << endl;
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
	cout << "---Available program subscriptions---" << endl;
	for (unsigned int i = 0; i < programs.size(); i++)
	{
		cout << *(this->getPrograms().at(i));
	}
}

//Adds a client to the gym
void Gym::addClient()
{
	//To-do alterar mecanismo de assgn de pt
	string name;
	int age, program;
	cout << "Adicionar novo cliente" << endl << endl;

	//Name
	cout << "Nome: ";
	cin >> name;

	//Program subscription
	displayProgramOptions();
	cout << "Programa:";
	program= filterInput(1, programs.size());

	//age
	cout << "Idade: ";
	cin >> age;

	//To-do arranjar maneira de em vez de usar staff ser um professor, porque pode dar errado
	PersonalTrainer *professor = profs.at(rand() % profs.size());

	Client novoCliente(name, codeToProgram(program), age, professor);

	clients.push_back(&novoCliente);
	cout << "Cliente adicionado com sucesso" << endl;
	cout << "Informacao do novo cliente:" << endl;
	cout << novoCliente;
}

//Shows the menu of options for adding or removing clients
int clientMenu() {

	string options[] = { "1. Add client", "2. Remove client" };
	for (size_t i = 0; i < 3; i++) {
		cout << options[i] << endl;
	}

	/* insert function to accept option */
	int option = filterInput(1, options->size());

	return option;
}



//Shows gym's clients id's
void Gym::displayClientsIds()
{
	for (size_t i = 0; i < clients.size(); i++)
	{
		cout << clients.at(i)->getName() << " ID: " << clients.at(i)->getId() << endl;
	}
}

/**
Removes a client
*/
void Gym::removeClient(Gym &gym)
{
	int optionClient;
	Client *clientToEdit;
	inputClientIdObj(optionClient, gym, &clientToEdit);

	//algo que mostre ids + fun��o que check ids

	vector<Client *>::iterator it_client;
	for (it_client = clients.begin(); it_client != clients.end(); it_client++) {
		if ((*it_client)->getId() == optionClient) {
			clients.erase(it_client);
			cout << "Client with id " << optionClient << " erased sucessfully!\n";
			return;
		}
	}
}

//To-do falta dar overload de operator << no schedule para substituir printSchedule
std::ostream &operator<<(ostream &out, const Gym &gym)
{
	out << "\t" <<gym.name << endl;
	gym.displayPrograms();
	out <<gym.clients.size() << " Clients" << endl;
	out << gym.staff.size() << " Staff Members" << endl;
	out << gym.profs.size() << " Professors" << endl;
	//out << gym.gymSchedule << endl;
	out << "Maximun number of clients: " << gym.maxNumClients << endl;
	out << "Maximum gym capacity: " << gym.maxCapacity << endl;
	return out;
}
