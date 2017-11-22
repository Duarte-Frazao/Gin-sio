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
	std::vector<Exercise*> exercises;
	std::string planType; //Functional, cardio, hypertrophism...
	//int date; data de criacao, para haver renovação de 3 em 3 meses Adicionar objeto que criar tempo, para poder fazer cenas fiches com isto
public:
	Plan();
	Plan(std::vector<Exercise*> exercises, std::string planType);
	~Plan();
	friend std::ostream & operator<<(std::ostream &out,const Plan &p1);
	std::vector<Exercise*> getExercises() ;
	std::string  getPlanType();
};

#endif /* PLAN_H_ */
