#include<iostream>
using namespace std;

union Payment{
	
	int cash;
	long long int card_number;
	
}pay1;
int main(){
	
	int choice;
	cout<<"Please Select an Option: "<<endl;
	cout<<"1. Cash."<<endl;
	cout<<"2. Card."<<endl;
	do{
	cin>>choice;
	if(choice<1||choice>2){
		cout<<"Invalid Choice!!!"<<endl;
	}}while(choice<1||choice>2);
	if(choice==1){
		cout<<"Ener the Amount of Cash: ";
		cin>>pay1.cash;
		cout<<"The Entered Amount of Cash is: "<<pay1.cash<<endl;
	}else{
		cout<<"Enter Card Number: ";
		cin>>pay1.card_number;
		cout<<"The Entered Card Number is: "<<pay1.card_number<<endl;
	}
	
	return 0;
}
