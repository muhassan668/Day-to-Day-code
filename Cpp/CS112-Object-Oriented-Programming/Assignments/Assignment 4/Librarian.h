#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "Person.h"
#include <string>

class Librarian: public Person{
	private:
		string password;
	public:
		Librarian(string id,string name,string address,string phone,string password): Person(id,name,address,phone,0){
			this->password = password;
		}
		bool login(string enteredPassword){
			if(enteredPassword == this->password) {return true;}
			else{ return false;}
		}
};

#endif
