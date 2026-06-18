#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H
#include <string>
#include <iostream>

using namespace std;

class LibraryItem {
	protected:
    	string id;
    	string name;
    	string author;
    	int edition;
    	string purchaseDate;
    	bool isAvailable;

	public:
    	// Constructor
    	LibraryItem(string id, string name, string author, int edition, string purchaseDate) {
    	    this->id = id;
    	    this->name = name;
    	    this->author = author;
    	    this->edition = edition;
    	    this->purchaseDate = purchaseDate;
    	    this->isAvailable = true;
    	}
	
	    virtual ~LibraryItem() {}
	
	    string getId() const { return id; }
	    string getName() const { return name; }
	    bool getStatus() const { return isAvailable; }
	    
	    void setStatus(bool status) { isAvailable = status; }
	
	    virtual int getMaxDaysAllowed() const = 0; 
};

#endif
