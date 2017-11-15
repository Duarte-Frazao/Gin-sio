#include "stdafx.h"
#include "Transaction.h"

using namespace std;

// Transaction constructors
Transaction::Transaction() { 
	amount = 0; 
	date = time(NULL);
	dateTransaction = asctime(localtime(&date));
}

Transaction::Transaction(string type, double amount) {
	this->type = type;
	this->amount = amount;
	date = time(NULL);
	dateTransaction = asctime(localtime(&date));
}

// Transaction destructor
Transaction::~Transaction() {

}

#pragma region Gets

string Transaction::getType() const {
	return type;
}

string Transaction::getDescription() const {
	return description;
}

double Transaction::getAmount() const {
	return amount;
}

string Transaction::getDateTransaction() const {
	return dateTransaction;
} 

#pragma endregion

#pragma region Sets

void Transaction::setType(string type) {
	this->type = type;
}

void Transaction::setDescription(string description) {
	this->description = description;
}

void Transaction::setAmount(double amount) {
	this->amount = amount;
}

void Transaction::setDateTransaction(string time) {
	dateTransaction = time;
} 

#pragma endregion

ostream& operator<< (ostream &out, const Transaction &transaction) {
	out << right << setw(10) << transaction.type << " ------- " 
		<< left << setw(6) << transaction.amount << transaction.getDateTransaction();
	return out;
}