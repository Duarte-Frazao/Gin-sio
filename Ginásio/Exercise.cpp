/*
 * Exercise.cpp
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#include "Exercise.h"


Exercise::Exercise(bool legsI, bool calvesI, bool cardioI,bool chestI,bool shouldersI,bool bicepsI,
		bool tricepsI, bool abdominalsI,
		bool gluteusI, bool backI, std::string name, std::string descriptionI,
		std::vector<Material*> necessaryMaterialI, int intensity): intensity(intensity), name(name), legs(legsI), calves(calvesI), cardio(cardioI), chest(chestI), shoulders(shouldersI), biceps(bicepsI), triceps(tricepsI), abdominals(abdominalsI), gluteus(gluteusI), back(backI), description(descriptionI) {


}

Exercise::~Exercise() {
	// TODO Auto-generated destructor stub
}


bool Exercise::isFunctional(){
	if (legs && chest &&biceps) return true; //mudar
	return false;
}

bool Exercise::isCardio() {return cardio;}

bool Exercise::legExercise(){
	if (legs ||calves ||gluteus) return true;
	return false;
}

bool Exercise::chestExercise() {return chest;}

bool Exercise::shoulderExercise(){return shoulders;}

bool Exercise::bicepExercise(){return biceps;}

std::vector<Material*> Exercise::getNecessaryMaterial(){return necessaryMaterial;}

std::string Exercise::getDescription(){ return description;}

std::string Exercise::getName(){ return name;}

bool Exercise::calvesExercise(){return calves;}
bool Exercise::shouldersExercise(){return shoulders;}
bool Exercise::tricepsExercise(){return triceps;}
bool Exercise::bicepsExercise(){return biceps;}
bool Exercise::abdominalsExercise(){return abdominals;}
bool Exercise::gluteusExercise(){return gluteus;}
bool Exercise::backExercise(){return back;}

int Exercise::getIntensity(){return intensity;}


std::ostream& operator<<(std::ostream& out,  Exercise& e)
{
	out << e.getName();
	out << "\n";

	if (e.getNecessaryMaterial().size() > 0)
	{
		out << "Necessary material:" << "\n";
		for (uint i =0; i < e.getNecessaryMaterial().size();i++)
		{
			out <<e.getNecessaryMaterial().at(i);
			out << "\n";
		}
	}
	out << "Description: " << e.getDescription() << "\n";
	if (e.isCardio())
	{
		out << "Cardio exercise" << "\n";
	}
	out << "Trained muscles: \n";
	if (e.legExercise()) out << "Legs\n";
	if (e.calvesExercise()) out << "Calves\n";
	if (e.chestExercise()) out << "Chest\n";
	if (e.shouldersExercise()) out << "Shoulders\n";
	if (e.bicepsExercise()) out << "Biceps\n";
	if (e.tricepsExercise()) out << "Triceps\n";
	if (e.abdominalsExercise()) out << "Abdominals\n";
	if (e.gluteusExercise()) out << "Gluteus\n";
	if (e.backExercise()) out << "Back\n";
	out << "-----\n";

	return out;
}

int Exercise::trainedMuscles()
{

	int muscleCounter=0;
	if (legs)muscleCounter++;
	if (calves)muscleCounter++;
	if (chest) muscleCounter++;
	if(shoulders)muscleCounter++;
	if(biceps)muscleCounter++;
	if (triceps)muscleCounter++;
	if(abdominals)muscleCounter++;
	if(gluteus)muscleCounter++;
	if (back)muscleCounter++;
	return muscleCounter;
}


