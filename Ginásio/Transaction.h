#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>

class Transaction {
public:
	Transaction();
	~Transaction();
	std::string getType();
	std::string getDescription();
	int getValue();
	void setType(std::string type);
	void setDescription(std::string description);
	void setValue(int value);
private:
	std::string type;
	std::string description;
	int value;
};

#endif
