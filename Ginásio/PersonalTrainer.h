/*
* PersonalTrainer.h
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/

#ifndef PERSONALTRAINER_H_
#define PERSONALTRAINER_H_

#include <vector>
#include <string>
#include "Staff.h"
#include "Client.h"
using namespace std;

class Client;
class PersonalTrainer : public Staff {
public:
	PersonalTrainer(int id, int age, int wage, string specializedArea);
	virtual ~PersonalTrainer();
	vector<Client *> getClients() const;
	string getSpecializedArea() const;
	void setSchedule(Schedule workSchedule);
	void setClients(vector<Client *> clients);
private:
	vector<Client *> clients;
	string specializedArea;
};

#endif /* PERSONALTRAINER_H_ */
