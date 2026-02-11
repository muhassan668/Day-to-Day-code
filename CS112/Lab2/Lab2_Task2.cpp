#include <iostream>
using namespace std;

void printBinary(unsigned int n){           // making function with unsigned int as argiment 
    for(int i=7; i>=0; i--){                // making so that the bit is of 8 digits and not more 
        int bit = (n>>i)&1;
        cout<<bit;                          // showing bit in terminal 
    }
    cout<<endl;
}
int main(){

    unsigned int num;
    cout<<"Enter an unsigned int : ";       // taking input of unsigned variable from user 
    cin>>num;
    cout<<"Binary : ";
    printBinary(num);                       // showing the binary form of the variable taken from user
    num = num | (1<<2);                     // setting the third bit to one 
    num = num & ~(1<<4);              	    // setting the fifth bit to zero 
    cout<<"Updates Decimal = "<<num<<endl;  // showing updated num
    cout<<"Updated Binary = ";
    printBinary(num);                       // showing updated binary 

    if((num & 1)==1){                       // checking if the number is odd or even 
        cout<<"The Number is Odd"<<endl;
    }else{
        cout<<"The Number is even"<<endl;
    }

    return 0;
}
