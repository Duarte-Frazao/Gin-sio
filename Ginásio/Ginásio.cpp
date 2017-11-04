// Ginásio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Gym.h"
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void mainMenu(Gym &gym);
void gymMenu(Gym &gym);
void clientMenu(Gym &gym);
void staffMenu(Gym &gym);
Gym * readInformationFile(std::string fileName);
void writeInformationFile(std::string fileName, Gym & gym);

int main()
{
/*

	vector <Program *> programs
	{
		new Program(1),
		new Program(2)
	};

	vector <PersonalTrainer *> pts
	{
		new PersonalTrainer(30, 500, "Karate"),
		new PersonalTrainer(30, 500, "Jogging")
	};

	vector <Client *> clients
	{
		new Client("Sandro", programs.at(0), 20, pts.at(0)),
		new Client("Duarte", programs.at(1), 20, pts.at(1)),
		new Client("Cesar", programs.at(0), 20, pts.at(1)),
		new Client("Ana", programs.at(1), 20, pts.at(0))
	};

	vector<Staff *> staff
	{
		pts.at(0),
		pts.at(1)
	};

	//Falta um set para os PersonalTrainer

	Schedule sched;
	Finance fin;

	Gym GoGym("GoGym", programs,clients, staff, pts, sched, 30, 30, fin);

	GoGym.setClients(clients);
	GoGym.setStaff(staff);
	staff.at(0)->setPassword("123");
	*/
	//GoGym.login();



	Gym * FitnessMx= readInformationFile("File.txt");
	mainMenu(*FitnessMx);
	writeInformationFile("outFile", *FitnessMx);
    return 0;
}

