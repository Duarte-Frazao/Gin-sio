#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include "PersonalTrainer.h"
#include "Gym.h"
#include "Program.h"
#include "ErrorClasses.h"

int filterInput(int inf, int sup);

class PersonalTrainer;
class Gym;


class Client {
	static int clientId ;

	std::string name;
	Program *enrolledProgram;
	int age;
	PersonalTrainer *responsiblePT;
	int id;
	int numDaysRemaining;
	bool insideGym;
	bool paymentsUpToDate;
	int numLatePayments;



public:

	/**Client constructor

	@param clientName Name of the client
	@param program	  Enrolled program subscription
	@param clientAge  Age of the client
	@param PT		Professor responsible for the client
	@return
	*/
	Client(std::string clientName, Program *program, int clientAge, PersonalTrainer *PT);

	/**Client destructor*/
	~Client();

	/** Returns the id of the client
	@param
	@return Returns the id of the client
	*/
	int getId() const;

	/** Returns the name of the client
	@param
	@return Returns the name of the client
	*/
	std::string getName() const;

	/** Returns the age of the client
	@param
	@return Returns the age of the client
	*/
	int getAge() const; //TO-DO a way to update age

	/**
	Returns if the Client is inside or outside the gym

	@param
	@return Returns true if Client is inside the gym and false if outside
	*/
	bool getLocation() const;

	/**
	Returns the status of the payments

	@param
	@return Returns true if Client's payments are up to date, false if not
	*/
	bool getPaymentStatus() const;

	/**
	Returns the number of months not yet payed

	@param
	@return Returns the number of months not yet payed
	*/
	int getNumLatePayments() const;

	/**
	Returns the enrolled Program

	@param
	@return Returns the enrolled Program
	*/
	const Program *getProgram() const;


	/**
	Returns the number of days remaining

	@param
	@return Returns the number of days remaining
	*/
	int getDaysRemaining() const;

	/**
	Returns the personal trainer that is responsible for the Client

	@param
	@return Returns the personal trainer that is responsible for the Client
	*/
	const PersonalTrainer *getPT() const;

	/**
	Sets a new subscription to Client

	@param newProgram The new subscription the Client has choosen to replace the current one
	@return
	*/
	void setProgram(Program *newProgram);

	/**
	Sets a new PersonalTrainer to Client

	@param PT New Personal Trainer choosen to replace the current one
	@return
	*/
	void setPT(PersonalTrainer *PT);

	/**
	Sets a new name to Client

	@param newName New name for Client
	@return
	*/
	void setName(std::string newName);

	/**
	Changes the current location of Client.
	Checks if he's allowed to enter, if not throws an exception

	@param
	@return
	*/
	void changeLocation();

	/** Enters a menu handler to edit client*/
	void editClient();

	/**
	Displays and selects the option for the edit Client menu

	@param 
	@return Returns the menu's option
	*/
	int editClientMenu() const;

	/**
	Returns in the argument vector problems the reasons for not being able to edit the Client
	If the vector wasn't empty it resets the vector to display only the current problems

	@param problems A vector to return the problems
	@return
	*/
	void problems(std::vector<std::string> &problems) const;

	/**
	Updates the number of days remaining after setting a new program
	@param 
	@return
	*/
	void updateNumDaysRemaining();

	/**
	Overload of operator <<
	@param
	@return ostream
	*/
	friend std::ostream & operator<<(std::ostream & out, const Client &client);
	
	/**
	Displays information about Client
	@param
	@return
	*/
	void viewInfo() const;

	//void updatePayments() const;
	//void changeProgram() const;
	//void changePT() const;
	//void editBasicSettings() const; client, name age
};

#endif /* CLIENT_H_ */
