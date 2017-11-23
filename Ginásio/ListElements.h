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



template<class T>
bool listingByID(std::vector<T *> vec) {
	int init, final;

	if (vec.size() == 0)
		return false;

	sort(vec.begin(), vec.end(), comparePtrByID<T>);

	std::cout<< "Between which values (" << vec.at(0)->getId() << " " << vec.at(vec.size()-1)->getId() << "): ";
	std::cin>> init >> final;

	if (!(init >= vec.at(0)->getId() &&  final <= vec.at(vec.size() - 1)->getId()))
		return false;

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

	sort(vec.begin(), vec.end(),comparePtrByName<T>);

	std::cout<< "Between which values (" << vec.at(0)->getName() << " " << vec.at(vec.size()-1)->getName() << "): ";
	std::cin>> init >> final;

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

	std::cout<< "Between which values (" << vec.at(0)->getAge() << " " << vec.at(vec.size()-1)->getAge() << "): ";
	std::cin>> init >> final;

	if (!(init >= vec.at(0)->getAge() &&  final <= vec.at(vec.size() - 1)->getAge()))
		return false;

	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec.at(i)->getAge() >= init && vec.at(i)->getAge() <= final)
			std::cout << *(vec.at(i));
	}
	return true;

}
