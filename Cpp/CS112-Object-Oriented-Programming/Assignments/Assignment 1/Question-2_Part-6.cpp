#include <iostream>
using namespace std;

void printChar(int n, char c) {
    if (n <= 0) return;
    cout << c;
    printChar(n - 1, c);
}
void PrintPattern2(int k, int n) {
    int row = n - k + 1;
    int spaces = k - 1;
    int width = (n - 2) + (row - 1);
    int numDots, numStars;
    if (k == 1) {
        numDots = width;
        numStars = 0;
    } else {
        numDots = k - 2;
        numStars = width - numDots;
    }
    printChar(spaces, ' ');   
    cout << "#";              
    printChar(numDots, '.');  
    printChar(numStars, '*'); 
    cout << "|";              
    printChar(numStars, '*'); 
    printChar(numDots, '.');  
    cout << "#";              
    cout << endl;
    if (k > 1) {
        PrintPattern2(k - 1, n);
        printChar(spaces, ' ');
        cout << "#";
        printChar(numDots, '.');
        printChar(numStars, '*');
        cout << "|";
        printChar(numStars, '*');
        printChar(numDots, '.');
        cout << "#";
        cout << endl;
    }
}

int main() {
    // Example 1
    cout << "Example 1: PrintPattern2(5, 5)" << endl;
    PrintPattern2(5, 5);

    cout << endl;

    // Example 2
    cout << "Example 2: PrintPattern2(6, 6)" << endl;
    PrintPattern2(6, 6);

    return 0;
}
