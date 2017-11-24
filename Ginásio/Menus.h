#include "Gym.h"


/** Display Main Menu
	@param gym Gym
	@return
	*/
void mainMenu(Gym &gym);

/** Display and change gym attributes
	@param gym Gym
	@return
	*/
void gymMenu(Gym &gym);

/** Display change, edit and add client's attributes
	@param gym Gym
	@return
	*/
void clientMenu(Gym &gym);

/** Display change, edit and add staff attributes
	@param gym Gym
	@return
	*/
void staffMenu(Gym &gym);

/** Display change, edit and add personal trainer attributes
	@param gym Gym
	@return
	*/
void personalTrainerMenu(Gym &gym);

/** Display and make transactions
	@param gym Gym
	@return
	*/
void financeMenu(Gym &gym);

/** Add, edit and delete clients subscriptions
	@param gym Gym
	@return
	*/
void subscriptionsMenu(Gym &gym);

/** Change gym capacity
	@param gym Gym
	@return
	*/
void capacityMenu(Gym &gym);

/** Read client id and test if it's correct
	@param optionClient Client ID
	@param gym Gym
	@param client_found Return client object that was found
	@return
	*/
void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);

/** Read Staff id and test if it's correct
	@param optionClient Staff ID
	@param gym Gym
	@param staff_found Return Staff object that was found
	@return
	*/
void inputStaffIdObj(int &optionStaff, Gym &gym, Staff** staff_found);

/** Read personal trainer id and test if it's correct
	@param optionClient personal trainer ID
	@param gym Gym
	@param staff_found Return personal trainer object that was found
	@return
	*/
void inputPtIdObj(int &optionPt, Gym &gym, Staff** staff_found);

/** Read program id and test if it's correct
	@param optionClient program ID
	@param gym Gym
	@param program_found Return program object that was found
	@return
	*/
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found);

/** Display press key message
	@param
	@return
	*/
void intervalFuntion();

/** Display press key message
	@param inf Inferior Limit
	@param sup Superior Limit
	@param msg Output message to ask for input
	@return
	*/
int filterInput(int inf, int sup,std::string msg = "Selection: ");

/** Display client's information ordered by id, name and age
	@param gym Gym
	@return
	*/
void listClient(Gym &gym);

/** Display staff's information ordered by id, name and age
	@param gym Gym
	@return
	*/
void listStaff(Gym &gym);

/** Display personal trainer information ordered by id, name and age
	@param gym Gym
	@return
	*/
void listPT(Gym &gym);
