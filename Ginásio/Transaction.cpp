#include "Transaction.h"

using namespace std;

// Transaction constructor
Transaction::Transaction() {value = 0;}

// Transaction destructor
Transaction::~Transaction() {

}

#pragma region Gets

string Transaction::getType() {
	return type;
}

string Transaction::getDescription() {
	return description;
}

int Transaction::getValue() {
	return value;
}

#pragma endregion

#pragma region Sets

void Transaction::setType(string type) {
	this->type = type;
}

void Transaction::setDescription(string description) {
	this->description = description;
}

void Transaction::setValue(int value) {
	this->value = value;
}

#pragma endregion
