#include <iostream>
#include <string>
using namespace std;

void Display(string arr[2][10]){
    for(int i=0; i<2; i++){
	    for(int j=0; j<10; j++){
		    cout<<arr[i][j]<<"     ";
    	}
	cout<<endl;
    }
}
void SWAP(string arr[2][10], int col1, int col2){
    string tempname = arr[0][col1];
    arr[0][col1]=arr[0][col2];
    arr[0][col2]=tempname;

    string tempstatus= arr[1][col1];
    arr[1][col1]=arr[1][col2];
    arr[1][col2]=tempstatus;
}

void selection_sort(string arr[2][10]){
    for(int i=0; i<9; i++){
        int maxIndex = i;
        for(int j=i+1; j<10; j++){
            if ( arr[1][j]> arr[1][maxIndex]){
                maxIndex = j;
            }
        }
        if (maxIndex != i ){
            SWAP(arr, i, maxIndex);
        }
    }
}

void transfer(string source[2][10], string destination[2][10]) {
    int k = 0; // Counter for the destination array (Iffat's house)
    
    for(int i = 0; i < 10; i++) {
        // Check if the person is Negative
        if(source[1][i] == "N") {
            destination[0][k] = source[0][i]; // Copy Name
            destination[1][k] = source[1][i]; // Copy Status
            k++; // Move to the next empty slot in Iffat's house
        }
    }
}


int main(){

    string arr[2][10]={
        {"Amna","Father","Mother","Sister","Brother1","Brother2","Grandfather","Grandmother","Uncle","Aunt"},
        {"P","N","P","N","P","P","N","N","N","N"}
    };
    string iffatshouse[2][10];

    cout<<"Before Sorting "<<endl;
    Display(arr);
    selection_sort(arr);
    cout<<endl;
    cout<<"After Sorting "<<endl;
    Display(arr);
    cout<<endl;
    cout<<"Iffat's House "<<endl;
    transfer(arr,iffatshouse);
    Display(iffatshouse);



    return 0;
    
}