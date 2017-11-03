/*
* Client.h
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include "PersonalTrainer.h"
#include "Gym.h"
#include "Program.h"
using namespace std;

/**
Filters an option by giving two limits, makes the user input and integer between them

@param inf Inferior Limit
@param sup Superior Limit
@return
*/
int filterInput(int inf, int sup);

class PersonalTrainer;
class Gym;

class EntranceError {
	string reason;
public:
	EntranceError(string rz);
	string getReason() const;
	friend ostream & operator << (ostream &out, const EntranceError &error);
};

class EditingError {
	vector<string> reasons;
public:
	EditingError(vector<string> rz);
	vector<string> getReasons() const;
	friend ostream & operator << (ostream &out, const EditingError &error);
};

class Client {
public:

	Client::Client(string clientName, Program *program, int clientAge, PersonalTrainer *PT);
	~Client();
	int getId() const;
	string getName() const;
	int getAge() const; //TO-DO a way to update age
	bool getLocation() const;
	bool getPaymentStatus() const;
	int getNumLatePayments() const;
	const Program *getProgram() const;
	const Gym *getGym() const;
	int getDaysRemaining() const;
	const PersonalTrainer *getPT() const;
	void setProgram(Program *newProgram);
	void setPT(PersonalTrainer *PT);
	void setGym(Gym *programGym);
	void setName(string newName);
	void changeLocation();
	void editClient();
	int editClientMenu() const;
	void problems(vector<string> &problems) const;
	void updateNumDaysRemaining();
	friend std::ostream & operator<<(std::ostream & out, const Client &client);
	void viewInfo() const;

	//void updatePayments() const;
	//void changeProgram() const;
	//void changePT() const;
	//void editBasicSettings() const; client, name age

private:

	string name;
	int id, age;
	static int clientId ;
	bool insideGym;
	bool paymentsUpToDate;
	int numLatePayments;
	Program *enrolledProgram;
	int numDaysRemaining;
	PersonalTrainer *responsiblePT;
	Gym *gym;
};

#endif /* CLIENT_H_ */
