# include <iostream>		//Header file
using namespace std;

int delivered =0;			//Global variable initialized to 0

void packdeliver(int n){
	if (n<=0){				//'n' cannot be negative
		cout<<"All Packages delivered!"<<endl;//when n=0 then all packages are delivered 
		return;
	}
	cout<<"Delivering package number "<<n<<endl;
	delivered++;
	
	packdeliver(n-1);		//recursive step
}
int main(){
	int totalPackages;
	do{
		cout<<"Enter number of packages: ";//Taking total number of packages 
		cin>>totalPackages;
		if(totalPackages<0){
			cout<<"Invalid input! please input again";
		}
		}while(totalPackages<0);			//Asking till input is non negative 

	packdeliver(totalPackages);				//Calling function 
	cout<<"Total deliveries made: "<<delivered<<endl;//Desplaing total deliveries
	
	return 0;
	
}


