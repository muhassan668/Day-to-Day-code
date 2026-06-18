#include <iostream>
using namespace std;

class Person{
	protected:
		int id;
		string name;
	public: 
		Person(int i, string n): id(i), name(n){}
		void display(){}
};
class Doctor: public Person{
	string specialty;
	public:
		Doctor(int i, string n, string sp): Person(i,n){
			specialty = sp;
		}
		void display(){
			cout<<id<<" "<<name<<" "<<specialty<<endl;
		}
};
class Patient: public Person{
	string disease;
	public:
		Patient(int i, string n, string d): Person(i,n){
			disease = d;
		}
		void display(){
			cout<<id<<" "<<name<<" "<<disease<<endl;
		}
};
int main(){
	Person* database[10];
	int choice;
	do{
		cout<<"Menu..."<<endl;
		cout<<"1. Add Doctor."<<endl;
		cout<<"2. Add Patient."<<endl;
		cout<<"3. View All Records."<<endl;
		cout<<"4. Exit.";
		cin>>choice;
		
	}while(choice<5||choice>1);
	if(choice == 1){
		Doctor *d = new Doctor;
		database[0] = d(101, "Ali", "Heart");
	}else if(choice == 2){
		Patient *p = new Patient;
		database[1] = p(202, "Hassan", "Leg");
	}else if(choice == 3){
		database[0].display();
		cout<<endl;
		database[1].display();
	}
	
	return 0;
}
