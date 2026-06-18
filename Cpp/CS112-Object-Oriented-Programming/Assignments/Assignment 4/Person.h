#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
#include "LibraryCard.h"

using namespace std;

class Person{
	protected:
		string id;
		string name;
		string address;
		string phone;
		LibraryCard* card;
	public:
		Person(string id, string name, string address, string phone, int cardLimit){
			this->id = id;
			this->name = name;
			this->address = address;
			this->phone = phone;
			this->card = new LibraryCard(cardLimit);
		}
		virtual ~Person(){
			delete card;
		}
		string getId() const{return id;}
		string getName() const{return name;}
		LibraryCard* getCard() const{return card;}
};

#endif
