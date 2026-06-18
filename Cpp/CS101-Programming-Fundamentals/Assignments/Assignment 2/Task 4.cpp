#include <iostream>
using namespace std;

float calculateBill(float gallons){
	float bill;
	
	if (gallons <= 100){
		bill = gallons * 50;
	}else if (gallons <= 250)
	{
		bill = (100*50)+((gallons - 100)*100);
	}else if (gallons <= 600)
	{
		bill = (100 *50 )+ (250*100)+((gallons-350)*150);
	}else {
		bill = (100 * 50)+(250 * 100)+(250*150)+((gallons - 600)*250);
	}	
		bill =bill +(bill *0.14);
		return bill;
}

int main(){
	float gallons;
	char choice;
	
	do{
	
	do {
		cout <<"How many gallons did you use : ";
		cin >> gallons;
		
		if (gallons <0){
			cout << "Please enter a possitive number, ";
		}
	}while ( gallons < 0 );
	
	float total = calculateBill(gallons);
	cout<<"Total bill including tax : Rs. "<<total<<endl;
	cout<<"Press 'c' to continue and 's' to stop : ";
	cin>>choice;
	} 
	
	while(choice == 'c' || choice == 'C');
	cout << "ThankYou!!";
	return 0;
}
