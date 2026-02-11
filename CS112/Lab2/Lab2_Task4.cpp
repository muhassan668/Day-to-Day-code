#include <iostream>
#include "BASIC_OPS.h"                  // including the preprocessive directive that we created for basic operations
#include "SCIENTIFIC_OPS.h"             // including the perpeocessive directive that we created for scientific operations
using namespace std;

int main(){

    double a = 10.0, b=2.0;             // checking each operation by initializing two variables
    cout<<"Addition : "<< add(a,b)<<endl;
    cout<<"Subtract : "<< sub(a,b)<<endl;
    cout<<"Multiplication : "<<mul(a,b)<<endl;
    cout<<"Divide : "<<div(a,b)<<endl;
    cout<<"Power : "<<power(a,b)<<endl;
    cout<<"Square Root of "<<a<<" : "<<sqrt(a)<<endl;
    cout<<"Square Root of "<<b<<" : "<<sqrt(b)<<endl;
    cout<<"Log of "<<a<<" : "<<log(a)<<endl;
    cout<<"Log of "<<b<<" : "<<log(b)<<endl;

    return 0;

}
