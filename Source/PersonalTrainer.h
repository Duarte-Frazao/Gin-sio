/*
 * PersonalTrainer.h
 *
 *  Created on: 14/10/2017
 *      Author: Sandro Ca
 */

#include <vector>
#include <string>
#include "Staff.h"
#include "Client.h"

#ifndef PERSONALTRAINER_H_
#define PERSONALTRAINER_H_

class PersonalTrainer : public Staff {
public:
	PersonalTrainer();
	virtual ~PersonalTrainer();
private:
	std::vector<Client *> clientes;
	std::string areaConhecimento;
};

#endif /* PERSONALTRAINER_H_ */
