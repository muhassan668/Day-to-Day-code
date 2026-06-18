# include <iostream>		//Header file
using namespace std;
int count;
int fibonacci(int n){
	count++;				//Global variable
	int result;				//Local variable to store results
	if(n==0){				//Case for 0
		result=0;
	}else if(n==1){			//Case for 1
		result=1;
	}else{
		result = fibonacci(n-1)+fibonacci(n-2);//We are calling the function in itself
	}
	return result;			//Returning the result of Febonacci series
}
	int main(){
		int n;
		cout<<"Enter a number 'n' : ";//Asking for input
		cin>>n;
		if(n<0){			//Asking for a possitive value
			cout<<"Invalid! Please Try Again ";
			cout<<"Enter a number 'n' : ";
			cin>>n;
			}
		cout<<"Fibonacci Series : ";
		for(int i=0; i<n;i++){
			cout<<fibonacci(i)<<" ";	//Print fibonacci serie for n terms
		}
	cout<<endl;	
	cout<<"Function called "<<count<<" times"<<endl;	//Total number of recursive calls
		
	return 0;
}
