#include <iostream>
using namespace std;

int sumDivisors(int number, int currentDivisor);
bool isperfectNumber(int n);

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isperfectNumber(n)) {
        cout << n << " is a perfect number" << endl;
    } else {
        cout << n << " is not a perfect number" << endl;
    }

    return 0;
}

int sumDivisors(int number, int currentDivisor) {
    if (currentDivisor > number / 2) {
        return 0;
    }
    if (number % currentDivisor == 0) {
        return currentDivisor + sumDivisors(number, currentDivisor + 1);
    }
    return sumDivisors(number, currentDivisor + 1);
}
bool isperfectNumber(int n) {
    if (n <= 1) return false;
    return sumDivisors(n, 1) == n;
}

