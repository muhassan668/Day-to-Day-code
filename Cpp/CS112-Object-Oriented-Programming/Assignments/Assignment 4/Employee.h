#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Project.h"
#include "Manager.h"

using namespace std;

class Employee {
private:
    string name;
    Project* project; // Your awesome Composition pointer!

public:
    Employee();
    ~Employee();
    
    void setName(string n);
    void setProject(string t);
    void allocateManager(Manager* m);
    void print() const;
};

#endif
