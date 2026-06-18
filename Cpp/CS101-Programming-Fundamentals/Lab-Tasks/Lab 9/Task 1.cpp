#include <iostream>							// header file 
using namespace std;
int main(){
	
	int arr[5]={10,20,30,40,50};			// declairing and initializing array
	int *ptr = arr;							// pointing to te first element of array
	
	cout<<"Array elements using pointer arithmetic:"<<endl;
	for(int i=1; i<=5; i++){
		cout<<"Element "<<i<<" at adress "<< ptr+i<<" : "<< *ptr <<endl; // printing each element of array by...
		ptr++;																// incrementing the pointer
	}
	cout<<endl;
	
	ptr = arr;
	cout<<"Accessing elements using *(ptr+i):"<<endl;
	for(int i=0;i<=4;i++){									// accessing each elemnt using pointer
		cout<<"*(ptr + "<<i<<") = "<<*ptr<<endl;
		ptr++;
	}
	
	return 0;	
}
