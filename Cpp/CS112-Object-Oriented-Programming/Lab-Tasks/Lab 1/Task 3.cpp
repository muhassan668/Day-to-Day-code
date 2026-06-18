#include<iostream>
using namespace std;

union SensorData{
	float temp;
	float pressure;
}sd1;
int main(){
	
	cout<<"Enter the Temperature: ";
	cin>>sd1.temp;
	cout<<"Enter the Pressure: ";
	cin>>sd1.pressure;
	cout<<endl;
	cout<<"The Temperature is: "<<sd1.temp<<endl;
	cout<<"The Pressure is: "<<sd1.pressure<<endl;
	
	return 0;
}
