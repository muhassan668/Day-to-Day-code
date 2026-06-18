#include<iostream>
using namespace std;
int main(){
	int x,y,z;
	cout<<"Enter a possitive number to multiply: \n"; // taking number from user to multiply 
	cin>>x;
	if (x<0){
		cout<<"Error! Number cannot be negative.\n"; // number should be possitie otherwise error occurs
	}
	if(x>=0){
		cout<<"Enter the range upto witch you want the Table.\n"; 
		cin>>y;
	}
	if (y<0){
		cout<<"Error! Range cannot be negative.\n";  // range can also not be negative
	}
	z = 1;
	while (y>=z && x>0){
		cout<<x<<" x "<<z<<" = "<<x*z<<endl;    // using while loop to execute 
		z=z+1;
	}
	
	return 0;
}
