#include <iostream>										// header file
using namespace std;

void swapIntegers(int* n1, int* n2) {					// function for swaping 2 integers
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void double_max_Array(int* arr, int size) {				// function for doubling each element of array
    for (int i = 0; i < size; i++) {
    	arr[i]=arr[i]*2;
	}   
}

int main() {
	// SWAPING INTEGERS 
	int n1,n2;
   	cout<<"Enter two integers to swap:"<<endl;			
   	cout<<"First integer: ";	
   		cin>>n1;										// taking input of first integer
   	cout<<"Second Integer: ";							
   		cin>>n2;										// taking input of second integer
	cout<<"Before swap: x = "<<n1<<", y = "<<n2<<endl;
	swapIntegers( &n1, &n2);							// Calling the fuctions to swap integers
	cout<<"After swap: x = "<<n1<<", y = "<<n2<<endl;
	
	// DOUBLING ARRAY ELEMENTS
	int size;
	

	int arr[size];										// redeclairing array 
		do{
			cout<<"Enter size of array: ";
			cin>>size;
			if(size<3){
				cout<<"Invalid! Please enter a size Greater than 3"<<endl; // input has to be greater than 3
			}
		}while(size<3);

	cout<<"Enter "<<size<<" elements for the array: "<<endl;	// getting input of array elements from user
	for(int i=0; i<size; i++){
		cout<<"Element "<<i+1<<": ";
		cin>>arr[i];
	}
	
	cout<<"Original Array: "<<endl;
	cout<<"Array elements with locations and addresses:"<<endl;	// showing the value and addresses of each element of original array
	for(int i=0; i<size; i++){
		cout<<"Index "<<i<<": Value = "<<*(arr+i)<<", Address = "<<arr+i<<endl;
	}
	
	cout<<"After doubling all elements: "<<endl;
	cout<<"Array elements with locations and addresses: "<<endl;
	double_max_Array(arr,size);				// Calling fuction to double the elements of array 
	for(int i=0;i<size;i++){
		cout<<"Index "<<i<<": Value = "<< *(arr+i)<<", Adress = "<<arr+i<<endl; // showing the values and sddreses of each element of new doubled array 
		
	}
	
	// SHOWING TOP 3 MAX VALUES 
	cout<<"Top 3 Maximum Values: "<<endl;
   
    for(int i=0; i<3; i++){							// loop for getting the maximun 3 numbers 
    	int max = *arr;								// assuming first element is maximum
    	int index = 0;								// index of maximum values
    	for(int j=0; j<size; j++){
    		if(*(arr + j ) > max ){					// compairing each element 
    			max = *(arr + j);					// updating each maximun after every itration
    			index = j;							// uodating index of maximum after every itration 
			}
		}

		cout<<i+1<<"st Max: "<<max<<" at Index "<<index<<" (Address: "<< arr + index <<")"<<endl;
		*(arr + index)= -999999; 					// for reseting the maximum elements after it is displayed once so it is not displayed twice 
	}
	
    return 0;
}
