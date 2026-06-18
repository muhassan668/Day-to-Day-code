#include <iostream>
using namespace std;
 
class Student{              // making class
    private:
        int marks;
    public:
        int roll_no;
        Student(int r, int m){  // parameterized constructor of class
            roll_no = r;
            marks = m;
        }
        void displayMarks(){
            cout<<"Marks: "<<marks<<endl;
        }
 
    friend class Teacher;       // making the teacher class a friend of student class
};
class Teacher{
    public:
        void upgradeMarks(Student &s){
            s.marks += 10;
        }
};
 
int main(){
 
    Student s(123,15);
    Teacher t;
 
    cout<<"Before Upgrading Marks: "<<endl;
    s.displayMarks();
 
    cout<<"After Adding 10 Marks Using Upgrade Marks Function: "<<endl;
    t.upgradeMarks(s);
    s.displayMarks();
 
    return 0;
}
