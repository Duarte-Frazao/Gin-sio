#ifndef FINANCE_H_
#define FINANCE_H_

#include <vector>
#include "Transaction.h"

class Finance {

	/**
	Overload of operator << for class Finance
	@return ostream
	*/
	friend std::ostream& operator<<(std::ostream &out, const Finance &finance);

public:

	/* Finance constructor */
	Finance();

	/* Finance destructor */
	virtual ~Finance();

	/**
	Get vector of transactions

	@return Returns the vector of transactions
	*/
	std::vector<Transaction> getTransactions();

	/**
	Get gym's account balance

	@return Returns gym's account balance
	*/
	double getBalance();

	/**
	Sets the vector of transactions

	@param The vector of transactions
	*/
	void setTransactions(std::vector<Transaction> transactions);

	/**
	Sets the balance of the gym account

	@param The gym balance
	*/
	void setBalance(double balance);

	/**
	Adds a new transaction to the vector of transactions

	@return Returns if transaction is feasible
	@param The new transaction
	*/
	bool addTransaction(Transaction newTransaction);

private:

	std::vector<Transaction> transactions;
	double balance;
};

#endif /* FINANCE_H_ */
