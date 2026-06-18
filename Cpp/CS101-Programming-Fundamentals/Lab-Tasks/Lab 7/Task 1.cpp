# include <iostream>		//Header file
using namespace std;
int main(){
	int size=8;				//Initializing array size to 8 as asked to
	int arr[size];			//Declairing array of size 
	cout<<"Enter 8 numbers: ";
	for(int i=0; i<size; i++){
		cin>>arr[i];		//Takes input from user
		
		if ( arr[i]%2==0){	//Checks if the number is even and if it is even it lets it stay as it is
			arr[i]=arr[i];
		}else{
			arr[i]=arr[i]+1;//Converts odd numbers into even 
		}
	}
	cout<<endl;
	cout<<"Updated Array: ";//Output display all even numbers
	for(int j=0; j<size; j++){
		cout<<arr[j]<<" ";
	}
	cout<<endl;
	
	int sum,diff,prod;		//Declaring the functions
	float div;				//Declairing division with float as the answer can be in points due to larger denominator
	float finalTotal=0;		//Initializing total of all the functions
	int operations = 0;
	for(int i=0; i<size; i=i+2){	//Performing all operations//Loop through array using 2 elements at a time  
		float a= arr[i];			//Using float as the answer can be in points
		float b= arr[i+1];
		sum= a+b;					
		diff= a-b;
		prod= a*b;
		if(b!=0){					//Condition to check that if denominator is 0, it is skipped
			div= a/b;
		}else{
			div=0;
		}
		//Displaying all operations for each pair of numbers seperately 
		cout<<"Pair ("<<a<<","<<b<<"): "<<"Sum="<<sum<<", "<<"Diff="<<diff<<", "<<"Prod="<<prod<<", "<<"Div="<<div<<endl;
	
	finalTotal= finalTotal+sum+diff+prod+div;	//final of all the operations stored in a variable 
	}
	cout<<endl;
	
	cout<<"Final Total of all operations = "<<finalTotal<<endl;//Display final total of aa operations 
	
	float updatedArraySum =0;
	for( int i=0; i<size; i++){		
		updatedArraySum = updatedArraySum + arr[i];
	}
	cout<<"Sum of all updated Array elements = "<<updatedArraySum;//Display sum of all updated array elements
	
	return 0;
}
