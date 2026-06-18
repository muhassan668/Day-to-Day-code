#include<iostream>
#include<string>
using namespace std;

struct Student{
	int id;
	string name;
	float marks;
};
int main(){
	Student s[5];
	float avg = 0;
	for (int i=0; i<5; i++){
		cout<<"Enter the Details of Student "<<i+1<<" :"<<endl;
		cout<<"Enter ID : ";
		cin>>s[i].id;
		cout<<"Enter Name : ";
		cin.ignore();
		getline(cin,s[i].name);
		cout<<"Enter Marks : ";
		cin>>s[i].marks;
	}
	for(int i=0; i<5; i++){
		avg = avg + s[i].marks;
	}
	avg = avg/5;
	
	cout<<"Students who scorred Higher than the Average are: "<<endl;
	for(int i=0; i<5; i++){
		if (avg<s[i].marks){
			cout<<"ID: "<<s[i].id<<"  Name: "<<s[i].name<<endl;
		}
	}
	return 0;
}
