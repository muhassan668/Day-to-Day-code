#include <iostream>
using namespace std;

class WebVisitor{
	static int totalVisitors;
	public:
		WebVisitor(){
			totalVisitors++;
		}
		static int getTraffic(){
			return totalVisitors;
		}
};
int WebVisitor::totalVisitors = 0;
int main(){
	cout<<"Before any visitors: Total Traffic = "<<WebVisitor::getTraffic()<<endl;
	WebVisitor q1,q2,q3;
	cout<<WebVisitor::getTraffic()<<endl;
	
	
	return 0;
}
