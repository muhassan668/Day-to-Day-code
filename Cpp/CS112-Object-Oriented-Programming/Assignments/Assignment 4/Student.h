#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"

class Student : public Person {
	public:
    	Student(string id, string name, string address, string phone) : Person(id, name, address, phone, 3) {}
};

#endif
