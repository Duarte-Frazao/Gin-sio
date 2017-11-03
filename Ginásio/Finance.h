#ifndef FINANCE_H_
#define FINANCE_H_

#include <vector>
#include "Transaction.h"

class Finance {
public:
	Finance();
	virtual ~Finance();
private:
	std::vector<Transaction> transactions;
};

#endif /* FINANCE_H_ */
