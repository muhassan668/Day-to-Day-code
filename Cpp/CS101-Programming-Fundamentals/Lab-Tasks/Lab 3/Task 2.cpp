#include<iostream>
using namespace std;
int main(){
	string name, meterID;
	int units,rateperunit,tb;
	
	cout<<"Enter Customer Name : \n"<<"Enter Meter ID : \n"<<"Enter Consumed Units : \n";
	cin>>name>>meterID>>units;
	
	if(0<units<=100){                 // different rate per units for different ranges of units consumed 
		rateperunit = 5;
	}else if(101<units<=200){
		rateperunit = 7;
	}else if(201<units<300){
		rateperunit = 10;
	}else{
		rateperunit = 15;
	}
	tb=rateperunit*units;
	// tb is the total bill.

	cout<<"====================================="<<endl;  // Body of the Main Bill
	cout<<"     ELECTRICITY BILL RECEIPT"<<endl;
	cout<<"====================================="<<endl;
	cout<<"Customer Name: "<<name<<endl<<endl;
	cout<<"Meter ID:      "<<meterID<<endl<<endl;
	cout<<"Units Consumed:"<<units<<endl<<endl;
	cout<<"Rate Per Unit: "<<rateperunit<<endl<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"Total Bill:    "<<tb<<endl;
	cout<<"====================================="<<endl;
	
	
	return 0;
}
