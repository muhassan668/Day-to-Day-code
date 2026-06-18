#include <iostream>
using namespace std;
 
class BankAccount{                  // making class
    public:
        static int totalAccounts;   // declaring static variable
        BankAccount(){
            totalAccounts ++;
        }
        static int getTotalAccounts(){      // defining static function
            return totalAccounts;
        }
};
 
int BankAccount::totalAccounts = 0;     // initializing static variable
 
int main(){
 
    cout<<"Before Object Creation:"<<endl;
    cout<<"Total Accounts: "<<BankAccount::getTotalAccounts()<<endl;
 
    cout<<"Making One Object:"<<endl;
    BankAccount acc1;
    cout<<"After Making One Object Total Accounts are : " <<BankAccount::getTotalAccounts()<<endl;
 
    cout<<"Making Second Object:"<<endl;
    BankAccount acc2;
    cout<<"After Making Second Object Total Accounts are : "<<BankAccount::getTotalAccounts();
 
    return 0;
}
