#include<iostream>
using namespace std;
 
class Account{
    private:
        int acc_no;
        float balance;
    public:
        Account(int no, float bal){	
            this->acc_no = no;			// using this pointer to distinguish
            this->balance = bal;
        }
        void deposit(float bal){
            this->balance += bal;		// adding using this pointer
        }
        void compareBalance(Account obj){
            if(this->balance > obj.balance){	// compairing using this pointer
                cout<<"Object "<< this->acc_no <<" has higher balance"<<endl;
            }else{
                cout<<"Object "<< obj.acc_no <<" has higher balance"<<endl;
            }
        }
};
int main(){
 
 	cout<<"Making first account with account number '123' and balance '12000'"<<endl;
    Account acc1(123,12000);
    cout<<"Making second account with account number '000' and balance '10000'"<<endl;
    Account acc2(000,10000);
 	cout<<"Depositing account number '123' with 1000"<<endl;
    acc1.deposit(1000);
 
    cout<<"Comparing with respect to first object"<<endl;
    acc1.compareBalance(acc2);
 
    cout<<"Comparing with respect to second object"<<endl;
    acc2.compareBalance(acc1);
 
    return 0;
}
