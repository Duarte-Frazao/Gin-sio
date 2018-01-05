#ifndef FINANCE_H_
#define FINANCE_H_

#include <vector>
#include "Transaction.h"

class Finance {

	/**
	@brief Overload of operator << for class Finance
	@param out ostream
	@param finance Finance
	@return ostream
	*/
	friend std::ostream& operator<<(std::ostream &out, const Finance &finance);

public:

	Finance();

	virtual ~Finance();

	/**
	@brief Get vector of transactions
	@return Returns the vector of transactions
	*/
	std::vector<Transaction> getTransactions();

	/**
	@brief Get gym's account balance
	@return Returns gym's account balance
	*/
	double getBalance();

	/**
	@brief Sets the vector of transactions
	@param The vector of transactions
	*/
	void setTransactions(std::vector<Transaction> transactions);

	/**
	@brief Sets the balance of the gym account
	@param The gym balance
	*/
	void setBalance(double balance);

	/**
	@brief Adds a new transaction to the vector of transactions
	@param The new transaction
	@return Returns if transaction is feasible
	*/
	bool addTransaction(Transaction newTransaction);

private:

	std::vector<Transaction> transactions;
	double balance;
};

#endif /* FINANCE_H_ */
