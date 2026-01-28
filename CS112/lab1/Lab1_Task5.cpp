#include<iostream>
#include<string>
using namespace std;

struct Contact{
	string phone_no;
	char email[50];
	string address;
};
struct Student{
	int roll_no;
	string name;
	int age;
	float CGPA;
	Contact c1;
};

int main(){
	
	Student s1;
	cout<<"Enter the Roll Number of the Student: ";
	cin>>s1.roll_no;
	cout<<"Enter the Name of the Student: ";
	cin.ignore();
	getline(cin,s1.name);
	cout<<"Enter the Age of the Student: ";
	cin>>s1.age;
	cout<<"Enter the CGPA of the Student: ";
	cin>>s1.CGPA;
	cout<<"Enter the Phone Number of the Student: ";
	cin.ignore();
	getline(cin,s1.c1.phone_no);
	cout<<"Enter the Email of the Student: ";
	cin>>s1.c1.email;
	cout<<"Enter the Address of the Student: ";
	cin.ignore();
	getline(cin,s1.c1.address);
	cout<<endl;
	
	cout<<"Entered Details of the Student are: "<<endl;
	cout<<"Roll Number of the Student: "<<s1.roll_no<<endl;
	cout<<"Name of the Student: "<<s1.name<<endl;
	cout<<"Age of the Student: "<<s1.age<<endl;
	cout<<"CGPA of the Student: "<<s1.CGPA<<endl;
	cout<<"Phone Number of the Student: "<<s1.c1.phone_no<<endl;
	cout<<"Email of the Student: "<<s1.c1.email<<endl;
	cout<<"Address of the Student: "<<s1.c1.address<<endl;

	return 0;
}
