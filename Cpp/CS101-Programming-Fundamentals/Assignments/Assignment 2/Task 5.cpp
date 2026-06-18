#include <iostream>
using namespace std;

int findHCF(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;  // when b becomes 0, a is the HCF
}
int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    // Input validation
    if (num1 <= 0 || num2 <= 0) {
        cout << " Please enter positive integers only!" << endl;
        return 0;
    }
    int hcf = findHCF(num1, num2);
    cout << "\nThe HCF of " << num1 << " and " << num2 << " is: " << hcf << endl;
    return 0;
}

