#include <iostream>
using namespace std;

class Patient{
	int bill;
	public:
		Patient(){
			bill = 5000;
		}
		int getbill(){return bill;}
		friend discount(Patient &p, int amount);
};
Patient::discount(Patient &p, int amount){
	bill = p.bill - amount;
	return bill;
}
int main(){
	Patient p;
	cout<<"Original bill: "<<p.getbill()<<endl;
	cout<<"Applying discount..."<<endl;
	cout<<"Updated bill: "<<p.discount(&p,500);
	
	return 0;
}
