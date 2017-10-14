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

class Client {
public:

	Client(std::string clientName,int program, int clientAge, PersonalTrainer *PT);
	~Client();
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
