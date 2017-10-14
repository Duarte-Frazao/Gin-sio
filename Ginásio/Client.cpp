/*
 * Client.cpp
 *
 *  Created on: 14/10/2017
 *      Author: Sandro Ca
 */
#include "stdafx.h"
#include "Gym.h"
#include <iostream>

using namespace std;

Client::Client(string clientName, int program, int clientAge, PersonalTrainer *PT):
	insideGym(false), paymentsUpToDate(true), numLatePayments(0), enrolledProgram(program),
	age(clientAge), responsiblePT(PT){
	//To-do initialize numDays remaining based on the program chosen
}

Client::~Client() {

}


