  #include <iostream>
  using namespace std;
  int main(){
	int time;
	cout<<"What is the current time : \n";
	cin>>time;
	
	if(time==530){
		cout<<"It's Fajz Time\n";
	}else if(time==1230){
		cout<<"It's Duhur Time\n";
	}else if(time==1530){
		cout<<"It's Asar Time\n";
	}else if(time==1720){
		cout<<"It's Maghrib Time\n";
	}else if(time==1900){
		cout<<"It's Isha Time\n";
	}else
	cout<<"Enter a valid Salah Time (530, 1230, 1530, 1720, 1900)\n";
  	
  	
  	return 0;
  }
