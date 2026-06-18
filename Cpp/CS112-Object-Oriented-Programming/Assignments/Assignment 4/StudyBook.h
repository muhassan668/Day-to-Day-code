#ifndef STUDYBOOK_H
#define STUDYBOOK_H
#include "LibraryItem.h"

class StudyBook : public LibraryItem{
	public:
		StudyBook(string id,string name,string author,int edition,string purchaseDate):LibraryItem(id,name,author,edition,purchaseDate){}
		int getMaxDaysAllowed() const{ return 0; }
};

#endif
