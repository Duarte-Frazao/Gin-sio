//Library
#include "stdafx.h"
#include "Gym.h"
#include <iostream>
#include "Client.h"
#include "ErrorClasses.h"
#include "Material.h"
#include <algorithm>

//Functions
int filterInput(int inf, int sup,std::string msg = "Selection: ");

using namespace std;


int Client::clientId = 0;


//Client constructor
Client::Client(string clientName, Program *program, int clientAge,PersonalTrainer *PT = NULL) :
		name(clientName), enrolledProgram(program), age(clientAge), responsiblePT(
				PT), id(++clientId), insideGym(false), paymentsUpToDate(
				true), numLatePayments(0) {
	//To-do initialize numDays remaining based on the program chosen
	numDaysRemaining = program->getDays();
}


//Client destructor
Client::~Client() {

}

#pragma region Gets
//getId
int Client::getId() const {
	return id;
}

//getName
string Client::getName() const
{
	return name;
}

//Returns the age of a Client
int Client::getAge() const
{
	return age;
}

/**
Returns if the Client is inside or outside the gym

@param 
@return Returns true if Client is inside the gym and false if outside
*/
bool Client::getLocation() const
{
	return insideGym;
}

//Returns the status of the payments

bool Client::getPaymentStatus() const
{
	return paymentsUpToDate;
}

//Returns the number of months not yet payed
int Client::getNumLatePayments() const
{
	return numLatePayments;
}

//Returns the enrolled Program

const Program *Client::getProgram() const
{
	return this->enrolledProgram;
}

//Returns the number of days remaining
int Client::getDaysRemaining() const
{
	return numDaysRemaining;
}

//Returns the personal trainer that is responsible for the Client
const PersonalTrainer *Client::getPT() const
{
	return this->responsiblePT;
}


#pragma endregion

#pragma region Sets

//Sets a new subscription to Client
void Client::setProgram(Program *newProgram)
{
	enrolledProgram = newProgram;
}

//Sets a new PersonalTrainer to Client
void Client::setPT(PersonalTrainer *PT)
{
	this->responsiblePT = PT;
}


//Sets a new name to Client
void Client::setName(string newName)
{
	name = newName;
}

#pragma endregion

//Changes the current location of Client.
void Client::changeLocation()
{
	if(insideGym)  insideGym = !insideGym; //Can always get out of the gym

	else{//But can only enter under some conditions
		if (!paymentsUpToDate) throw EntranceError("Payments not up to date");
		else if (numDaysRemaining == 0 && !insideGym) throw EntranceError("Maximum number of entries exceeded, see our other program offers!");
		else insideGym = !insideGym;
	}
}


//Returns in the argument vector problems the reasons for not being able to edit the Client
void Client::problems(vector<string> &problems) const
{
	if (problems.size() != 0) problems.clear();
	if (insideGym) problems.push_back("Client is still inside gym");
	if (!paymentsUpToDate) problems.push_back("Payments not up to date");
}

//Edits a Client
void Client::editClient(Gym &gym)
{
	bool continueInMenu = true;
	string newName;
	vector<string> clientProblems;
	int newProgramCode;
	do
	{
		int option = editClientMenu();
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			cout << "What's the Client's new name? " << endl;
			cout << "Previously: " << name << endl;
			cout << "->";
			cin >> newName;
			setName(newName);
			break;
		case 2:
			//Error checking
			problems(clientProblems);
			if (clientProblems.size() != 0) throw EditingError(clientProblems);

			cout << "What's the subscription you want to enroll?\n" << endl;
			gym.displayProgramOptions();

			//Selection of the new program
			newProgramCode = filterInput(1,gym.getNumberPrograms(),"Select a new program: ");

			//Checks if the program is the current one
			if (newProgramCode == enrolledProgram->getCode())  throw EditingError(vector<string>{"Trying to change program to the current one"});

			//Gets the respective program of the code
			setProgram(gym.codeToProgram(newProgramCode));

			//Updates days, as there were changes to the program
			updateNumDaysRemaining();

			cout << "Program successfully changed to program number " << enrolledProgram->getCode() << endl << endl;
			break;
			
		case 3:
			cout << *this;
			break;
		default:
			cout << "Algum erro";
			break;
		}
	} while (continueInMenu);
	//setProgram(int newProgram);
	//setPT(PersonalTrainer *PT);
}

