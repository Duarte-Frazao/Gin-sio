#ifndef CLIENT_H_
#define CLIENT_H_

#include <string>
#include "PersonalTrainer.h"
#include "Gym.h"
#include "Program.h"

class PersonalTrainer;
class Gym;

using namespace std;

class Client {

	std::string name;
	Program *enrolledProgram;
	int age;
	Gym *gym;
	PersonalTrainer *responsiblePT;
	int id;
	static int clientId;
	bool insideGym;
	bool paymentsUpToDate;
	int numLatePayments;
	int numDaysRemaining;

public:

	Client(string clientName, Program *program, int clientAge,Gym *gym, PersonalTrainer *PT);
	~Client();
	int getId() const;

	/**
	Returns the name of a Client

	@param
	@return Name of Client
	*/
	string getName() const;

	/**
	Returns the age of a Client

	@param
	@return returns the age of a Client
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
	Sets a new name to Client

	@param newName New name for Client
	@return
	*/
	void setGym(Gym *prorgamGym);
	void setName(string newName);

	/**
	Changes the current location of Client.
	Checks if he's allowed to enter, if not throws an exception

	@param
	@return
	*/
	void changeLocation();

	/**
	Edits a Client
	*/
	void editClient();


	int editClientMenu() const;

	/**
	Returns in the argument vector problems the reasons for not being able to edit the Client
	If the vector wasn't empty it resets the vector to display only the current problems

	@param problems A vector to return the problems
	@return
	*/
	void problems(vector<string> &problems) const;


	//void updateNumDaysRemaining(Program *newProgram);
	//void updatePayments() const;
	//void changeProgram() const;
	//void changePT() const;
	//void editBasicSettings() const; client, name age
};

#endif /* CLIENT_H_ */
