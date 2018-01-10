#include <iostream>
#include "stdafx.h"
#include "PersonalTrainer.h"
#include "colorWin.h"
#include "Input.h"
#include "Staff.h"
#include "Client.h"
#include "Gym.h"
#include <unordered_set>
#include <utility>
#include <algorithm>

using namespace std;

//Functions
int filterInput(int inf, int sup, std::string msg = "Selection: ");
void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found);

PersonalTrainer::PersonalTrainer(int age, double wage, string specializedArea) :
	Staff(age, wage), specializedArea(specializedArea) {}

PersonalTrainer::PersonalTrainer(std::string name, int age, double wage, std::string pwd, std::string specializedArea) :
	Staff(name, age, wage, pwd), specializedArea(specializedArea) {}

PersonalTrainer::PersonalTrainer(int id, std::string name, int age, double wage, std::string pwd, std::string specializedArea) :
	Staff(id, name, age, wage, pwd), specializedArea(specializedArea) {

}

PersonalTrainer::~PersonalTrainer() {

}

#pragma region Gets



AssociatedClientsHash PersonalTrainer::getClients() const { return clients; }

string PersonalTrainer::getSpecializedArea() const { return specializedArea; }


#pragma endregion

# pragma region Sets


void PersonalTrainer::setSchedule(Schedule workSchedule) {
	Staff::setSchedule(workSchedule);
}


void PersonalTrainer::addClient(Client * client)
{
	clients.insert(client);
}


void PersonalTrainer::setClients(vector<Client *> clients) {
	for(uint i =0; i < clients.size();i++)
	{
		addClient(clients.at(i));
	}
}


void PersonalTrainer::setSpecializedArea(string area) {

	specializedArea = area;
}

#pragma endregion

#pragma region editPersonalTrainer

/**
Shows the menu of options for editing the personal trainer
and returns the option chosen

@return Returns the chosen option of the personal trainer's edit menu
*/
int editPersonalTrainerMenu() {

	cout << "\nSelect what you want to edit" << endl;

	vector<string> options = { "1. Edit specialized area", "2. Edit associated clients", "3. Show information", "0. Return" };

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}

void PersonalTrainer::editPersonalTrainer(Gym &gym) {

	bool continueInMenu = true;
	string newSpecializedArea;
	do
	{
		int option = editPersonalTrainerMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			cout << "What's the PT's new specialized area? " << endl;
			cout << "Previously: " << specializedArea << endl;
			cout << "->";
			cin.ignore(1000, '\n');
			getline(cin, newSpecializedArea);
			setSpecializedArea(newSpecializedArea);
			cout << sign::success <<"PT's specialized area sucessfully modified!\n";
			break;
		case 2:
			editAssociatedClients(gym);
			break;
		case 3:
			cout << *this;
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
}

/**
Shows the menu of options for editing the personal trainer's
associated clients and returns the option chosen

@return Returns the chosen option of the personal trainer's
associated clients' edit menu
*/
int editAssociatedClientsMenu() 
{
	cout << "\nSelect what you want to edit" << endl;

	vector<string> options = { "1. Add client", "2. Remove client", "0. Return" };
	
	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}

void PersonalTrainer::editAssociatedClients(Gym &gym) {

	string name;
	int age;
	bool continueInMenu = true;
	Client *clientToAdd = NULL;
	Client *clientToErase = NULL;
	Program *programFound = NULL;
	int optionClient;
	int optionProgram;
	do
	{
		int option = editAssociatedClientsMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
		{
			string answer_str;
			char answer;

			cin.ignore();
			cout << sign::question << "Willing to insert existent client (y/n)? ";
			getline(cin, answer_str);
			answer = tolower(answer_str.at(0));
			while ((answer != 'y' && answer != 'n') || answer_str.length() > 1) {
				cout << sign::error << "Please insert a valid input! ";
				getline(cin, answer_str);
				answer = tolower(answer_str.at(0));
			}
			cout << endl;

			if (answer == 'y') {
				bool alreadyExists=true;
				do{
					inputClientIdObj(optionClient, gym, &clientToAdd);
					std::pair<AssociatedClientsHash::iterator, bool > result;
					result = clients.insert(clientToAdd);
					if(result.second == false) cout << sign::error << "Client already exists related to this personal trainer!\n\n";
					else alreadyExists = false;
				}while(alreadyExists);
				cout << endl;

				inputProgramIdObj(optionProgram, gym, &programFound);

				PersonalTrainer* changed_PT = NULL;
				priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp;
				while (!gym.getPT().empty()) {
					if (gym.getPT().top()->getId() != this->getId()) {
						temp.push(gym.getPT().top());
					}
					else {
						changed_PT = gym.getPT().top();
					}
					gym.popPqElem();
				}

				changed_PT->addClient(clientToAdd);
				clientToAdd->setPT(changed_PT);
				temp.push(changed_PT);

				gym.setPq(temp);
			}
			else {
				/* add new client to Personal Trainer */
				cout << "Insert the name of the client to add: ";
				getline(cin, name);
				cout << "Insert client's age: ";
				getInput(age);

				cout << endl << endl;
				inputProgramIdObj(optionProgram, gym, &programFound);

				PersonalTrainer* changed_PT = NULL;
				priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp;
				while (!gym.getPT().empty()) {
					if (gym.getPT().top()->getId() != this->getId()) {
						temp.push(gym.getPT().top());
					}
					else {
						changed_PT = gym.getPT().top();
					}
					gym.popPqElem();
				}

				//If the client is new at the gym
				Client * newClient = new Client(name, new Program(optionProgram), age, changed_PT);
				gym.addClient(newClient); //Also add the client to the gym's clients vector
				changed_PT->addClient(newClient);
				temp.push(changed_PT);

				gym.setPq(temp);
			}

			cout << endl << sign::success << "Client added successfully to Personal Trainer!\n";
			break;
		}
		case 2:
		{
			if (gym.getClients().empty()) {
				cerr << "There are no clients in the gym" << std::endl;
				return;
			}

			cout << "----------ID Selection----------" << endl;
			bool badInput = false;
			AssociatedClientsHash::iterator iter = clients.begin();
			while(iter!=clients.end()) {
				cout << setw(10) << left << (*iter)->getName() << " ID: " << (*iter)->getId() << endl;
				iter++;
			}

			cout << endl << sign::question << "Insert client's ID: ";
			do
			{
				if (badInput)
				{
					cout << sign::error << "Insert a valid ID" << endl;
					AssociatedClientsHash::iterator iter = clients.begin();
					while(iter!=clients.end()) {
						cout << setw(10) << left << (*iter)->getName() << " ID: " << (*iter)->getId() << endl;
						iter++;
					}
				}
				cin >> optionClient;
				badInput = true;

			} while (!gym.findClient(optionClient, &clientToErase));

			std::pair<AssociatedClientsHash::iterator, bool > result;
			result = clients.insert(clientToErase);
			if(result.second == false)
			{
				cout << sign::success << "Client with id " << clientToErase->getId() << " erased successfully!\n";
				PersonalTrainer* pNew;
				priority_queue<PersonalTrainer *, std::vector<PersonalTrainer*>, CmpPtPointers> temp;
				bool find=true;
				while (!gym.getPT().empty()) {
					if (gym.getPT().top()->getId() == this->getId() ||!find) {
						temp.push(gym.getPT().top());
					}
					else {
						find=false;
						clientToErase->setPT(gym.getPT().top());
						temp.push(gym.getPT().top());
					}
					gym.popPqElem();
				}
				gym.setPq(temp);
			}else cout << sign::error << "Client with id " << clientToErase->getId() << " does not exist!\n";

			clients.erase(result.first);

			//free(clientToErase);


			break;
		}
		default:
			cout << "Algum erro";
			break;
		}

	} while (continueInMenu);
}
#pragma endregion