//Menu for editing client
int Client::editClientMenu() const
{
	cout << "\nSelect what you want to edit" << endl<< endl;

	vector<string> options = { "1 - Change name", "2 - Set a new program subscription", "3 - Show information", "0 - Sair\n" };

	for (unsigned int i = 0; i < options.size(); i++)
		cout << options.at(i) << endl;

	int option = filterInput(0, options.size() - 1);

	return option;
}

//Updates the number of days remaining after setting a new program
void Client::updateNumDaysRemaining()
{
	if (numDaysRemaining > enrolledProgram->getDays()) numDaysRemaining = enrolledProgram->getDays();
}


std::ostream & operator<<(std::ostream & out, const Client &client)
{
	out << "\n---------- Client Information ----------" << endl << endl;
	out << "Client " << client.id << " information\n";
	out << "Name: " << client.name<< "\n";
	out << "Age: " << client.age << "\n";
	out << "Location: ";
	if (client.insideGym) out << "inside gym\n";
	else out << "outside gym\n";
	out << "Payment Status: ";
	if (client.paymentsUpToDate) out << "Up-to-date\n";
	else out << client.numDaysRemaining << " late payments\n";
	out << "Responsible professor: " << "\tName: " << client.responsiblePT->getName() << "\tID: "<<client.responsiblePT->getId() << endl << endl;
	out << *(client.getProgram())<<endl;
	return out;
}

void Client::informationClient()
{
	//Pode-se adicionar mais op��es como mostrar plano de treino
	cout << *this;
}

vector<Material*> generateMaterial()
{
	vector <Material *> m1;
	Material *m= new Material(true, "colchao", 2);
	m1.push_back(m);

	cout << "vetor de material com tamanho: "<< m1.size() <<endl;
	return m1;
}

void Client::setPlans()
{
	plans= generateStandardPlans();
}

vector<Exercise *> generateFiveExercises()
{
	int s=5;
	vector<Exercise *> v;
	while(s!=0)
	{
		//Exercise * e(vb.at(0),vb.at(1),vb.at(2),vb.at(3),vb.at(4),vb.at(5),vb.at(6),vb.at(7),vb.at(8),vb.at(9));
		string s1 = "random";
		string s2 = "flex";
		Exercise * e = new Exercise(true,false,false,false,false,false,false,false,false,true, s1,s2, generateMaterial(), 9);
		v.push_back(e);
		s--;
	}

	cout << "vetor de exercisios com tamanho: "<< v.size() <<endl;
	return v;
}

vector<Plan*> Client::generateStandardPlans(){

	int numPlans= enrolledProgram->getDays()/4; //Dividir os dias por 4 semanas

	cout << enrolledProgram->getDays()<< " "<< numPlans << endl;
	vector<Plan*> v;



	while(numPlans!=0)
	{
		string s= "random";
		Plan *p = new Plan(generateFiveExercises(),s);
		v.push_back(p);
		numPlans--;
	}
	cout << "vetor de planos com tamanho: "<< v.size() <<endl;
	return v;

}

std::vector<Plan *> Client::getPlans(){return plans;}

bool findInVector(vector<Exercise *> exercisios, Exercise e)
{
	for(auto &exercisio:exercisios) if(exercisio->getName() == e.getName()) return true;
	return false;
}

void eliminatePotentialEqualExercises(vector <Exercise *> &exercisios)
{
	vector <Exercise *> nR;
	for(uint i = 0; i < exercisios.size(); i++)
	{
		if (!findInVector(nR,*exercisios.at(i))) nR.push_back(exercisios.at(i));
	}
}

void Client::generateFunctionalPlan(Gym &gym)
{
	vector<Exercise *> exercisios;
	for(auto &exercise: gym.getExercises())
	{
		if (exercise->isFunctional()) exercisios.push_back(exercise);
	}
	eliminatePotentialEqualExercises(exercisios);
	sort(exercisios.begin(),exercisios.end(), [&](Exercise *e1, Exercise *e2){
			if (e1->trainedMuscles() > e2->trainedMuscles() ) return true;
			else if (e1->trainedMuscles() < e2->trainedMuscles())return false;
			else{
				if(e1->getIntensity() > e2->getIntensity()) return true;
				else if (e1->getIntensity() > e2->getIntensity()) return false;
				else
				{
					if(e1->getName() < e2->getName()) return true;
					else return false;
				}
			}
	});

	for(uint i = 10; i <exercisios.size() ;i++) exercisios.erase(exercisios.begin() + i);

	cout << "The generated plan looks like this:" << endl;
	for(auto &ex:exercisios) cout << *ex<< endl;

}

