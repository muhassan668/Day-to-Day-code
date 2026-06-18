#include "Project.h"

Project::Project(string t) {
    title = t;
    manager = NULL;
}

string Project::getTitle() const { 
    return title; 
}

void Project::setTitle(string t) { 
    title = t; 
}

Manager* Project::getManager() const { 
    return manager; 
}

void Project::setManager(Manager* m) { 
    manager = m; 
}
