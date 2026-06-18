#include <iostream>
using namespace std;

int main()
{
    int capacity = 5;
    int count = 0;
    int *students = new int[capacity];      // making dynamic memory
    int n;

    cout << "Enter the number of students to register: ";
    cin >> n;

    for (int i = 0; i < n; i++){
        if (count == capacity){
            int newCapacity = capacity * 2;
            int *newArr = new int[newCapacity];     // initializing the dynamic memory

            for (int j = 0; j < capacity; j++){
                newArr[j] = students[j];
            }
            delete[] students;                      // freeing memory 
            students = newArr;
            capacity = newCapacity;
        }
        cout << "Enter Student ID: ";
        cin >> students[count];
        count++; 
    }
    cout << "\nFinal list of Student IDs: ";        // printing the list of students
    for (int i = 0; i < count; i++){
        cout << students[i] << " ";
    }
    cout << endl; 

    cout << "Final capacity: " << capacity << endl; // printing the capacity
    cout << "Total number of registered students: " << count << endl;

    int searchID;
    bool found = false;
    cout << "\nEnter Student ID to search: ";
    cin >> searchID;

    for (int i = 0; i < count; i++){
        if (students[i] == searchID){           // checking if the id match 
            found = true;
            break;
        }}
    if (found){
        cout << "Student ID found." << endl;
    }
    else{
        cout << "Student ID not found." << endl;
    }
    int removeID;
    int removeIndex = -1;
    cout << "\nEnter Student ID to remove: ";
    cin >> removeID;

    for (int i = 0; i < count; i++){
        if (students[i] == removeID){
            removeIndex = i;
            break;
        }}
    if (removeIndex != -1){
        for (int i = removeIndex; i < count - 1; i++){
            students[i] = students[i + 1];
        }
        count += -1;
        cout << "Student ID removed." << endl;
    }
    else{
        cout << "Student ID not found." << endl;
    }
    cout << "Updated list of Student IDs: ";        // printing the updated list of student ids 
    for (int i = 0; i < count; i++){
        cout << students[i] << " ";
    }
    cout << endl;

    delete[] students;

    return 0;
}