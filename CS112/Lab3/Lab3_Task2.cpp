#include<iostream>
using namespace std;

struct student{                 // making user defined data type 
    string name;
    int rollnumber;
    float cgpa;
};

int main(){
    int n;
    cout<<"Total Number of Students : ";
    cin>>n;

    student* std = new student[n];      // making dynamic memory to store the details of the students 
    for(int i=0; i<n; i++){
        cout<<"Enter the name of Student "<<i+1<<" : ";
        cin>>std[i].name;
        cout<<"Enter roll number of Student "<<i+1<<" : ";
        cin>>std[i].rollnumber;
        cout<<"Enter CGPA of the Student "<<i+1<<" : ";
        cin>>std[i].cgpa;
    }
    float avg_cgpa = 0;
    for(int i=0; i<n; i++){             // calculating average cgpa
        avg_cgpa = avg_cgpa + std[i].cgpa;
    }
    avg_cgpa = avg_cgpa/n;
    cout<<"Average CGPA = "<<avg_cgpa<<endl;    // printing average cgpa

    int topper_index;
    float topper_cgpa=-3;
    for(int i=0; i<n; i++){
        if(std[i].cgpa>topper_cgpa){
            topper_cgpa = std[i].cgpa;          // finding the topper cgpa by compairing with the other student cgpas
            topper_index = i;                   // the index of the topper is declaired
        }
    }
    cout<<"Topper CGPA = "<<topper_cgpa<<endl;
    cout<<"Topper Index = "<<topper_index<<endl;

    delete[] std;                               // deleting 


    return 0;
}
