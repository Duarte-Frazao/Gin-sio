/*
 * Material.h
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_
#include <string>


class Material {
	bool machine;
	std::string materialName;
	int machineNumber;
public:
	bool isMachine();
	int getMachineNumber();
	std::string getMaterialName();
	Material(bool machine, std::string materialName, int machineNumber);
	~Material();
	std::ostream & operator<<(std::ostream &out);
};

#endif /* MATERIAL_H_ */
