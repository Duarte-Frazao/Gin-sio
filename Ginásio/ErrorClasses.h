#ifndef ERROR_CLASSES_H_
#define ERROR_CLASSES_H_


//Library
#include <iostream>
#include <vector>
#include <string>


class EntranceError {
	std::string reason;
public:
	/** 
	@brief Entrance error constructor
	@param rz Reason for the error
	*/
	EntranceError(std::string rz) : reason(rz) {}

	/** 
	@brief Returns the reason for the error
	@return Reason causing the error
	*/
	std::string getReason() const { return reason; }

	/** 
	@brief Overload of the << operator
	@param out Output Stream
	@param error Entrance Error object
	@return out Output Stream
	*/
	friend std::ostream & operator << (std::ostream &out, const EntranceError &error);
};




class EditingError {
	std::vector<std::string> reasons;
public:
	/** 
	@brief Editing error constructor
	@param rz Reason for the error
	*/
	EditingError(std::vector<std::string> rz) : reasons(rz) {}

	/**
	@brief Returns the reasons for the error
	@return Reasons causing the error
	*/
	std::vector<std::string> getReasons() const { return reasons; }

	/** 
	@brief Overload of the << operator
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

	/** 
	@brief Returns the reason for the error
	@return Reason causing the error
	*/
	std::string getReason() const { return reason; }

	/**
	@brief Overload of the << operator
	@param out Output Stream
	@param error Editing Error object
	@return out Output Stream
	*/
	friend std::ostream & operator<<(std::ostream & out, const ErrorDate & errorDate);
};



class InvalidValue {
	std::string reason;
public:
	InvalidValue(std::string rz) : reason(rz) {}

	/** 
	@brief Returns the reason for the error
	@return Reason causing the error
	*/
	std::string getReason() const {return reason;}

	/**
	@brief Overload of the << operator
	@param out Output Stream
	@param error Editing Error object
	@return out Output Stream
	*/
	friend std::ostream & operator << (std::ostream &out, const InvalidValue &error);
};
#endif
