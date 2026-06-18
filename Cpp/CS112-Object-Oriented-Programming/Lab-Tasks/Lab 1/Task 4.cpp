#include<iostream>
using namespace std;

enum  FanSpeed{OFF = 1 , LOW = 2 , MEDIUM = 3 , HIGH = 4};

int main(){
	
	int choice;
	cout<<"Enter the Fan Speed(1-4): ";
	do{
	cin>>choice;
	if(choice<1||choice>4){
		cout<<"Invalid Choice!!!"<<endl;
	}}while(choice<1||choice>4);
	
	switch(choice){
	case OFF:
		cout<<"Fan is Off."<<endl;
		break;
	case LOW:
		cout<<"Fan Speed is Low."<<endl;
		break;
	case MEDIUM:
		cout<<"Fan Speed is Medium."<<endl;
		break;
	case HIGH:
		cout<<"Fan Speed is High."<<endl;
		break;
}
	return 0;
}
