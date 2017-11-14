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
	Gym * FitnessMx= readInformationFile("File.txt");
	mainMenu(*FitnessMx);
	writeInformationFile("outFile", *FitnessMx);
	return 0;
}

