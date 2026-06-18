// Line.cpp
#include "Line.h"

Line::Line() {
    length = 0;
    text = new char[41];
    text[0] = '\0';
}

Line::Line(const char* t) {
    text = new char[41];
    *this = t; 
}

Line::Line(const Line& copy) {
    length = copy.length;
    text = new char[41];
    for (int i = 0; i <= length; i++) {
        text[i] = copy.text[i];
    }
}

Line::~Line() {
    delete[] text;
}

Line& Line::operator=(const Line& rhs) {
    if (this != &rhs) {
        length = rhs.length;
        for (int i = 0; i <= length; i++) {
            text[i] = rhs.text[i];
        }
    }
    return *this;
}

Line& Line::operator=(const char* t) {
    length = 0;
    while (t[length] != '\0' && length < 40) {
        text[length] = t[length];
        length++;
    }
    text[length] = '\0';
    return *this;
}

bool Line::addWord(const char* word) {
    int wLen = 0;
    while (word[wLen] != '\0') wLen++;

    if (length == 0) {
        if (wLen <= 40) {
            for (int i = 0; i < wLen; i++) text[i] = word[i];
            length = wLen;
            text[length] = '\0';
            return true;
        }
        return false;
    } else {
        if (length + 1 + wLen <= 40) {
            text[length] = ' ';
            for (int i = 0; i < wLen; i++) text[length + 1 + i] = word[i];
            length += 1 + wLen;
            text[length] = '\0';
            return true;
        }
        return false;
    }
}

int Line::getLength() const {
    return length;
}

const char* Line::getText() const {
    return text;
}

ostream& operator<<(ostream& out, const Line& l) {
    out << l.text;
    return out;
}
