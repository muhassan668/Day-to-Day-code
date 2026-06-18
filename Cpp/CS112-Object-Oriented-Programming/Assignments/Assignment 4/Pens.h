#ifndef PENS_H
#define PENS_H
#include<iostream>
#include <string>
#include "Item.h"

class Pens: public Item{
	protected:
		int units;
		bool onSale;
		bool giftCard;
	public:
		Pens(float price, int units = 1, bool onSale = false, bool giftCard = false): Item("Pens", "Supplies", price){
			this->units = units;
			this->onSale = onSale;
			this->giftCard = giftCard;
		}
		float price() const {
			if(onSale) return (basicPrice*0.75)*units;
			else return basicPrice*units;
		}
		bool gift() const { return giftCard; } 
		int getUnits() const{ return units;}
		bool isOnSale() const{ return onSale; }
		
};

#endif
