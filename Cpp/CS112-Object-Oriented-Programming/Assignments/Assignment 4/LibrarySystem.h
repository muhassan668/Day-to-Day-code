#ifndef LIBRARYSYSTEM_H
#define LIBRARYSYSTEM_H
#include <iostream>
#include "LibraryItem.h"
#include "Person.h"

using namespace std;

class LibrarySystem{
	private:
		LibraryItem** catalog;
		Person** members;
		int maxItems;
		int currentItemCount;
		int maxMembers;
		int currentMemberCount;
	public:
		LibrarySystem(int maxItems, int maxMembers){
			this->maxItems = maxItems;
			this->maxMembers = maxMembers;
			this->currentItemCount = 0;
			this->currentMemberCount = 0;
			
			catalog = new LibraryItem*[maxItems];
			members = new Person*[maxMembers];
			
			for(int i=0; i<maxItems; i++) catalog[i] = NULL;
			for(int i=0; i<maxMembers; i++) members[i] = NULL; 
			}
		~LibrarySystem(){
			delete[] catalog;
			delete[] members;
		}
		void addItem(LibraryItem* item){
			if(currentItemCount < maxItems){
				catalog[currentItemCount] = item;
				currentItemCount++;
			}else{
				cout<<"Catalog is full!"<<endl;
			}
		}
		void addPerson(Person* p){
			if(currentMemberCount < maxMembers){
				members[currentMemberCount] = p;
				currentMemberCount++;
			}else{
				cout<<"Member list is full!"<<endl;
			}
		}
		void issueItem(Person* p, LibraryItem* item){
			bool success = p->getCard()->issueItem(item);
			if(success){
				cout<<p->getName()<<" successfully checked out: "<<item->getName()<<endl;
			}else{
				cout<<"Checkout failed! Item unavailable or limit reached for "<<p->getName()<<endl;
			}
		}
		void returnItem(Person* p, LibraryItem* item, int daysKept) {
			
	    bool success = p->getCard()->returnItem(item);
        if (success) {
            cout << p->getName() << " returned " << item->getName() << "." << endl;
            int allowedDays = 0;
            if (p->getCard()->getCardLimit() == 3) {
                allowedDays = 14;
            } else if (p->getCard()->getCardLimit() == 5) {
                allowedDays = 60;
            }
            if (daysKept > allowedDays) {
                int daysLate = daysKept - allowedDays;
                int fine = daysLate * 50;
                cout << "LATE RETURN! " << daysLate << " days late. Fine generated: " << fine << endl;
            } else {
                cout << "Returned on time. No fine." << endl;
            }
            cout << "Status updated: " << item->getName() << " is now available." << endl;
        } else {
            cout << "Error: " << p->getName() << " does not have " << item->getName() << "!" << endl;
        }
    }
};

#endif
