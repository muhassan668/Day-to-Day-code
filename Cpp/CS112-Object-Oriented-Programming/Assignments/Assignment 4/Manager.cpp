#include "Manager.h"

Manager::Manager(string n) {
    name = n;
}

string Manager::getManager() const {
    return name;
}
