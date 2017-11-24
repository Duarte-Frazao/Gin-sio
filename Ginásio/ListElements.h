#include "Finance.h"
#include "Gym.h"
#include "Client.h"
#include "Program.h"
#include "PersonalTrainer.h"
#include "Staff.h"
#include "algorithm"
#include <string>

template <class T>
bool comparePtrByID(T* a, T* b) {
	return (a->getId() < b->getId());
}

template <class T>
bool comparePtrByName(T* a, T* b) {
	if(a->getName() == b->getName())
		return comparePtrByID(a,b);

	return (a->getName() < b->getName());
}

template <class T>
bool comparePtrByAge(T* a, T* b) {
	if(a->getAge() == b->getAge())
			return comparePtrByID(a,b);
	return (a->getAge() < b->getAge());
}

template <class T>
bool comparePtrByWage(T* a, T* b) {
	if(a->getWage() == b->getWage())
			return comparePtrByID(a,b);
	return (a->getWage() < b->getWage());
}



template<class T>
bool listingByID(std::vector<T *> vec) {
	int init, final;

	if (vec.size() == 0)
		return false;

	sort(vec.begin(), vec.end(), comparePtrByID<T>);

	std::cout <<"Minimum value available: " << vec.at(0)->getId() << std::endl;
	std::cout << "Maximum value available: " << vec.at(vec.size()-1)->getId() << std::endl<<std::endl;
	std::cout << "Between which values: " << std::endl;
	std::cout << "Minimum: "; std::cin >> init;
	std::cout << "Maximum: "; std::cin >>final;

	if (!(init >= vec.at(0)->getId() &&  final <= vec.at(vec.size() - 1)->getId())){
		std::cout << std::endl << sign::error << "Invalid ID's" << std::endl;
		return false;
	}

	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getId() >= init && vec.at(i)->getId() <= final)
			std::cout << *(vec.at(i));
	}

	return true;
}

template<class T>
bool listingByName(std::vector<T *> vec) {
	std::string init, final;

	if (vec.size() == 0)
		return false;

	bool all = false;

	sort(vec.begin(), vec.end(),comparePtrByName<T>);

	std::cout << "First name: " << vec.at(0)->getName() << std::endl;
	std::cout << "Last name: " << vec.at(vec.size()-1)->getName() << std::endl<<std::endl;
	std::cout << "Between which values (-1 for all): " << std::endl;
	std::cout << "Minimum: "; std::cin >> init;

	try{
		if(std::stoi(init) == -1)
			all=true;
	}
	catch(...){
		all = false;
	}

	if(!all){
		std::cout << "Maximum: "; std::cin >>final;
	}
	else{
		init = vec.at(0)->getName();
		final = vec.at(vec.size()-1)->getName();
	}

	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getName() >= init && vec.at(i)->getName() <= final)
			std::cout << *(vec.at(i));
	}
	return true;

}


template<class T>
bool listingByAge( std::vector<T *> vec) {

	int init, final;
	if (vec.size() == 0)
		return false;

	sort(vec.begin(), vec.end(),comparePtrByAge<T>);


	std::cout << "Minimum age available: " << vec.at(0)->getAge() << std::endl;
	std::cout << "Maximum age available: " << vec.at(vec.size()-1)->getAge() << std::endl<<std::endl;
	std::cout << "Between which values: " << std::endl;
	std::cout << "Minimum: "; std::cin >> init;
	std::cout << "Maximum: "; std::cin >>final;


	if (!(init >= vec.at(0)->getAge() &&  final <= vec.at(vec.size() - 1)->getAge()))
		return false;

	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getAge() >= init && vec.at(i)->getAge() <= final)
			std::cout << *(vec.at(i));
	}
	return true;

}


template<class T>
bool listingByWage( std::vector<T *> vec) {

	int init, final;
	if (vec.size() == 0)
		return false;

	sort(vec.begin(), vec.end(),comparePtrByWage<T>);


	std::cout << "Minimum wage available: " << vec.at(0)->getWage() << std::endl;
	std::cout << "Maximum wage available: " << vec.at(vec.size()-1)->getWage() << std::endl<<std::endl;
	std::cout << "Between which values: " << std::endl;
	std::cout << "Minimum: "; std::cin >> init;
	std::cout << "Maximum: "; std::cin >>final;

	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getWage() >= init && vec.at(i)->getWage() <= final)
			std::cout << *(vec.at(i));
	}
	return true;

}
