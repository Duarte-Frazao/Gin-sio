/*
 * Plan.cpp
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#include "Plan.h"
#include <iostream>
#include "Exercise.h"

Plan::Plan(){}

Plan::Plan(std::vector<Exercise*> exercisesI, std::string planTypeI): exercises(exercisesI), planType(planTypeI){
	// TODO Auto-generated constructor stub

}

Plan::~Plan() {
	// TODO Auto-generated destructor stub
}

std::ostream & operator<<(std::ostream &out,const Plan &p1){
	out << "Program objective: " << p1.planType << "\n";
	for (auto exercise : p1.exercises) out << *exercise;
	return out;
}

std::vector<Exercise*> Plan::getExercises(){return exercises;}

std::string  Plan::getPlanType(){return planType;}

