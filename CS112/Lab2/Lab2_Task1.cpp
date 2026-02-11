#include<iostream>
using namespace std;

#define SQUARE(x)((x)*(x))          // defining the function for squaring
#define MAX(a,b)((a)>(b) ? (a):(b)) // defining the function for finding max

int main(){

    int num1, num2;
    cout<<"Enter Two Numbers: ";    // taking input
    cin>>num1;
    cin>>num2;
    cout<<"Square of "<<num1<<" = "<<SQUARE(num1)<<endl;  
    cout<<"Square of "<<num2<<" = "<<SQUARE(num2)<<endl;
    cout<<endl;
    cout<<"Maximum of Two is : "<<MAX(num1,num2)<<endl;

    return 0;
}