
#include <iostream>
using namespace std;

void printStars(int k);
void printSpaces(int k);
void printRow(int n, int i);
void printHollowDiamond(int n, int i);

int main() {
    int n;
    cout << "Enter the size of the Diamond: ";
    cin >> n;
    printHollowDiamond(n, 1);
    return 0;
}

void printStars(int k) {
    if (k <= 0) return;
    cout << "*";
    printStars(k - 1);
}

void printSpaces(int k) {
    if (k <= 0) return;
    cout << " ";
    printSpaces(k - 1);
}

void printRow(int n, int i) {
    int stars = n - i + 1;
    int spaces = 2 * (i - 1);
    printStars(stars);
    printSpaces(spaces);
    printStars(stars);
    cout << endl;
}

void printHollowDiamond(int n, int i) {
    printRow(n, i);
    if (i < n) {
        printHollowDiamond(n, i + 1);
        printRow(n, i);
    }
}
