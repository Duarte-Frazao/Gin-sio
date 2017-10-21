/*
 * Finance.h
 *
 *  Created on: 14/10/2017
 *      Author: Sandro Ca
 */

#include <vector>
#include "Transaction.h"
using namespace std;

#ifndef FINANCE_H_
#define FINANCE_H_

class Finance {
public:
	Finance();
	virtual ~Finance();
private:
	vector<Transaction> transactions;
};

#endif /* FINANCE_H_ */
