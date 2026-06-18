#include <iostream>
using namespace std;
 
class Book{                 // creating class
    string title;
    double* price;          // making pointer
    public:
    Book(string titl,double pric){
        title = titl;
        price = new double; // making dynamic memory
        *price = pric;
    }
    void display(){
        cout<<"Title: "<<title<<endl;
        cout<<"Price: "<<*price<<endl;
    }
    ~Book(){                // deleting the dynamic memory
        delete price;
    }
};
int main(){
 
    string titl;
    double pric;
    cout<<"Enter title: ";
    getline(cin,titl);
    cout<<"Enter Price: ";
    cin>>pric;
    Book B{titl, pric};		// {} brackets in vscode and () brackets in dev c++
    B.display();
 
    return 0;
}
