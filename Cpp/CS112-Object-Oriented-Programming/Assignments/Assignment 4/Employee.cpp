#include "Employee.h"
#include <iostream>

Employee::Employee() {
    name = "Unassigned";
    project = new Project(); // Composition birth
}

Employee::~Employee() {
    delete project; // Composition death
}

void Employee::setName(string n) { 
    name = n; 
}

void Employee::setProject(string t) { 
    project->setTitle(t); 
}

void Employee::allocateManager(Manager* m) { 
    project->setManager(m); 
}

void Employee::print() const {
    cout << "Employee: " << name << "\t";
    
    if (project->getTitle() != "") {
        cout << "| Project: " << project->getTitle() << "\t";
        if (project->getManager() != NULL) {
            cout << "| Manager: " << project->getManager()->getManager();
        } else {
            cout << "| Manager: Unsupervised";
        }
    } else {
        cout << "| Project: None (Unsupervised)";
    }
    cout << endl;
}
