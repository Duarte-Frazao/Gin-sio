/*
 * Plan.cpp
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#include "Plan.h"
#include <iostream>

Plan::Plan(){}

Plan::Plan(std::vector<Exercise*> exercisesI, std::string planTypeI): exercises(exercisesI), planType(planTypeI){
	// TODO Auto-generated constructor stub

}

Plan::~Plan() {
	// TODO Auto-generated destructor stub
}

std::ostream & Plan::operator<<(std::ostream &out){
	out << "Program objective: " << planType << "\n";
	for (auto &exercise:exercises) out << exercise;
	return out;
}

std::vector<Exercise*> Plan::getExercises(){return exercises;}

std::string  Plan::getPlanType(){return planType;}

