#include <iostream>
using namespace std;
 
class BankAccount{                          // making class
    private:
        int accountNumber;
        double balance;
        string ownerName;
    public:                             // constructor's member initializer list
  		BankAccount(int acc_num = 124 , double bal = 10000, string): accountNumber(acc_num), balance(bal), ownerName(name) {}
    void display_data(){
        cout<<"Account Number: "<<accountNumber<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<"Owner Name: "<<ownerName<<endl;
    }
};
int main(){
    int num;
    double bal;
    string naam;
 
    cout<<"Bank Account Details(default). "<<endl;
    BankAccount A;
    A.display_data();
    cout<<"Enter account number: ";
    cin>>num;
    cout<<"Enter balance: ";
    cin>>bal;
    cout<<"Enter owner name: ";
    cin>>naam;
    cout<<endl;
 
    cout<<"Bank Account Details(parameterized)"<<endl;
    BankAccount B(num , bal , naam);
    B.display_data();
 
    return 0;
}
