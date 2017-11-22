/*
 * Material.cpp
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#include "Material.h"
#include <iostream>

Material::Material(bool machine, std::string materialName, int machineNumber): machine(machine), materialName(materialName), machineNumber(machineNumber) {

}

Material::~Material() {
	// TODO Auto-generated destructor stub
}

bool Material::isMachine(){ return machine;}

int Material::getMachineNumber() {return machineNumber;}

std::ostream & Material::operator<<(std::ostream &out)
{
	if (!machine) out << "Material: " <<materialName << "\n";
	else out << "Machine: " << materialName << " Number: " << machineNumber << "\n";
	return out;
}
