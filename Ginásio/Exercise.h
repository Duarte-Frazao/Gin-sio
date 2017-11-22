/*
 * Exercise.h
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#ifndef EXERCISE_H_
#define EXERCISE_H_
#include <string>
#include <vector>
#include <iostream>
#include "Material.h"

class Material;

class Exercise {
private:
	bool legs;
	bool calves; //gemeos
	bool cardio;
	bool chest;
	bool shoulders;
	bool biceps;
	bool triceps;
	bool abdominals;
	bool gluteus;
	bool back;
	std::string name;
	std::string description;
	std::vector<Material*> necessaryMaterial;
	int intensity;
public:
	Exercise(bool legs, bool calves, bool cardio,bool chest,bool shoulders,bool biceps,
			bool triceps, bool abdominals, bool gluteus,
			bool back,std::string name, std::string description, std::vector<Material*> necessaryMaterial, int intensity);
	~Exercise();
	bool isFunctional();
	bool isCardio();
	bool legExercise();
	bool chestExercise();
	bool shoulderExercise();
	bool bicepExercise();
	bool calvesExercise();
	bool shouldersExercise();
	bool tricepsExercise();
	bool bicepsExercise();
	bool abdominalsExercise();
	bool gluteusExercise();
	bool backExercise();

	std::vector<Material*> getNecessaryMaterial();
	std::string getDescription();
	friend std::ostream& operator<<(std::ostream& out,const  Exercise& e);
	int trainedMuscles();
	std::string getName();
	int getIntensity();

};

#endif /* EXERCISE_H_ */
