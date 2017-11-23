#include "Gym.h"

void mainMenu(Gym &gym);
void gymMenu(Gym &gym);
void clientMenu(Gym &gym);
void staffMenu(Gym &gym);
void personalTrainerMenu(Gym &gym);
void financeMenu(Gym &gym);
void subscriptionsMenu(Gym &gym);
void capacityMenu(Gym &gym);
void inputClientIdObj(int &optionClient, Gym &gym, Client** client_found);
void inputStaffIdObj(int &optionStaff, Gym &gym, Staff** staff_found);
void inputPtIdObj(int &optionPt, Gym &gym, Staff** staff_found);
void inputProgramIdObj(int &optionProgram, Gym &gym, Program** program_found);
void intervalFuntion();
int filterInput(int inf, int sup,std::string msg = "Selection: ");
void listClient(Gym &gym);
void listStaff(Gym &gym);
void listPT(Gym &gym);
