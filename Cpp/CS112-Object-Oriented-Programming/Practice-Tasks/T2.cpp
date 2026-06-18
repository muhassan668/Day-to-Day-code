#include <iostream>
using namespace std;

class FlightTicket{
	private:
		string passengerName;
		string flightNumber;
		string seatClass;
	public:
		FlightTicket(){
			passengerName = "Default";
			flightNumber = "Flight 0";
			seatClass = "Economy";
		}
		FlightTicket(string pN, string fN, string sC): passengerName(pN), flightNumber(fN), seatClass(sC){}
};
int main(){
	FlightTicket f1;
	FlightTicket f2("Ali", "Flight 707", "Business");
	FlightTicket f3("Sara", "Flight 303", "First Class");
	
	cout<<f1;
	
	return 0;
}
