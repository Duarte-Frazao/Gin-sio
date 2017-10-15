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
class PersonalTrainer;
using namespace std;

class EntranceError {
	string reason;
public:
	EntranceError(string rz);
	string getReason() const;
	friend ostream & operator << (ostream &out, EntranceError &error);
};

class Client {
public:

	Client(std::string clientName,int program, int clientAge, PersonalTrainer *PT);
	~Client();
	string getName() const;
	int getAge() const;
	bool getLocation() const;
	bool getPaymentStatus() const;
	int getNumLatePayments() const;
	int getProgram() const;
	int getDaysRemaining() const;
	const PersonalTrainer *getPT() const;
	void setProgram(int newProgram);
	void setPT(PersonalTrainer *PT);
	void changeLocation();

	//void updatePayments() const;
	//void changeProgram() const;
	//void changePT() const;
	//void editBasicSettings() const; client, name age

private:

	std::string name;
	int age;
	bool insideGym;
	bool paymentsUpToDate;
	int numLatePayments;
	int enrolledProgram;
	int numDaysRemaining;
	PersonalTrainer *responsiblePT;
};

#endif /* CLIENT_H_ */