void PersonalTrainer::printInfo() 
{
	cout << *this;
}


int displayAssociatedClientsMenu(const PersonalTrainer& pt)
{
	cout << "\nSelect how you want to see "<< pt.getName()<< " list of associated clients: " << endl;

	vector<string> options = { "1. Full", "2. Partial" };

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(1, options.size()  );

	return option;
}

int displayAssociatedClientsTypeMenu(const PersonalTrainer& pt)
{
	cout << "\nSelect how the list should be ordered: " << endl;

	vector<string> options = { "1. Id", "2. Age","3. Number of late payments"};

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(1, options.size() );

	return option;
}

std::vector<Client* > PersonalTrainer::getVClients() const
{
	auto it=clients.begin();
	vector<Client*> v;
	while(it!= clients.end())
	{
		v.push_back(*it);
		it++;
	}
	return v;
}

ostream& operator<<(ostream& out, const PersonalTrainer& pt) {

	vector<Client*> v;

	if(pt.getClients().size() >0)
	{
		int optionSize= displayAssociatedClientsMenu(pt);

		int size;

		if(optionSize == 2)
		{
			cout << "How many client's long should the list be? ";
			size= filterInput(0, 200);
			if(size>pt.getClients().size()) size= pt.getClients().size();
			cout<< endl;
		}else size= pt.getClients().size();


		int optionType=displayAssociatedClientsTypeMenu(pt);

		v=pt.getVClients();

		switch(optionType)
		{
			case (1):
				sort(v.begin(), v.end(),
					[](const Client* a, const Client* b)
				{
					return a->getId()<b->getId();
				});
				break;
			case(2):
				sort(v.begin(), v.end(),
					[](const Client* a, const Client* b)
				{
					return a->getAge()<b->getAge();
				});
				break;
			case(3):
				sort(v.begin(), v.end(),
					[](const Client* a, const Client* b)
				{
					return a->getNumLatePayments()<b->getNumLatePayments();
				});
				break;

		}

	}

	out << static_cast<const Staff &>(pt);
	out << "Specialized area: " << pt.getSpecializedArea() << endl;
	out << "Clients by whom it is responsible: ";
	if (v.size() == 0) out << "NONE" << endl;
	cout << endl;
	for(int i = 0; i< v.size();i++) out << "-> ID: " << v.at(i)->getId() << " | Name: " << v.at(i)->getName()<< " | Age: " << v.at(i)->getAge()<< " | Number of late payments: " << v.at(i)->getNumLatePayments() << endl;


	return out;
}
