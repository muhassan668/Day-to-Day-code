#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "LibraryItem.h"

class Magazine: public LibraryItem{
	public:
		Magazine(string id,string name,string author,int edition,string purchaseDate):LibraryItem(id,name,author,edition,purchaseDate){}
		int getMaxDaysAllowed() const{ return 0;}
};

#endif
