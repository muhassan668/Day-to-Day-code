#include <iostream>
using namespace std;
int main(){
	int month ;
	
	do{
		cout<<"enter month number";
		cin>>month;
		if (month>12 || month<1){
			cout<<"invalid please";
		}
	}while(month>12 || month<1);

	switch (month){
		case 12 :
			cout<<"December\n";
			break;
		case 11 :
			cout<<"November\n";
			break;
		case 10 :
			cout<<"October\n";
			break;
		case 9 :
			cout<<"September\n";
			break;
		case 8:
			cout<<"August\n";
			break;
		case 7 :
			cout<<"July\n";
			break;
		case 6 :
			cout<<"June\n";
			break;
		case 5 :
			cout<<"May\n";
			break;	
		case 4 :
			cout<<"April\n";
			break;
		case 3 :
			cout<<"March\n";
			break;
		case 2 :
			cout<<"February\n";
			break;
		case 1 :
			cout<<"January\n";
			break;
		case 0 :
			cout<<"'You Failed\n'";
			break;
	default:
		cout<<"The number entered is invalid\n";
	}
	
	
	return 0;
}
