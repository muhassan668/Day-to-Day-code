#include <iostream>
using namespace std;

void sellItem (int &stock, int quantity){
	stock = stock-quantity;
// Sold items will be deducted from the total 
}

void restockItem (int &stock, int quantity){
	stock = stock + quantity;
// Restocked items will be added to the total

}


void showStock (int &stock){
	cout <<"Current stock : "<<stock;

}
int main(){

	int stock,restock,sold;
do {	
	cout<<"Initial stock : ";
	cin>>stock;
	if(stock<0)
	cout<<"Enter a possitive number "<<endl;
}while(stock<0);

do{

	cout<<"Sold : ";
	cin>>sold;
	if (sold<0)
	cout<<"Enter a possitive number"<<endl;
}while(sold<0);

do{

	cout<<"Restock Items : ";
	cin>>restock;
	if (restock<0)
	cout<<"Enter a possitive number"<<endl;
}while(restock<0);

	sellItem(stock,sold);
	restockItem(stock,restock);
	showStock(stock);
	return 0;
	
	
}









