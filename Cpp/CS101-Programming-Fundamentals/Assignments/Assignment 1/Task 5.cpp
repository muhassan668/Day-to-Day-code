#include <iostream>

using namespace std;

int main(){
	float x,y,z;
	cout<<"How many kilometers do you want to travel.\n";
	cin>>x;
	y= (1/50.2)*x;
	cout<<"For CD 70, liter/s required will be : " << y << endl;
	z= (1/40.5)*x;
	cout<<"For CG 125, liter/s required will be : "<< z << endl;
	
	return 0;
}


