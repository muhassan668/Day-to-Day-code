#include <iostream>
using namespace std;

float celTOfaren(float C){			// For converting Celcius to Farenheit
	float F;
	F=(C*9.0/5.0)+32.0;				// Using given formula
	return F;
	
}

float farenTOcel(float K){			// For converting Farenheit to Celcius
	float F;
	F=(K-273.15)*9.0/5.0 +32.0;		// Using given formula
	return F;
}
int main(){
	float temp;
	char scale;
	
	cout<<"Enter scale :"<<endl;
	cin>>scale;
	cout<<"Enter temperature value as per selected scale:"<<endl;
	cin>> temp;
	
	if (scale=='K'|| scale== 'k'){
		cout<<"Temperature in Farenheit is "<<farenTOcel(temp);
	}else if (scale == 'C'|| scale == 'c'){
		cout <<"Temperature in Celcius is "<<celTOfaren(temp);
		}
		else{
			cout<<"Invalid scale. Assuming Celcius"<<endl;
			cout<<"Temperature in Farenheit is "<<celTOfaren(temp);
		}
		return 0;
}










