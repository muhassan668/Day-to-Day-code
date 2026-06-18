// Line.h
#ifndef LINE_H
#define LINE_H
#include <iostream>

using namespace std;

class Line {
    char* text;
    int length;

public:
    Line();
    Line(const char* t);
    Line(const Line& copy);
    ~Line();

    Line& operator=(const Line& rhs);
    Line& operator=(const char* t);
    
    bool addWord(const char* word);
    int getLength() const;
    const char* getText() const;

    friend ostream& operator<<(ostream& out, const Line& l);
};

#endif
