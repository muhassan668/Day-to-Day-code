#include <iostream>
using namespace std;
int main(){
	
	float arr[6][6]={						//Initializing 2D array with given values
		
		{1	, 2 , 1 , 2 , 1 , 2 },
		{1 , 2 , 3 , 4 , 5 , 6},
		{0 , -1 , -2.5 , -4 , -5.5 , -8 },
		{ -3.5 , -4.5 , -6 , -2 , -9.5 , -9 },
		{-2.9 , 10 , 11 , 12 , -17.5 , 9 },
		{ 3.8 , 8 , 1.5 , -6 , 2 , 8 }
	};
	
cout<<"The negative values are:";
cout<<endl;								
	for ( int i=0; i<6; i++){				//For loop to seperate all the negative values from the array
		for ( int j=0; j<6; j++){
			if( arr[i][j]<0 ){
				cout<<"Arr["<<i<<"]"<<"["<<j<<"] = "<<arr[i][j];
				cout<<endl;
			}
		}
	}
cout<<endl;
	
cout<<"Diagonal Values are:";
cout<<endl;
	for (int i=0; i<6; i++){				//For loop to seperate all the bold values while retaining their pattern 
		for (int j=0; j<=i; j++){
			
			cout<<arr[i][j]<<"  ";
		}	
		cout<<endl;
	}	
	
	
	return 0;
	
}
