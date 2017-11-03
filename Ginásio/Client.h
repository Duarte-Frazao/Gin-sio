/*
* Client.h
*
*  Created on: 14/10/2017
*      Author: Sandro Ca
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include "PersonalTrainer.h"
#include "Gym.h"
#include "Program.h"
using namespace std;

/**
Filters an option by giving two limits, makes the user input and integer between them

@param inf Inferior Limit
@param sup Superior Limit
@return
*/
int filterInput(int inf, int sup);

class PersonalTrainer;
class Gym;

class EntranceError {
	string reason;
public:
	/** Entrance error constructor
	@param rz Reason for the error
	@return 
	*/
	EntranceError(string rz);

	/** Returns the reason for the error
	@param
	@return Reason causing the error
	*/
	string getReason() const;

	/**Overload of the << operator
	@param out Output Stream
	@param error Entrance Error object
	@return out Output Stream
	*/
	friend ostream & operator << (ostream &out, const EntranceError &error);
};

class EditingError {
	vector<string> reasons;
public:
	/** Editing error constructor
	@param rz Reason for the error
	@return
	*/
	EditingError(vector<string> rz);

	/** Returns the reasons for the error
	@param
	@return Reasons causing the error
	*/
	vector<string> getReasons() const;

	/**Overload of the << operator
	@param out Output Stream
	@param error Editing Error object
	@return out Output Stream
	*/
	friend ostream & operator << (ostream &out, const EditingError &error);
};

/**


@param
@return 
*/
class Client {
public:

	/**Client constructor

	@param clientName Name of the client
	@param program	  Enrolled program subscription
	@param clientAge  Age of the client
	@param PT		Professor responsible for the client
	@return
	*/
	Client::Client(string clientName, Program *program, int clientAge, PersonalTrainer *PT);

	/**Client destructor

	*/
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
	string getName() const;

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
	Returns the gym the client is signed
	@param
	@return Returns the gym the client is signed
	*/
	const Gym *getGym() const;

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
	Sets a new gym to the Client

	@param newGym New gym for client 
	@return
	*/
	void setGym(Gym *newGym);

	/**
	Sets a new name to Client

	@param newName New name for Client
	@return
	*/
	void setName(string newName);

	/**
	Changes the current location of Client.
	Checks if he's allowed to enter, if not throws an exception

	@param
	@return
	*/
	void changeLocation();

	/** Enters a menu handler to edit client


	@param 
	@return
	*/
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
	void problems(vector<string> &problems) const;

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

private:

	string name;
	int id, age;
	static int clientId ;
	bool insideGym;
	bool paymentsUpToDate;
	int numLatePayments;
	Program *enrolledProgram;
	int numDaysRemaining;
	PersonalTrainer *responsiblePT;
	Gym *gym;
};

#endif /* CLIENT_H_ */
