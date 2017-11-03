#include "stdafx.h"
#include <iostream>

/**
Filters an option by giving two limits, makes the user input and integer between them

@param inf Inferior Limit
@param sup Superior Limit
@return
*/
int filterInput(int inf, int sup)
{
	int option;
	bool validValue = true;

	do
	{
		std::cin >> option;
		if (std::cin.fail() || option< inf || option > sup)
		{
			std::cout << "Please enter a valid value\n";
			std::cin.clear();
			std::cin.ignore(100, '\n');
			validValue = false;
		}
		else if(validValue == false) validValue = true;

	} while (!validValue);

	return option;

}
