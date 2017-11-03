#include "stdafx.h"
#include "ErrorClasses.h"
#include <iostream>


std::ostream & operator << (std::ostream &out, const EntranceError &error) {
	out << "Error registring client's entry" << std::endl;
	out << "Reason: " << error.reason << std::endl;
	return out;
}


std::ostream & operator << (std::ostream &out, const EditingError &error) {
	out << "Error editing client" << std::endl;

	if (error.reasons.size() == 1)out << "Reason: " << error.reasons.at(0) << std::endl;
	else
	{
		out << "Reasons: " << std::endl;
		for (size_t i = 0; i < error.reasons.size() - 1; i++)
		{
			out << error.reasons.at(i) << std::endl;
		}
	}
	return out;
}


std::ostream & operator<<(std::ostream & out, const ErrorDate & errorDate){
	out << errorDate.reason;
	return out;
}

std::ostream & operator << (std::ostream &out, const InvalidValue &error) {
	out << "Error registring staff's wage!" << std::endl;
	out << "Reason: " << error.reason << std::endl;
	return out;
}

