#ifndef PROJECT_H
#define PROJECT_H
#include <string>
#include "Manager.h"

using namespace std;

class Project {
private:
    string title;
    Manager* manager;

public:
    Project(string t = "");
    string getTitle() const;
    void setTitle(string t);
    Manager* getManager() const;
    void setManager(Manager* m);
};

#endif
