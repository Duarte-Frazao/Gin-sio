/*
* Transaction.h
*
*  Created on: 21/10/2017
*      Author: Sandro Ca
*/

#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>
using namespace std;

class Transaction {
public:
	Transaction();
	~Transaction();
	string getType();
	string getDescription();
	int getValue();
	void setType(string type);
	void setDescription(string description);
	void setValue(int value);
private:
	string type;
	string description;
	int value;
};

#endif