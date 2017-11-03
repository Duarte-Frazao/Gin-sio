#ifndef ERROR_CLASSES_H_
#define ERROR_CLASSES_H_


//Library
#include <iostream>
#include <vector>
#include <string>


class EntranceError {
	std::string reason;
public:
	/* brief EntranceError constructor */
	EntranceError(std::string rz) : reason(rz) {}

	/*brief Return error's reason*/
	std::string getReason() const { return reason; }

	/* brief EntranceError operator<< overload*/
	friend std::ostream & operator << (std::ostream &out, const EntranceError &error);
};




class EditingError {
	std::vector<std::string> reasons;
public:
	/* brief EditingError constructor */
	EditingError(std::vector<std::string> rz) : reasons(rz) {}

	/*brief Return error's reason*/
	std::vector<std::string> getReasons() const { return reasons; }

	/* brief EditingError operator<< overload*/
	friend std::ostream & operator << (std::ostream &out, const EditingError &error);
};



class ErrorDate{
private:
	std::string reason;

public:
	ErrorDate(std::string reason) : reason(reason){};
	friend std::ostream & operator<<(std::ostream & out, const ErrorDate & errorDate);
};


#endif
