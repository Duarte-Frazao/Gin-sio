template <class T>
bool comparePtrByID(T* a, T* b) {
	return (a->getID() < b->getID());
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
