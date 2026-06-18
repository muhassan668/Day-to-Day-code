#include <iostream>

using namespace std;

int main(){
	float x;
	cout<<"Please enter the radius of the sphere\n";
	cin>>x;
	float y;
	y = 4*3.14*x*x;
	cout<< "The surface area of the sphere is : "<<y<<endl;
	float z;
	z = (1.33333)*3.14*x*x*x;
	cout<<"The volume of the sphere is : "<< z <<endl;
	
	
	return 0;
}
