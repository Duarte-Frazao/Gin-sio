/*
 * Client.h
 *
 *  Created on: 14/10/2017
 *      Author: Sandro Ca
 */

#include "PersonalTrainer.h"

#ifndef CLIENT_H_
#define CLIENT_H_

class Client {
public:
	Client();
	~Client();
private:
	bool presentGym;
	bool paymentsUpToDate;
	int numLatePayments;
	int programEnrolled;
	int numDaysRemaining;
	PersonalTrainer *responsiblePT;
};

#endif /* CLIENT_H_ */
