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
#include "Gym.h"

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

	Exercise(std::string name, std::string description, std::vector<Material*> necessaryMaterial, int intensity);
	~Exercise();
	bool isFunctional() const;
	bool isCardio()const;
	bool isHyper() const;
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
	int trainedMuscles() const;
	void generateCardioPlan(Gym &gym);
	std::string getName()const;
	void setName(std::string namei) {namei=name;}
	void setDescription(std::string dI) {description=dI;}
	void setMaterial(std::vector<Material *> m) {necessaryMaterial=m;}
	int getIntensity()const;
	bool includeMuscles(std::vector<std::string> muscles);
	bool includeMuscle(std::string muscle);
	void editExercise(Gym &gym);
	std::vector<bool> getMuscles();

};

#endif /* EXERCISE_H_ */
