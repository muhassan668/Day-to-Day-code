#include<iostream>
using namespace std;

struct Computer{
	
	char brand_name[25];
	int model_year;
	int Price;	
	
}c1,c2;
int main(){
	
	cout<<"Enter Details Of Computer 1: "<<endl;
	cout<<"Brand Name: ";
	cin>>c1.brand_name;
	cout<<"Model Year: ";
	cin>>c1.model_year;
	cout<<"Price: ";
	cin>>c1.Price;
	
	cout<<"Enter Details Of Computer 2: "<<endl;
	cout<<"Brand Name: ";
	cin>>c2.brand_name;
	cout<<"Model Year: ";
	cin>>c2.model_year;
	cout<<"Price: ";
	cin>>c2.Price;
	cout<<endl;
	
	cout<<"Computer 1: ";
	cout<<"Brand Name: "<<c1.brand_name<<endl;
	cout<<"Model Year: "<<c1.model_year<<endl;
	cout<<"Price     : "<<c1.Price<<endl;
	cout<<"Computer 2: ";
	cout<<"Brand Name: "<<c2.brand_name<<endl;
	cout<<"Model Year: "<<c2.model_year<<endl;
	cout<<"Price   : "<<c2.Price<<endl;
	
	return 0;
}
