/*
 * Material.h
 *
 *  Created on: 17 Nov 2017
 *      Author: duarte
 */

#ifndef MATERIAL_H_
#define MATERIAL_H_


class Material {
	bool machine;
	std::string materialName;
	int machineNumber;
public:
	bool isMachine();
	int getMachineNumber();
	std::string getMaterialName;
	Material();
	~Material();
};

#endif /* MATERIAL_H_ */
