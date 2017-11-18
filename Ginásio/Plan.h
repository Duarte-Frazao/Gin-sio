/*
 * Plan.h
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#ifndef PLAN_H_
#define PLAN_H_

#include "Exercise.h"



class Plan {
private:
	std::vector<Exercise> exercises;
	std::string planType; //Functional, cardio, hypertrophism...
	//int date; data de criacao, para haver renovação de 3 em 3 meses
public:
	Plan(std::vector<Exercise> exercises, std::string planType);
	~Plan();
};

#endif /* PLAN_H_ */
