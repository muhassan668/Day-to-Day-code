#include <iostream>
#include <iomanip>
#include "basic_func.cpp"

using namespace std;

#define INITIAL_SIZE 3
#define DOUBLE_SIZE(x) ((x) * 2)

int main(){
    int capacity = INITIAL_SIZE;
    int count = 0;

    Student *students = new Student[capacity];

    while (true){
        if (count == capacity){
            capacity = DOUBLE_SIZE(capacity);
            Student *temp = new Student[capacity];

            for (int i = 0; i < count; i++){
                temp[i] = students[i];
            }

            delete[] students;
            students = temp;
        }

        cout << "\nEnter data of student " << count + 1<< " (-1 in marks to stop)\n";
        cout << "Enter Student Name: ";
        cin >> students[count].name;
        cout << "Enter Roll Number: ";
        cin >> students[count].rollno;
        cout << "Enter Marks: ";
        cin >> students[count].marks;
        if (students[count].marks == -1){
            break;
        }

        count++;
    }

    if (count == 0){
        cout << "No student data entered.";
        delete[] students;
        return 0;
    }

    cout << "\nStudent Database:\n";

    for (int i = 0; i < count; i++){
        cout << students[i].name
             << " (Roll No. " << students[i].rollno
             << ") Marks: " << students[i].marks << endl;
    }

    cout << "\nHighest Marks: " << max(students, count) << endl;
    cout << "Lowest Marks: " << min(students, count) << endl;
    cout << "Average Marks: " << avg(students, count) << endl;

    delete[] students;

    return 0;
}