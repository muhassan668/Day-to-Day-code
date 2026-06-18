#include <iostream>
using namespace std;

int main(){
	int n;
	cout<<"Enter Rows ";
	cin>>n;
	
	for( int i=0; i<=n; i++){
			for(int k=i;k<=n;k++){
				cout<<"  ";			// cout me 2 spaces deni paren gi // cout me 1 space ke sath pyramid banega. 
			}
		for(int j=1;j<=1+i;j++){		// j<=i karen ge triangle ke lie // agar two uparneechay triangle banane hain to j<=1+i
			cout<<"* ";
		}
		cout<<endl;
	}
	for(int l=0;l<=n+1;l++){
		cout<<"* ";
	}
	cout<<endl;
		for( int i=0; i<=n; i++){
				for(int k=0;k<=i;k++){
					cout<<"  ";
			}
			for(int j=0;j<=n-i;j++){
			cout<<"* ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