void Client::generateHyperPlan(Gym &gym)
{
	vector<Exercise *> exercisios;
	for(auto &exercise: gym.getExercises())
	{
		if (exercise->isHyper()) exercisios.push_back(exercise);
	}
	eliminatePotentialEqualExercises(exercisios);
	sort(exercisios.begin(),exercisios.end(), [&](Exercise *e1, Exercise *e2){
			if (e1->trainedMuscles() < e2->trainedMuscles() ) return true;
			else if (e1->trainedMuscles() > e2->trainedMuscles())return false;
			else{
				if(e1->getIntensity() > e2->getIntensity()) return true;
				else if (e1->getIntensity() > e2->getIntensity()) return false;
				else
				{
					if (e1->trainedMuscles() > e2->trainedMuscles() ) return true;
					else if (e1->trainedMuscles() < e2->trainedMuscles())return false;
					else
					{
						if(e1->getName() < e2->getName()) return true;
						else return false;
					}
				}
			}
	});

	for(uint i = 10; i <exercisios.size() ;i++) exercisios.erase(exercisios.begin() + i);

	cout << "The generated plan looks like this:" << endl;
	for(auto &ex:exercisios) cout << *ex<< endl;

}

void Client::generateCardioPlan(Gym &gym)
{
	vector<Exercise *> exercisios;
	for(auto &exercise: gym.getExercises())
	{
		if (exercise->isCardio()) exercisios.push_back(exercise);
	}
	eliminatePotentialEqualExercises(exercisios);
	sort(exercisios.begin(),exercisios.end(), [&](Exercise *e1, Exercise *e2){
			if (e1->isCardio() && !e2->isCardio() ) return true;
			else if (!e1->isCardio() && e2->isCardio() )return false;
			else{
				if(e1->getIntensity() > e2->getIntensity()) return true;
				else if (e1->getIntensity() > e2->getIntensity()) return false;
				else
				{
					if(e1->getName() < e2->getName()) return true;
					else return false;
				}
			}
	});

	for(uint i = 10; i <exercisios.size() ;i++) exercisios.erase(exercisios.begin() + i);

	cout << "The generated plan looks like this:" << endl;
	for(auto &ex:exercisios) cout << *ex<< endl;

}

bool Exercise::includeMuscles(vector<string> muscles)
{
	for(auto &muscle:muscles)
	{
		if (muscle == "legs" && legExercise()) return true;
		if (muscle == "calves" && calvesExercise()) return true;
		if (muscle == "chest" && chestExercise()) return true;
		if (muscle == "shoulders" && shouldersExercise()) return true;
		if (muscle == "biceps" && bicepsExercise()) return true;
		if (muscle == "triceps" && tricepsExercise()) return true;
		if (muscle == "abdominals" && abdominalsExercise()) return true;
		if (muscle == "gluteus" && gluteusExercise()) return true;
		if (muscle == "back" && backExercise()) return true;

	}
	return false;

}

bool Exercise::includeMuscle(string muscle)
{

	if (muscle == "legs" && legExercise()) return true;
	if (muscle == "calves" && calvesExercise()) return true;
	if (muscle == "chest" && chestExercise()) return true;
	if (muscle == "shoulders" && shouldersExercise()) return true;
	if (muscle == "biceps" && bicepsExercise()) return true;
	if (muscle == "triceps" && tricepsExercise()) return true;
	if (muscle == "abdominals" && abdominalsExercise()) return true;
	if (muscle == "gluteus" && gluteusExercise()) return true;
	if (muscle == "back" && backExercise()) return true;
	if (muscle == "cardio" && isCardio()) return true;

	return false;

}

