/*
 * Exercise.cpp
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#include "Exercise.h"
#include <string>
#include <vector>

using namespace std;


int filterInput(int inf, int sup, std::string msg);
vector<string> selectMuscles();
vector<Material *> getMaterial();

Exercise::Exercise(bool legsI, bool calvesI, bool cardioI, bool chestI,
		bool shouldersI, bool bicepsI, bool tricepsI, bool abdominalsI,
		bool gluteusI, bool backI, std::string name, std::string descriptionI,
		std::vector<Material*> necessaryMaterialI, int intensity) :
		intensity(intensity), name(name), legs(legsI), calves(calvesI), cardio(
				cardioI), chest(chestI), shoulders(shouldersI), biceps(bicepsI), triceps(
				tricepsI), abdominals(abdominalsI), gluteus(gluteusI), back(
				backI), description(descriptionI),necessaryMaterial(necessaryMaterialI) {



}

Exercise::Exercise(std::string name, std::string description, std::vector<Material*> necessaryMaterial, int intensity):name(name),description(description), necessaryMaterial(necessaryMaterial){

};

Exercise::~Exercise() {
	// TODO Auto-generated destructor stub
}


bool Exercise::isFunctional()const{
	if (legs && chest &&biceps) return true; //mudar
	return false;
}

bool Exercise::isCardio() const{return cardio;}

bool Exercise::legExercise()const{
	if (legs ||calves ||gluteus) return true;
	return false;
}

bool Exercise::chestExercise() const{return chest;}

bool Exercise::shoulderExercise()const{return shoulders;}

bool Exercise::bicepExercise()const{return biceps;}

std::vector<Material*> Exercise::getNecessaryMaterial()const{return necessaryMaterial;}

std::string Exercise::getDescription()const{ return description;}

std::string Exercise::getName()const{ return name;}

bool Exercise::calvesExercise()const{return calves;}
bool Exercise::shouldersExercise()const{return shoulders;}
bool Exercise::tricepsExercise()const{return triceps;}
bool Exercise::bicepsExercise()const{return biceps;}
bool Exercise::abdominalsExercise()const{return abdominals;}
bool Exercise::gluteusExercise()const{return gluteus;}
bool Exercise::backExercise()const{return back;}

int Exercise::getIntensity()const{return intensity;}


std::ostream& operator<<(std::ostream& out, const Exercise & e)
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
	out << "\nDescription: " << e.getDescription() << "\n\n";
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

int Exercise::trainedMuscles() const
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

bool Exercise::isHyper() const
{
	if(cardio) return false;
	if(trainedMuscles()<= 3) return true;
	return false;
}

std::vector<bool> Exercise::getMuscles(){
	vector<bool> arrayBool = {legs, calves, cardio, chest, shoulders, biceps, triceps, abdominals, gluteus, back};
	return arrayBool;
}

//Edits a Client
void Exercise::editExercise(Gym &gym)
{
	string name,description;
	vector<string> vs;
	vector<string> sections = { "\t1.	Change Muscles" ,"\t2.	Name" ,"\t3.	Necessary Material" ,"\t4.	Description" ,"\t5.	See current state of the exercise", "\n\t0.	Leave\n" };
	bool continueInMenu = true;
	vector <Material *> necessaryMaterial;
	do{
		cout << endl << "\t 	What do you want to change in the exercise: " <<getName() << endl;
		cout << "\t--------------------------" << endl << endl;

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size(), "");
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			vs= selectMuscles();
			this->includeMuscles(vs);
			break;
		case 2:
			cout << "New name: ";
			cin >> name;
			this->setName(name);
			break;
		case 3:
			getMaterial();
			this->setMaterial(necessaryMaterial);
			break;
		case 4:
			cout << "New description: ";
			cin >> description;
			this->setDescription(description);
			break;
		case 5:
			cout <<*this;
			break;
		default:
			break;
		}
	}while (continueInMenu);

}
