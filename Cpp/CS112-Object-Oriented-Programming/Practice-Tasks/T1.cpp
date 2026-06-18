#include <iostream>
using namespace std;

class SmartDevice{
	private:
		string deviceName;
		int batteryLevel;
	public:
		SmartDevice(){
			deviceName = "";
			batteryLevel = 40;
			
			cout<<"Current Battery: "<<batteryLevel<<endl;
		}
		void chargeDevice(int amount){
			cout<<"Charging...";
			if(batteryLevel >= amount) cout<<"Remaining charge: "<<100 - (batteryLevel + amount)<<endl;
			else if (batteryLevel < amount)	cout<<"Battery is now full at 100%"<<endl;
		}
	
};
int main(){
	SmartDevice s;
	int amount;
	do{
		cout<<"Enter charge amount: ";
		cin>> amount;
	}while(amount < 0 || amount > 100 );
	s.chargeDevice(amount);
	
	
	
	return 0;
}
