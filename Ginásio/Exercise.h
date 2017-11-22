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
	bool isFunctional() const;
	bool isCardio()const;
	bool legExercise()const;
	bool chestExercise()const;
	bool shoulderExercise()const;
	bool bicepExercise()const;
	bool calvesExercise()const;
	bool shouldersExercise()const;
	bool tricepsExercise()const;
	bool bicepsExercise()const;
	bool abdominalsExercise()const;
	bool gluteusExercise()const;
	bool backExercise()const;

	std::vector<Material*> getNecessaryMaterial()const;
	std::string getDescription()const;
	friend std::ostream& operator<<(std::ostream& out,const Exercise & e);
	int trainedMuscles();
	std::string getName()const;
	int getIntensity()const;

};

#endif /* EXERCISE_H_ */
