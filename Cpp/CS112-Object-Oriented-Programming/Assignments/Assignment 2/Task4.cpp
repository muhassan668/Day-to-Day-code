#include "Task4.h"
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

// Constructor
Record::Record(char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }

    fileName = new char[length + 1];
    for (int i = 0; i <= length; i++) {
        fileName[i] = str[i];
    }

    // Create the file if it does not already exist
    ofstream file(fileName, ios::app);
    file.close();
}

// Destructor
Record::~Record() {
    delete[] fileName;
}

// Helper function to manually compare two strings
bool Record::compareStrings(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return (str1[i] == '\0' && str2[i] == '\0');
}

// Function to input records
int Record::record_Input() {
    ofstream file(fileName, ios::app);

    if (!file) {
        return -1;
    }

    char name[100], address[100], age[10], cgpa[10];

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Address: ";
    cin >> address;

    cout << "Enter Age: ";
    cin >> age;

    cout << "Enter CGPA: ";
    cin >> cgpa;

    file << name << " " << address << " " << age << " " << cgpa << endl;

    file.close();
    return 1;
}

// Function to display all records
void Record::record_Display() {
    ifstream file(fileName);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    char line[200];

    cout << "\nAll Records:\n";
    cout << "------------------------------------------\n";

    while (file.getline(line, 200)) {
        cout << line << endl;
    }

    cout << "------------------------------------------\n";

    file.close();
}

// Function to delete a record by name
int Record::delete_Record() {
    ifstream file(fileName);

    if (!file) {
        return -1;
    }

    ofstream temp("temp.txt");

    if (!temp) {
        file.close();
        return -1;
    }

    char deleteNameBuffer[100];
    cout << "Enter name to delete: ";
    cin >> deleteNameBuffer;

    char name[100], address[100], age[10], cgpa[10];
    bool deleted = false;

    while (file >> name >> address >> age >> cgpa) {
        if (!compareStrings(name, deleteNameBuffer)) {
            temp << name << " " << address << " " << age << " " << cgpa << endl;
        } else {
            deleted = true;
        }
    }

    file.close();
    temp.close();

    remove(fileName);
    rename("temp.txt", fileName);

    return deleted ? 1 : 0;
}

// Function to count records in the file
int Record::record_Count() {
    ifstream file(fileName);

    if (!file) {
        return -1;
    }

    int count = 0;
    char line[200];

    while (file.getline(line, 200)) {
        count++;
    }

    file.close();

    cout << "Total records: " << count << endl;
    return count;
}

// Function to search for a record by name
int Record::record_Search() {
    ifstream file(fileName);

    if (!file) {
        return -1;
    }

    char searchNameBuffer[100];
    cout << "Enter name to search: ";
    cin >> searchNameBuffer;

    char name[100], address[100], age[10], cgpa[10];
    bool found = false;

    while (file >> name >> address >> age >> cgpa) {
        if (compareStrings(name, searchNameBuffer)) {
            cout << "\nRecord Found:\n";
            cout << "Name: " << name << endl;
            cout << "Address: " << address << endl;
            cout << "Age: " << age << endl;
            cout << "CGPA: " << cgpa << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Record not found." << endl;
    }

    file.close();

    return found ? 1 : 0;
}

// Function to insert a record after a specific name
int Record::record_Insert() {
    ifstream file(fileName);

    if (!file) {
        return -1;
    }

    ofstream temp("temp.txt");

    if (!temp) {
        file.close();
        return -1;
    }

    char insertAfterName[100];
    cout << "Enter name after which to insert: ";
    cin >> insertAfterName;

    char newName[100], newAddress[100], newAge[10], newCGPA[10];
    cout << "Enter new Name: ";
    cin >> newName;
    cout << "Enter new Address: ";
    cin >> newAddress;
    cout << "Enter new Age: ";
    cin >> newAge;
    cout << "Enter new CGPA: ";
    cin >> newCGPA;

    char name[100], address[100], age[10], cgpa[10];
    bool inserted = false;

    while (file >> name >> address >> age >> cgpa) {
        temp << name << " " << address << " " << age << " " << cgpa << endl;

        if (compareStrings(name, insertAfterName)) {
            temp << newName << " " << newAddress << " " << newAge << " " << newCGPA << endl;
            inserted = true;
        }
    }

    file.close();
    temp.close();

    remove(fileName);
    rename("temp.txt", fileName);

    return inserted ? 1 : 0;
}

// Function to replace a record by name
void Record::record_Replace() {
    ifstream file(fileName);

    if (!file) {
        cout << "Error opening file." << endl;
        return;
    }

    ofstream temp("temp.txt");

    if (!temp) {
        file.close();
        cout << "Error creating temporary file." << endl;
        return;
    }

    char replaceName[100];
    cout << "Enter name to replace: ";
    cin >> replaceName;

    char newName[100], newAddress[100], newAge[10], newCGPA[10];
    cout << "Enter new Name: ";
    cin >> newName;
    cout << "Enter new Address: ";
    cin >> newAddress;
    cout << "Enter new Age: ";
    cin >> newAge;
    cout << "Enter new CGPA: ";
    cin >> newCGPA;

    char name[100], address[100], age[10], cgpa[10];
    bool replaced = false;

    while (file >> name >> address >> age >> cgpa) {
        if (compareStrings(name, replaceName)) {
            temp << newName << " " << newAddress << " " << newAge << " " << newCGPA << endl;
            replaced = true;
        } else {
            temp << name << " " << address << " " << age << " " << cgpa << endl;
        }
    }

    file.close();
    temp.close();

    remove(fileName);
    rename("temp.txt", fileName);

    if (replaced) {
        cout << "Record replaced successfully." << endl;
    } else {
        cout << "Record not found." << endl;
    }
}