void Client::generateMusclesPlan(Gym &gym, vector<string> muscles)
{
	vector<Exercise *> exercisios;
	for(auto &exercise: gym.getExercises())
	{
		if(exercise->includeMuscles(muscles)) exercisios.push_back(exercise);
	}
	eliminatePotentialEqualExercises(exercisios);

	sort(exercisios.begin(),exercisios.end(), [&](Exercise *e1, Exercise *e2){
			for(auto &muscle:muscles)
			{
				if (e1->includeMuscle(muscle) && !e2->includeMuscle(muscle)) return true;
				else if(!e1->includeMuscle(muscle) && e2->includeMuscle(muscle)) return false;
			}
			if(e1->getName() <e2->getName()) return true;
			else return false;
	});

	for(uint i = 10; i <exercisios.size() ;i++) exercisios.erase(exercisios.begin() + i);

	cout << "The generated plan looks like this:" << endl;
	for(auto &ex:exercisios) cout << *ex<< endl;

}

vector<string> selectMuscles()
{
	vector<string> muscles= {"legs", "calves", "chest", "shoulders", "biceps", "triceps", "abdominals", "gluteus", "back"};
	vector<bool> musclesToUse(9,false);
	cout << endl<<"Select the muscles" << endl << endl;
	vector<string> sections = { "\t1.	Legs" ,"\t2.	Calves" ,"\t3.	Chest" ,"\t4. Shoulders","\t5. Biceps" ,"\t6. Triceps","\t7. Abdominals","\t8. Gluteus","\t9. Back",  "\n\t0.	Leave\n" };
	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	Available Muscles	" << endl;
		cout << "\t--------------------------" << endl << endl;

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:
			musclesToUse.at(0) = true;
			break;
		case 2:
			musclesToUse.at(1) = true;
			break;
		case 3:
			musclesToUse.at(2) = true;
			break;
		case 4:
			musclesToUse.at(3) = true;
			break;
		case 5:
			musclesToUse.at(4) = true;
			break;
		case 6:
			musclesToUse.at(5) = true;
			break;
		case 7:
			musclesToUse.at(6) = true;
			break;
		case 8:
			musclesToUse.at(7) = true;
			break;
		case 9:
			musclesToUse.at(8) = true;
			break;
		default:
			break;
		}
	} while (continueInMenu);

	vector<string> finalMuscles;

	for(uint i = 0; i < musclesToUse.size();i++)
	{
		if(musclesToUse.at(i) == false) finalMuscles.push_back(muscles.at(i));
	}

	return finalMuscles;
}

void displayTypePlanExplanation()
{
	cout << "\n 	---Different Plan Types---" << endl<< endl;
	cout <<"\t		Functional" << endl;
	cout << "Training that involves a wide range of muscles, with movements similar to daily activities" << endl;
	cout << "Objective: Healthy lifestyle"<< endl << endl;

	cout << "\t		Hypertrophism "<<endl;
	cout << "Single muscle exercises, designed to maximaze muscle growth" << endl;
	cout << "Objective: Gain muscle" << endl << endl;

	cout << "\t		Cardio "<<endl;
	cout << "Exercise that accelarates heart beating" << endl;
	cout << "Objective: Lose weigth" << endl << endl;
	cout << "\t 	--------------------------" << endl;

}

void Client::generateNewPlans(Gym &gym)
{
	cout << endl<<"Qual é o teu objetivo?" << endl << endl;
	vector<string> sections = { "\t1.	Forma física (Funcional)" ,"\t2.	Ganhar musculo (Hipertrofismo)" ,"\t3.	Perder peso(cardio)" ,"\t4. Quais são as diferenças?" , "\n\t0.	Leave\n" };
	bool continueInMenu = true;
	do
	{
		cout << endl << "\t 	Training Plan Generator	" << endl;
		cout << "\t--------------------------" << endl << endl;

		for (unsigned int i = 0; i < sections.size(); i++)
			cout << sections.at(i) << endl;

		int option = filterInput(0, sections.size());
		switch (option)
		{
		case 0:
			continueInMenu = false;
			break;
		case 1:

			this->generateFunctionalPlan(gym);
			break;
		case 2:
			this->generateHyperPlan(gym);
			break;
		case 3:
			this->generateCardioPlan(gym);
			break;
		case 4:
			displayTypePlanExplanation();
			break;
		default:
			break;
		}
	} while (continueInMenu);

}

