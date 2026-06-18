#ifndef LIBRARYCARD_H
#define LIBRARYCARD_H
#include "LibraryItem.h"

class LibraryCard {
	private:
    	int issueLimit;
    	int currentIssued;
    	LibraryItem** borrowedItems;

	public:
    	LibraryCard(int limit) {
        	issueLimit = limit;
        	currentIssued = 0;
        	borrowedItems = new LibraryItem*[issueLimit];
        	for(int i = 0; i < issueLimit; i++) {
            	borrowedItems[i] = NULL;
        	}
    	}

    	~LibraryCard() {
        	delete[] borrowedItems; 
    	}
		int getCardLimit() const{ return issueLimit; }
    	bool issueItem(LibraryItem* item) {
        	if (currentIssued < issueLimit && item->getStatus() == true) {
            	borrowedItems[currentIssued] = item;
            	currentIssued++;
            	item->setStatus(false);
            	return true;
        	}
        	return false;
    	}
    	bool returnItem(LibraryItem* item) {
        for (int i = 0; i < currentIssued; i++) {
            if (borrowedItems[i] == item) {
                item->setStatus(true);
                for (int j = i; j < currentIssued - 1; j++) {
                    borrowedItems[j] = borrowedItems[j + 1];
                }
                borrowedItems[currentIssued - 1] = NULL;
                currentIssued--; 
                return true;
            }
        }
        return false;
    }
};

#endif
