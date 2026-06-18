// Book.h
#ifndef BOOK_H
#define BOOK_H
#include "Page.h"

class Book {
    Page* pages;
    int numPages;

public:
    Book();
    Book(int num);
    Book(const Book& copy);
    ~Book();

    Book& operator=(const Book& rhs);
    Book& operator+=(const Page& p);
    Page& operator[](int index);
    Book operator+(const Book& b) const;

    friend ostream& operator<<(ostream& out, const Book& b);
};

#endif
