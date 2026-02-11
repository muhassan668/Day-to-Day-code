#include<iostream>
using namespace std;

int Addition( int a, int b){        // making function for addition 
    int c= a+b;
    return c;
}
int Subtract(int a, int b){         // making function for subtraction
    int c= a-b;
    return c;
}
int Multiply(int a, int b){         // making function for multipication 
    int c = a*b;
    return c;
}

int main(){

    int x,y, choice;                // taking choice from user
    cout<<"Enter Two Numbers: "; 
    cin>> x >>y;
    cout<<"Menu: "<<endl;           // showing munu option 
    cout<<"1. Addition."<<endl;
    cout<<"2. Subtraction."<<endl;
    cout<<"3. Multiplication."<<endl;
    do{
    cin>>choice;
    if ( choice <1||choice >3){
        cout<<"Invalid! Enter Again. : ";
    }
    }while(choice<1||choice>3);
    int (*fun_ptr)(int,int);
    if(choice==1){
        fun_ptr = &Addition;                // saving the address of the addition function in the function pointer
        cout<<"Addition of Two numbers = ";
    }else if(choice == 2){
        fun_ptr=&Subtract;                  // saving the address of the subtraction function in the function pointer
        cout<<"Subtraction of Two numbers = ";
    }else{
        fun_ptr=&Multiply;                  // saving the address of the multiplication function in the function pointer
        cout<<"Multiplication of Two numbers = ";
    }
    cout<<fun_ptr(x,y)<<endl;               // printing the function using the function pointer


    return 0;
}