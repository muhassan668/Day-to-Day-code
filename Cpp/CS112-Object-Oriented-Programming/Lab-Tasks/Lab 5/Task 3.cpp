#include <iostream>
using namespace std;
 
class Bank{                                         // making the required class
    private :                                       // making private attribute
        double balance = 0;
    public :                                        // making public attributes
        void deposit(double);
        void withdraw(double);
};
void Bank::deposit(double d){                       // defining the functions and doing the required operations
    balance = balance + d;
    cout<<"Balance: "<<balance<<endl;
}
void Bank::withdraw(double w){                      // defining the functions and doing the required operations
    if(w>balance){
        cout<<"Insufficient balance."<<endl;
    }else if(w<0){
        cout<<"Cannot withdraw negative balance."<<endl;
    }else{
        balance = balance - w;
    }
    cout<<"Balance: "<<balance<<endl;
}
 
int main(){
 
    int choice;
    double d,w;
    Bank b;
    do{
    do{
    cout<<"Menu:"<<endl;                    // making the menu of better clarity
    cout<<"1. Deposit."<<endl;
    cout<<"2. Withdraw."<<endl;
    cout<<"3. Quit."<<endl;
    cin>>choice;
    }while(choice<0||choice>3);             // error handling
    if(choice == 1){
        cout<<"Enter Amount: ";
        cin>>d;
        do{
            if(d<=0){                      // number cannot be negative
                cout<<"Please enter a non-negative number to Deposit:";
                cin>>d;
            }
        }while(d<=0);
        b.deposit(d);                       // calling the function for deposit
    }else if(choice == 2){
        cout<<"Enter Amount: ";
        cin>>w;
        do{
            if(w<=0){
                cout<<"Please enter a non-negative number to Withdraw:";
                cin>>w;
            }
        }while(w<=0);
        b.withdraw(w);                      // calling the function for withdraw
    }else{
        cout<<"Successfully Exitted"<<endl;
        return 0;
    }
    } while (choice > 0 || choice < 3);
 
    return 0;
 
}
