#include <iostream>
using namespace std;
 
class Book{                     // creating the required class
    private :                   // making private attributes
        string title;
        double price;
    public :                    // making public attributes
        void setData(string t, double p){   // making function for setting data
            title = t;
            price = p;
        }
        void display(){                     // making function for displaying data
            cout<<"Title: "<<title<<endl;
            cout<<"Price: "<<price<<endl;
        }
};
 
int main(){
 
    string title;
    double price;
    cout<<"Enter Title of Book: ";
    cin>>title;
    cout<<"Enter Price of Book: ";
    cin>>price;
    while(price<0){
        if (price < 0){                 // price cannot be negative
            cout<<"Invalid price. It cannot be negative."<<endl;    
            cout<<"Please enter the price again: ";
            cin>>price;
        }
    }
 
    Book b;                             // making object of the class
    b.setData(title, price);            // calling the functions
    b.display();
 
    return 0;
 
}
