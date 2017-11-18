/*
 * Exercise.h
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#ifndef EXERCISE_H_
#define EXERCISE_H_


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
	std::string description;
	std::vector<Material> necessaryMaterial;
public:
	Exercise(bool legs, bool calves, bool cardio,bool chest,bool shoulders,bool biceps,
			bool triceps, bool abdominals, bool gluteus,
			bool back, std::string description, std::vector<Material> necessaryMaterial);
	~Exercise();
	bool isFunctional();
	bool isCardio();
	bool legExercise();
	bool chestExercise();
	bool shoulderExercise();
	bool bicepExercise();
	std::vector<Material> getNecessaryMaterial();
	std::string getDescription();
	std::ostream &operator<<(std::ostream &out);
	int traiedMuscles();

};

#endif /* EXERCISE_H_ */
