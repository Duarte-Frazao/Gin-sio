#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>

class Transaction {
	std::string type;
	std::string description;
	int value;

public:
	Transaction();
	~Transaction();
	std::string getType();
	std::string getDescription();
	int getValue();
	void setType(std::string type);
	void setDescription(std::string description);
	void setValue(int value);
};

#endif
