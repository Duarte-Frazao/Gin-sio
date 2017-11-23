#ifndef ERROR_CLASSES_H_
#define ERROR_CLASSES_H_


//Library
#include <iostream>
#include <vector>
#include <string>


class EntranceError {
	std::string reason;
public:
	/** Entrance error constructor
		@param rz Reason for the error
		@return
		*/
	EntranceError(std::string rz) : reason(rz) {}

	/** Returns the reason for the error
		@param
		@return Reason causing the error
		*/
	std::string getReason() const { return reason; }

	/**Overload of the << operator
		@param out Output Stream
		@param error Entrance Error object
		@return out Output Stream
		*/
	friend std::ostream & operator << (std::ostream &out, const EntranceError &error);
};




class EditingError {
	std::vector<std::string> reasons;
public:
	/** Editing error constructor
		@param rz Reason for the error
		@return
		*/
	EditingError(std::vector<std::string> rz) : reasons(rz) {}

	/** Returns the reasons for the error
		@param
		@return Reasons causing the error
		*/
	std::vector<std::string> getReasons() const { return reasons; }

	/**Overload of the << operator
		@param out Output Stream
		@param error Editing Error object
		@return out Output Stream
		*/
	friend std::ostream & operator << (std::ostream &out, const EditingError &error);
};



class ErrorDate{
private:
	std::string reason;

public:
	ErrorDate(std::string reason) : reason(reason){};
	friend std::ostream & operator<<(std::ostream & out, const ErrorDate & errorDate);
};



class InvalidValue {
	std::string reason;
public:
	InvalidValue(std::string rz) : reason(rz) {}
	std::string getReason() const {return reason;}
	friend std::ostream & operator << (std::ostream &out, const InvalidValue &error);
};
#endif
