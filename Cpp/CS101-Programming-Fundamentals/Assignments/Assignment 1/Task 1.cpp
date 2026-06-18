#include <iostream>
#include <math.h>

using namespace std;

int main(){
	 int x;
	 cout<< "Please enter a number!\n";
	 cin>>x;
	 cout<< "Your entered number is : "<<x<<endl;
	int y;
	cout<< "What would you like its power to be!\n";
	cin>>y;
	cout << "Your entered power is : "<<y<<endl<<endl;
	cout<< x << " to the power of "<< y <<" is : "<<pow(x,y)<<endl;
	cout << "Thankyou!!";
	
	return 0;
}
