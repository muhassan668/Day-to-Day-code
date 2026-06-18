     // TASK 2

#include <iostream>
using namespace std;
int main(){
	int Marks ;
	cout<<"Enter Marks : ";
	cin>> Marks;
	switch (Marks/10){
		case 10 :
		case 9 :
			cout<<"Grade 'A'\n";
			break;
		case 8:
			cout<<"Grade 'B'\n";
			break;
		case 7 :
			cout<<"Grade 'C'\n";
			break;
		case 6 :
			cout<<"Grade 'D'\n";
			break;
		case 5 :
			cout<<"'You Failed\n''";
			break;	
		case 4 :
			cout<<"'You Failed\n'";
			break;
		case 3 :
			cout<<"'You Failed\n'";
			break;
		case 2 :
			cout<<"'You Failed\n'";
			break;
		case 1 :
			cout<<"'You Failed\n'";
			break;
		case 0 :
			cout<<"'You Failed\n'";
			break;
	default:
		cout<<"The number entered is invalid\n";
	}
	
	
	return 0;
}

//int ko 10 se devide se puri range aa jati hai 








































