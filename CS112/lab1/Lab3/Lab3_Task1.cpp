#include <iostream>
using namespace std;
int main(){

    int fixed_arr[10];                  // making static memory
    int *dynamic_arr = new int[7];      // making dynamic memory

    cout<<"Enter the elements of the Fixed Array."<<endl;
    for(int i=0; i<10; i++){
        cout<<"Element # "<<i+1<<" : ";     // taking input of the static memory 
        cin>>fixed_arr[i];
    }
    cout<<endl;
    cout<<"Enter the elements of the Dynamic Array."<<endl;     // taking input of the dynamic memory
    for(int i=0; i<7; i++){
        cout << "Element # " << i + 1 << " : ";
        cin>>dynamic_arr[i];
    }
    cout<<endl;
    cout<<"Fixed Array:"<<endl;
    for(int i=0; i<10; i++){
        cout<<"Element # "<<i+1<<" = "<<fixed_arr[i]<<endl;     // printing static memory 
    }

    cout<<"Dynamic Array:"<<endl;
    for(int i=0; i<7; i++){
        cout<<"Element # "<<i+1<<" = "<<dynamic_arr[i]<<endl;   // printing dynamic memory
    }

    delete[] dynamic_arr;           // deleting dynamic array to free memory 

    return 0;
}
