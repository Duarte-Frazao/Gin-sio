/*
 * Exercise.cpp
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#include "Exercise.h"


Exercise::Exercise(bool legsI, bool calvesI, bool cardioI,bool chestI,bool shouldersI,bool bicepsI,
		bool tricepsI, bool abdominalsI,
		bool gluteusI, bool backI, std::string descriptionI,
		std::vector<Material> necessaryMaterialI): legs(legsI), calves(calvesI), cardio(cardioI), chest(chestI), shoulders(shouldersI), biceps(bicepsI), triceps(tricepsI), abdominals(abdominalsI), gluteus(gluteusI), back(backI), description(descriptionI) {


}

Exercise::~Exercise() {
	// TODO Auto-generated destructor stub
}

