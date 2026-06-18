#ifndef MANAGER_H
#define MANAGER_H
#include <string>

using namespace std;

class Manager {
private:
    string name;
public:
    // Default argument goes ONLY in the header!
    Manager(string n = ""); 
    string getManager() const;
};

#endif
