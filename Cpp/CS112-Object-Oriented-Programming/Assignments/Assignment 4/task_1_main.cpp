#include <iostream>
#include "LibrarySystem.h"
#include "StudyBook.h"
#include "Magazine.h"
#include "Journal.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;

int main() {
    LibrarySystem lib(20, 10);

    StudyBook* sb1 = new StudyBook("B1", "Physics", "Newton", 1, "2023-01-01");
    StudyBook* sb2 = new StudyBook("B2", "Calculus", "Stewart", 8, "2022-05-15");
    StudyBook* sb3 = new StudyBook("B3", "Chemistry", "Zumdahl", 10, "2021-08-20");
    StudyBook* sb4 = new StudyBook("B4", "Biology", "Campbell", 11, "2020-01-10");
    StudyBook* sb5 = new StudyBook("B5", "History", "Smith", 3, "2019-03-22");
    Magazine* mag1 = new Magazine("M1", "Nat Geo", "Various", 2024, "2024-01-01");
    Magazine* mag2 = new Magazine("M2", "Time", "Various", 2024, "2024-02-01");
    Journal* j1 = new Journal("J1", "IEEE Software", "IEEE", 5, "2023-11-01");
    Journal* j2 = new Journal("J2", "Nature", "Springer", 1, "2023-12-01");
    Journal* j3 = new Journal("J3", "Science", "AAAS", 1, "2024-01-01");

    lib.addItem(sb1);
    lib.addItem(sb2);
    lib.addItem(sb3);
    lib.addItem(sb4);
    lib.addItem(sb5);
    lib.addItem(mag1);
    lib.addItem(mag2);
    lib.addItem(j1);
    lib.addItem(j2);
    lib.addItem(j3);

    Student* s1 = new Student("S1", "Alice", "123 Elm St", "555-0001");
    Student* s2 = new Student("S2", "Bob", "456 Oak St", "555-0002");
    Student* s3 = new Student("S3", "Charlie", "789 Pine St", "555-0003");
    
    Faculty* f1 = new Faculty("F1", "Dr. Smith", "101 Faculty Row", "555-1001");
    Faculty* f2 = new Faculty("F2", "Dr. Jones", "102 Faculty Row", "555-1002");

    lib.addPerson(s1);
    lib.addPerson(s2);
    lib.addPerson(s3);
    lib.addPerson(f1);
    lib.addPerson(f2);

    lib.issueItem(s1, sb1);
    lib.issueItem(s1, sb2);
    lib.issueItem(s1, mag1);

    lib.issueItem(s2, j1);

    lib.issueItem(s3, mag2);
    lib.issueItem(s3, sb3);
    
    lib.issueItem(s3, sb1);

    lib.issueItem(f1, j2);
    lib.issueItem(f1, j3);
    lib.issueItem(f1, sb4);
    
    lib.returnItem(s2,j1,20);

    return 0;
}
