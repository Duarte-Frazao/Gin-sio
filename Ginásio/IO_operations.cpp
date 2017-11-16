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
	bool validValue = true;

	do
	{
		if(msg != "")
			std::cout<< sign::question <<msg;
		std::cin >> option;
		if (std::cin.fail() || option< inf || option > sup)
		{
			std::cout << sign::error << "Please enter a valid value.\n\n";
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			validValue = false;
		}
		else if(validValue == false) validValue = true;

	} while (!validValue);
	std::cout << std::endl << std::endl;

	return option;

}




