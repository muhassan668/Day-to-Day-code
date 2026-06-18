#ifndef FACULTY_H
#define FACULTY_H
#include "Person.h"

class Faculty : public Person{
	public:
		Faculty(string id, string name, string address, string phone): Person(id, name, address, phone, 5){}
};

#endif
