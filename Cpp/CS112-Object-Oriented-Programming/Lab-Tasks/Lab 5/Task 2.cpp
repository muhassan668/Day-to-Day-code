#include <iostream>
using namespace std;
 
class Calculator{                           // making the required class
    private :                               // making the private attributes
        double a;
        double b;
    public :                                // making function prototypes as public attributes
        void setValues(double x, double y);
        void add();
        void sub();
        void mul();
        void div();
 
};
void Calculator::setValues(double x, double y){     // defining functions
    a = x;
    b = y;
}
void Calculator::add(){
    cout<<"Addition: "<<a+b;
}
void Calculator::sub(){
    cout<<"Subtraction: "<<a-b;
}
void Calculator::mul(){
    cout<<"Multiplication: "<<a*b;
}
void Calculator::div(){
    if(b==0){
        cout<<"Invalid! Cannot divide by 0."<<endl;
    }else{
        cout<<"Division: "<<a/b;
    }
}
 
int main(){
 
    int x,y;
    cout<<"Enter the first number: ";
    cin>>x;
    cout<<"Enter the second number: ";
    cin>>y;
 
    Calculator calc;                // making the object of the function
 
    calc.setValues(x,y);            // calling function to set the values
 
    calc.add();                     // calling every function
    cout<<endl;
    calc.sub();
    cout<<endl;
    calc.mul();
    cout<<endl;
    calc.div();
    cout<<endl;
 
 
    return 0;
 
}
