#include <iostream>
using namespace std;
 
class Student{                          // creating class
    string name;                        // the first three are private variables
    int rollno;
    float marks;
    public:                             // making public variables and fnctions
    Student(){                          // default constructor
        name = "Unknown";
        rollno = 0;
        marks = 0;
    }
    Student( string n, int r, float m){ // parameterized constructor
        name = n;
        rollno = r;
        marks = m;
    }
    void display_data(){                // public function to display data
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<rollno<<endl;
        cout<<"Marks: "<<marks;
    }
};
int main(){
 
    string naam1, naam2;
    int roll1, roll2;
    float mark1, mark2;
 
    cout<<endl;
    cout<<"Student 1 with default."<<endl;
    Student s1;
    s1.display_data();                  // displaying the data of student 1 with default values
    cout<<endl<<endl;
 
    cout<<"Student 2 with parameterized."<<endl;
    cout<<"Student 2 name: ";
    cin>>naam1;
    cout<<"Student 2 Roll number: ";
    cin>>roll1;
    cout<<"Student 2 Marks: ";
    cin>>mark1;
    cout<<endl;
    Student s2(naam1,roll1,mark1);      // creating object which is calling parameterized constructor
    s2.display_data();
    cout<<endl<<endl;
 
    cout<<"Student 3 with parameterized."<<endl;
    cout<<"Student 3 Name: ";
    cin>>naam2;
    cout<<"Student 3 Roll Number: ";
    cin>>roll2;
    cout<<"Student 3 Marks: ";
    cin>>mark2;
    cout<<endl;
    Student s3(naam2,roll2,mark2);
    s3.display_data();
    cout<<endl;
 
 
    return 0;
}
