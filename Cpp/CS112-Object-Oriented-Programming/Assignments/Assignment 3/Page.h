#ifndef PAGE_H
#define PAGE_H
#include "Line.h"

class Page {
    Line* lines;
    int numLines;

public:
    Page();
    Page(const char* text);
    Page(const Page& copy);
    ~Page();

    Page& operator=(const Page& rhs);
    Page& operator+=(const char* text);
    Page& operator+=(const Line& line);
    Page& operator+=(const Page& rhs);
    Line& operator[](int index);

    int getNumLines() const;
    Line getLine(int index) const;

    friend ostream& operator<<(ostream& out, const Page& p);
};

#endif
