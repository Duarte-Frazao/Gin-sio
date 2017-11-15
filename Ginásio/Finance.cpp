#include <iostream>
#include "stdafx.h"
#include "Finance.h"

using namespace std;

// Finance constructors
Finance::Finance() {
	balance = 0;
}

Finance::~Finance() {

}

vector<Transaction> Finance::getTransactions() {
	return transactions;
}

double Finance::getBalance() {
	return balance;
}

void Finance::setTransactions(vector<Transaction> transactions) {
	this->transactions = transactions;
}

void Finance::setBalance(double balance) {
	this->balance = balance;
}

bool Finance::addTransaction(Transaction newTransaction) {
	if (newTransaction.getType() == "WITHDRAWAL") {
		if (newTransaction.getAmount() > balance) return false;
		transactions.push_back(newTransaction);
		setBalance(balance - newTransaction.getAmount());
		return true;
	}
	else if (newTransaction.getType() == "DEPOSIT") {
		transactions.push_back(newTransaction);
		setBalance(balance + newTransaction.getAmount());
		return true;
	}
	return false;
}

ostream& operator<<(ostream &out, const Finance &finance) {
	out << "---------------- Gym's Finance ----------------\n\n";
	if (finance.transactions.size() == 0)
		out << "	    No transactions found!\n";
	else {
		for (auto pTransaction : finance.transactions)
			out << pTransaction << endl;
	}
	out << "\n      ----------- BALANCE: " << finance.balance << " -----------\n\n";
	return out;
}