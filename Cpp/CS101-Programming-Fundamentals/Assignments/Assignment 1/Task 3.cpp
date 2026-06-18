#include <iostream>
#include <math.h>

using namespace std;

int main(){
	float a,b,c,s,x;
	cout<<"Please input the 3 values of the sides of the triangle simultaneously!\n";
	cin>> a>>b>>c;
	
	s = (a+b+c)/2;
	x = sqrt(s*(s-a)*(s-b)*(s-c));
	cout<<"The Area of the triangle is : "<< x<<endl;
	
	
	return 0;
}

