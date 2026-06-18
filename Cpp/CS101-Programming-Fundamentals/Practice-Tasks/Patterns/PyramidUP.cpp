#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n";                         
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int k=i; k<=n ; k++){
            cout<<" ";  
        }
        for(int j=1; j<2*i ; j++){
            cout<<"*";
        } 
        cout<<endl;
    }
	
	return 0;
	}
    
