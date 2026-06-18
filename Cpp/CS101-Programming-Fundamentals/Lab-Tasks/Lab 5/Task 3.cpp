#include <iostream>
using namespace std;
	
void menu(int choice){
	cout<<"   ===Number Generator===   "<<endl;
	cout<<"1.Fibonacci Sequence"<<endl;
	cout<<"2.Factorial"<<endl;
	cout<<"3.Exit"<<endl;
	cin>>choice;
}
void factorial(int n){
	int factoral = 1;
	for(int i=1;i<=n; i++){
		factoral = factoral *i;
	}
	cout<<"Factorial = "<<factoral<<endl;
}
void fibonacci(int n){
    
	int first = 0, second = 1, next;
	for (int i = 1; i <= n; ++i) {
        cout << first << " ";
        next = first + second;
        first = second;
        second = next;
    }
}
 
 
 
int main(){
	int choice,q,n,w;
do {
	
	cout<<"   ===Number Generator===   "<<endl;
	cout<<"1.Fibonacci Sequence"<<endl;
	cout<<"2.Factorial"<<endl;
	cout<<"3.Exit"<<endl;
	cout<<"Enter a Choice"<<endl;
	cin>>choice;
	



	if (choice == 1){
		cout<< "Enter the number of terms :";
		cin>>q;
		fibonacci(q);
	cout<<endl;
		
	}
	else if (choice == 2){
		cout<<"Enter number to factoral :";
		cin>>n;
		factorial(n);

	}
	
	else (choice == 3);{
		cout<<"Have a good Day!"<<endl;
		
}
}while(choice == 1 || choice == 2);
	return 0;
}
