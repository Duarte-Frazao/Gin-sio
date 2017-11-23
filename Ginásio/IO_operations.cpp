#include "stdafx.h"
#include <iostream>
#include <string>
#include "termcolor.hpp"


/**
Filters an option by giving two limits, makes the user input and integer between them

@param inf Inferior Limit
@param sup Superior Limit
@return
*/


int filterInput(int inf, int sup, std::string msg)
{
	int option;
	bool validValue;
	std::string value_str;

	do
	{
		if (msg != "")
			std::cout << sign::question << msg;

		validValue = true;

		getline(std::cin, value_str);
		if (value_str.length() == 0) {
			std::cout << sign::error << "Please insert a value.\n\n";
			validValue = false;
		}

		for (size_t i = 0; i < value_str.length(); i++) {
			if (!isdigit(value_str.at(i))) {
				std::cout << sign::error << "Please insert a valid value.\n\n";
				validValue = false;
				break;
			}
		}

		if (validValue) {
			option = stoi(value_str);
			if (option< inf || option > sup)
			{
				std::cout << sign::error << "Please enter a valid value.\n\n";
				validValue = false;
			}
		}

	} while (!validValue);
	std::cout << std::endl << std::endl;

	return option;

}