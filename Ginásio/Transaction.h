#ifndef TRANSACTION_H_
#define TRANSACTION_H_

#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

class Transaction {

	/**
	Overload of operator << for class Transaction
	@return ostream
	*/
	friend std::ostream& operator<<(std::ostream &out, const Transaction &transaction);

public:
	Transaction();
	Transaction(std::string type, double amount);
	~Transaction();

	/**
	Get type of the transaction

	@return Returns the type of the transaction
	*/
	std::string getType() const;

	/**
	Get description of the transaction

	@return Returns the description of the transaction
	*/
	std::string getDescription() const;

	/**
	Get amount of the transaction

	@return Returns the amount of the transaction
	*/
	double getAmount() const;

	/**
	Get the date of the transaction

	@return The date of the transaction
	*/
	std::string getDateTransaction() const;
	
	/**
	Sets the type of the transaction

	@param The type of the transaction
	*/
	void setType(std::string type);

	/**
	Sets the description of the transaction

	@param The description of the transaction
	*/
	void setDescription(std::string description);

	/**
	Sets the amount of the transaction

	@param The amount of the transaction
	*/
	void setAmount(double amount);

	/**
	Sets the date of the transaction

	@param The date of the transaction
	*/
	void setDateTransaction(std::string time);

private:
	std::string type;
	std::string description;
	double amount;
	std::time_t date;
	std::string dateTransaction;
};

#endif