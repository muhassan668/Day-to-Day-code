#ifndef JOURNAL_H
#define JOURNAL_H
#include "LibraryItem.h"

class Journal: public LibraryItem{
	public:
		Journal(string id,string name,string author,int edition,string purchaseDate):LibraryItem(id,name,author,edition,purchaseDate){}
		int getMaxDaysAllowed() const{ return 0;}
};

#endif
