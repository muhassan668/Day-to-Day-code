#include <iostream>
using namespace std;
 
class Temperature{
    private:
        double temp;
    public:
        Temperature(int t){     // constructor
            temp = t;
        }
        Temperature operator-() const {     // operator overloading of -
            return Temperature(-temp);
        }
        void display() const{
            cout<<temp<<" Degree Celcius"<<endl;
        }
};
int main(){
    Temperature original(25);
    Temperature modified = -original;       // object modified calls the operator -
 // it assigns the reversed value of original to modified
    cout<<"Original: ";
    original.display();
 
    cout<<"Modified: ";
    modified.display();
 
    return 0;
}
