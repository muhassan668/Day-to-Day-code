#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter a number";
    cin>>n;
    bool isprime = true;
    if(n<2){
        isprime = false;
    }
    else{
        for(int i=2 ; i<=n-1 ; i++){
            if(n%i==0){
                isprime = false;
            }
        }
    }
    if(isprime){
        cout<<"it is prime";
    }
    else{
        cout<<"not a prime";
    }


    return 0;
}
