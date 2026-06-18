// Book.cpp
#include "Book.h"

Book::Book() {
    pages = NULL;
    numPages = 0;
}

Book::Book(int num) {
    numPages = num;
    if (numPages > 0) {
        pages = new Page[numPages];
    } else {
        pages = NULL;
    }
}

Book::Book(const Book& copy) {
    numPages = copy.numPages;
    if (numPages > 0) {
        pages = new Page[numPages];
        for (int i = 0; i < numPages; i++) {
            pages[i] = copy.pages[i];
        }
    } else {
        pages = NULL;
    }
}

Book::~Book() {
    delete[] pages;
}

Book& Book::operator=(const Book& rhs) {
    if (this != &rhs) {
        delete[] pages;
        numPages = rhs.numPages;
        if (numPages > 0) {
            pages = new Page[numPages];
            for (int i = 0; i < numPages; i++) {
                pages[i] = rhs.pages[i];
            }
        } else {
            pages = NULL;
        }
    }
    return *this;
}

Book& Book::operator+=(const Page& p) {
    for (int i = 0; i < p.getNumLines(); i++) {
        Line temp = p.getLine(i);
        
        bool added = false;
        for (int j = 0; j < numPages; j++) {
            if (pages[j].getNumLines() < 20) {
                pages[j] += temp;
                added = true;
                break;
            }
        }
        
        if (!added) {
            Page* newPages = new Page[numPages + 1];
            for (int j = 0; j < numPages; j++) {
                newPages[j] = pages[j];
            }
            newPages[numPages] += temp;
            delete[] pages;
            pages = newPages;
            numPages++;
        }
    }
    return *this;
}

Page& Book::operator[](int index) {
    if (index >= numPages) {
        Page* newPages = new Page[index + 1];
        for (int i = 0; i < numPages; i++) {
            newPages[i] = pages[i];
        }
        delete[] pages;
        pages = newPages;
        numPages = index + 1;
    }
    return pages[index];
}

Book Book::operator+(const Book& b) const {
    Book result;
    for (int i = 0; i < numPages; i++) {
        result += pages[i];
    }
    for (int i = 0; i < b.numPages; i++) {
        result += b.pages[i];
    }
    return result;
}

ostream& operator<<(ostream& out, const Book& b) {
    for (int i = 0; i < b.numPages; i++) {
        out << "--- Page " << (i + 1) << " ---" << endl;
        out << b.pages[i];
    }
    return out;
}
