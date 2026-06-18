#include <iostream>
using namespace std;
 
class Polynomial{
    private:
        int a, b, c;
    public:
        Polynomial(){       // default constructor
            a = 0;
            b = 0;
            c = 0;
        }
        Polynomial(int x, int y, int z){        // perimeterized constructor
            a = x;
            b = y;
            c = z;
        }
        Polynomial operator+(Polynomial &other){    // overloading the operator +
            Polynomial p1;
            p1.a = a+other.a;
            p1.b = b+other.b;
            p1.c = c+other.c;
            return p1;
        }
        int operator()(int x){                      // overloading the () operator
            return a*x*x + b*x + c;
        }
        void display(){
            cout<<a<<"x^2 + "<<b<<"x + "<<c<<endl;
        }
};
int main(){
 
    Polynomial P1(2,4,1);
    cout<<"First Polynomial: ";         // making objects
    P1.display();
    Polynomial P2(3,1,5);
    cout<<"Second Polynomial: ";
    P2.display();
    cout<<endl;
 
    Polynomial result = P1 + P2;        // adding objects
    cout<<"Result: ";
    result.display();
    cout<<endl;
   
    cout<<"At x=2: "<<result(2)<<endl;  
 
    return 0;
 
}
