/*
 * Date.h
 *
 *  Created on: 11/10/2017
 *      Author: Windows10
 */

#ifndef DATE_H_
#define DATE_H_

class Date {
public:
	Date(int hour, int min, int weekDay);

private:
	int weekDay, hour, min;
};

#endif /* DATE_H_ */
