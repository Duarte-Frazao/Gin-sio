/*
 * Staff.h
 *
 *  Created on: 14/10/2017
 *      Author: Sandro Ca
 */

#include "Schedule.h"

#ifndef STAFF_H_
#define STAFF_H_

class Staff {
public:
	Staff();
	virtual ~Staff();
private:
	int id, age, wage;
	bool presentGym;
	Schedule workSchedule;
};

#endif /* STAFF_H_ */
