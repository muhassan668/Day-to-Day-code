#include<iostream>
using namespace std;

class PaymentMethod{
	public:
		virtual float processPayment( float amount){
		}
};
class CreditCard: public PaymentMethod{
	public:
		float processPayment(float amount){
			cout<<"credit card"<<endl;
		}
};
class CryptoWallet: public PaymentMethod{
	public:
		float processPayment(float amount){
			cout<<"crypto wallet"<<endl;
		}
};
int main(){
	PaymentMethod* p;
	CreditCard c;
	p = &c;
	p->processPayment(7.0);
	CryptoWallet w;
	p = &w;
	p->processPayment(7.0);
	
	
	return 0;
}
