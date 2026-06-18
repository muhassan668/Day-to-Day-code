#ifndef CART_H
#define CART_H
#include <iostream>
#include "Item.h"

using namespace std;

class Cart {
	private:
    	Item** items;
    	int count;
    	int capacity;

	public:
    	Cart(int cap = 50) {
        	capacity = cap;
        	count = 0;
        	items = new Item*[capacity];
    	}
    	~Cart() {
	   	    delete[] items;
    	}
    	
    	Cart& operator+=(Item& item) {
        	if (count < capacity) {
            	items[count] = &item;
            	count++;
        	}
        	return *this;
    	}
    	bool Discount() const {
			int saleCount = 0;
        	for(int i=0; i<count; i++){
        		if(items[i]->isOnSale()){
        			saleCount++;
				}
			}
			return (saleCount >= 3);
    	}
    	float price() const {
        	float finalprice = 0.0;
        	for(int i=0; i<count; i++){
        		finalprice += items[i]->price();
			}
			if(Discount() == true){
				finalprice = finalprice* 0.875;
			}
			return finalprice;
    	}
    	friend ostream& operator<<(ostream& out, const Cart& cart) {
        if (cart.count == 0) {
            out << "Still no item in the cart\n";
        } else {
            out << "Cart Contains\n";
            for (int i = 0; i < cart.count; i++) {
                out << *(cart.items[i]) << "\n"; 
            }
            out << "Cart is Discounted: " << (cart.Discount() ? "Yes" : "No") << "\n";
            out << "Total Price: " << cart.price() << " Rs.\n";
        	}
        	return out;
    	}
    	Cart(const Cart& other) {
        	capacity = other.capacity;
        	count = other.count;
        	items = new Item*[capacity];
        	for (int i = 0; i < count; i++) {
        	    items[i] = other.items[i];
        	}
    	}
    	Cart& operator=(const Cart& rhs) {
        	if (this != &rhs) {
            	delete[] items; // Delete our old array
            	capacity = rhs.capacity;
            	count = rhs.count;
            	items = new Item*[capacity]; // Build a new one
            	for(int i = 0; i < count; i++) {
            	    items[i] = rhs.items[i];
            	}
        	}
        	return *this;
    	}
		Cart& operator-=(Item& item) {
        	string targetType = item.getItemType();
			for (int i = 0; i < count; ) {
            if (items[i]->getItemType() == targetType) {
                for (int j = i; j < count - 1; j++) {
                    items[j] = items[j + 1];
                	}
                items[count - 1] = NULL;
                count--;
            } else {
               	i++; 
           		}
       		}
        	return *this;
    	}
		Cart operator+(Item& item) {
        	Cart newCart(*this);
        	newCart += item;    
        	return newCart;
    	}
    	Cart operator-(Item& item) {
       		Cart newCart(capacity);
        	string targetName = item.getName(); 
        	for (int i = 0; i < count; i++) {
            	if (items[i]->getName() != targetName) {
                	newCart += *(items[i]);
            	}
        	}
        	return newCart;
    	}
    	
};

#endif
