#include <iostream>
using namespace std;
 
class Transactions;     // Prototype of class
 
class Account{          // making class
    private:
        int balance;
    public:
        int acc_no;
        Account(int acc, int bal):acc_no(acc),balance(bal) {}      // initializing acc no and balance using member initializer list
       
        friend void updateBalance(Account &a, Transactions &t);    // making friend function
        void display(){
            cout<<"Balance: "<<balance<<endl;
        }
};
class Transactions{     // making class        
    private:
        int ammount;
    public:
        Transactions(int amm):ammount(amm){}                        // initializing ammount
        friend void updateBalance(Account &a,Transactions &t);      // making friend function
};
void updateBalance(Account &a, Transactions &t){                    // defining function
    a.balance += t.ammount;
}
 
int main(){
 
    Account acc(123,10000);     // making object
    Transactions tran(500);     // making object
    cout<<"Account Balance Before Transaction: "<<endl;
    acc.display();
    updateBalance(acc,tran);    // calling update balance function
    cout<<"After Updating Balance: "<<endl;
    acc.display();
 
    return 0;
}
