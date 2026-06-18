#include <iostream>
#include <string>
#include <sstream>
#include "Manager.h"
#include "Project.h"
#include "Employee.h"

using namespace std;

int main() {
    // Step 4: Create the 4 managers
    Manager m1("Michael");
    Manager m2("Dwight");
    Manager m3("Jim");
    Manager m4("Andy");

    // Step 5: Create an array of 15 employees
    Employee employees[15];

 // Step 6: Populate the array
    for (int i = 0; i < 15; i++) {
        
        // Old-school integer to string conversion
        stringstream ssName;
        ssName << (i + 1);
        employees[i].setName("Worker " + ssName.str());
        
        // Give some projects to test output
        if (i % 3 != 0) { 
            stringstream ssProj;
            ssProj << (i + 100);
            employees[i].setProject("Project " + ssProj.str());
        }
        
    } // <-- Don't forget this closing bracket for the loop!

    // Step 7: Assign managers (Array indices are Employee # minus 1)
    
    // a. First manager (Michael) to 1st and 2nd employee
    employees[0].allocateManager(&m1);
    employees[1].allocateManager(&m1);

    // b. Second manager (Dwight) to 3rd and 7th employee
    employees[2].allocateManager(&m2);
    employees[6].allocateManager(&m2);

    // c. Third manager (Jim) to 4th through 9th EXCEPT 7th
    employees[3].allocateManager(&m3);
    employees[4].allocateManager(&m3);
    employees[5].allocateManager(&m3);
    // Index 6 (7th employee) is skipped!
    employees[7].allocateManager(&m3);
    employees[8].allocateManager(&m3);

    // d. Fourth manager (Andy) to 14th and 15th
    employees[13].allocateManager(&m4);
    employees[14].allocateManager(&m4);

    // Step 8: Print
    cout << "=== MAINTENANCE MANAGEMENT SYSTEM ===" << endl;
    for (int i = 0; i < 15; i++) {
        employees[i].print();
    }

    return 0;
}
