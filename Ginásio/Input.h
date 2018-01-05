#include <string>
#include <iostream>

/**
Accepts a string of input and returns
the respective T value. iI it contains
any alphabetic char, requires new input

@param input Input as a template T
@param msg Message as a string to output
*/
template<class T>
void getInput(T &input, std::string msg = "") {

	std::string value_str;
	bool newInput, isDouble;
	std::cin.clear();
	if (std::cin.peek() == '\n') std::cin.ignore();

	std::cout << msg;
	do {
		newInput = false;
		isDouble = false;

		getline(std::cin, value_str);
		if (value_str.length() == 0) {
			std::cout << sign::error << "Please insert a valid value! ";
			newInput = true;
		}
		else {
			for (size_t i = 0; i < value_str.length(); i++) {
				if (!isdigit(value_str.at(i))) {
					if (value_str.at(i) != '.') {
						std::cout << sign::error << "Please insert a valid value! ";
						newInput = true;
						break;
					}
					else {
						isDouble = true;
					}
				}
			}
		}
	} while (newInput);

	if (isDouble) input = stod(value_str);
	else input = stoi(value_str);
}
