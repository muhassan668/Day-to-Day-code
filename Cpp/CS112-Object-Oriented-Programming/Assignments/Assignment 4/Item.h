#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

using namespace std;

class Item{
	protected:
		string name;
		string itemType;
		float basicPrice;
	public:
		Item(){
			name = "";
			itemType = "";
			basicPrice = 0.0;
		}
		Item(string name, string itemType, float basicPrice){
			this->name = name;
			this->itemType = itemType;
			this->basicPrice = basicPrice;
		}
		string getName() const{ return name;}
		string getItemType() const{ return itemType;}
		float getBasicPrice() const{return basicPrice; }
		void setName(string n){name = n;}
		void setItemType(string t){itemType = t;}
		void setBasicPrice(float p){ basicPrice = p;}
		
		virtual ~Item(){}
		virtual float price() const = 0;
		virtual bool gift() const = 0;
		virtual int getUnits() const = 0;
		virtual bool isOnSale() const = 0;
		
		friend ostream& operator<<(ostream& out, const Item& item){
			out<< item.getName()<<" "
				<< item.getBasicPrice()<<" "
				<< item.getUnits()<< " "
				<<(item.isOnSale() ? "True" : "False")<<" "
				<<(item.gift() ? "True" : "False")<<" "
				<< item.price()<<" Rs.";
				return out;
		}
		friend bool operator==(const Item& left, const Item& right){
			if(left.getName() == right.getName() && left.getBasicPrice() == right.getBasicPrice() && left.getItemType() == right.getItemType()){
				return true;
			}
			return false;
		}
};

#endif
