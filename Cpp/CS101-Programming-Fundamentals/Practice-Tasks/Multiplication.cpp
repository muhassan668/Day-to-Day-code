#include <iostream>
using namespace std;

int main() {
    int num, range;

    cout << "Enter a positive number to print its multiplication table: ";
    cin >> num;
    cout << "Enter the range up to which you want the table: ";
    cin >> range;

    for (int i = 1; i <= range; ++i) {
        cout << num << " x " << i << " = " << num * i << endl;
    }

    return 0;
}

