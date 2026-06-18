#include "Page.h"

Page::Page() {
    lines = NULL;
    numLines = 0;
}

Page::Page(const char* text) {
    lines = NULL;
    numLines = 0;
    *this += text; 
}

Page::Page(const Page& copy) {
    numLines = copy.numLines;
    if (numLines > 0) {
        lines = new Line[numLines];
        for (int i = 0; i < numLines; i++) {
            lines[i] = copy.lines[i];
        }
    } else {
        lines = NULL;
    }
}

Page::~Page() {
    delete[] lines;
}

Page& Page::operator=(const Page& rhs) {
    if (this != &rhs) {
        delete[] lines;
        numLines = rhs.numLines;
        if (numLines > 0) {
            lines = new Line[numLines];
            for (int i = 0; i < numLines; i++) {
                lines[i] = rhs.lines[i];
            }
        } else {
            lines = NULL;
        }
    }
    return *this;
}

Page& Page::operator+=(const char* text) {
    int i = 0;
    while (text[i] != '\0') {
        while (text[i] == ' ') i++;
        if (text[i] == '\0') break;

        int start = i;
        int wLen = 0;
        while (text[i] != ' ' && text[i] != '\0') {
            wLen++;
            i++;
        }

        char* word = new char[wLen + 1];
        for (int j = 0; j < wLen; j++) {
            word[j] = text[start + j];
        }
        word[wLen] = '\0';

        if (numLines == 0) {
            lines = new Line[1];
            lines[0].addWord(word);
            numLines = 1;
        } else {
            if (!lines[numLines - 1].addWord(word)) {
                if (numLines < 20) {
                    Line* newLines = new Line[numLines + 1];
                    for (int k = 0; k < numLines; k++) {
                        newLines[k] = lines[k];
                    }
                    newLines[numLines].addWord(word);
                    delete[] lines;
                    lines = newLines;
                    numLines++;
                }
            }
        }
        delete[] word;
    }
    return *this;
}

Page& Page::operator+=(const Line& line) {
    if (numLines < 20) {
        Line* newLines = new Line[numLines + 1];
        for (int i = 0; i < numLines; i++) {
            newLines[i] = lines[i];
        }
        newLines[numLines] = line;
        delete[] lines;
        lines = newLines;
        numLines++;
    }
    return *this;
}

Page& Page::operator+=(const Page& rhs) {
    for (int i = 0; i < rhs.getNumLines(); i++) {
        *this += rhs.getLine(i);
    }
    return *this;
}

Line& Page::operator[](int index) {
    if (index >= numLines) {
        int newSize = index + 1;
        if (newSize > 20) newSize = 20; 
        
        Line* newLines = new Line[newSize];
        for (int i = 0; i < numLines; i++) {
            newLines[i] = lines[i];
        }
        delete[] lines;
        lines = newLines;
        numLines = newSize;
        
        if (index >= 20) return lines[19];
    }
    return lines[index];
}

int Page::getNumLines() const {
    return numLines;
}

Line Page::getLine(int index) const {
    return lines[index];
}

ostream& operator<<(ostream& out, const Page& p) {
    for (int i = 0; i < p.numLines; i++) {
        out << p.lines[i] << endl;
    }
    return out;
}
