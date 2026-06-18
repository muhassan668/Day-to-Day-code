#include <iostream>
using namespace std;

void printSpaces(int n);
void PrintPattern1(int start, int end);

int main() {
	int start, end;
	cout<<"What should be the start of the Pattern : ";
	cin>>start;
	cout<<"What should be the end of the Pattern : ";
	cin>>end;
    PrintPattern1(start, end);
    return 0;
}

void printSpaces(int n) {
    if (n <= 0) return;
    cout << " ";
    printSpaces(n - 1);
}

void PrintPattern1(int start, int end) {
    if (start >= end) return;

    int spaces = end - start;

    if (start + 1 == end) {
        printSpaces(spaces);
        cout << "*" << endl;
        return;
    }

    printSpaces(spaces);
    cout << "*" << endl;

    PrintPattern1(start + 1, end - 1);

    printSpaces(spaces);
    cout << "*" << endl;
}
