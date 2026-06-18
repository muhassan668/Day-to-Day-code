#include <iostream>
using namespace std;

int findVowels(char* str);

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    int count = findVowels(str);
    cout << "Total number of vowels: " << count << endl;

    return 0;
}
int findVowels(char* str) {
    if (*str == '\0') {
        return 0;
    }

    char c = *str;
    if (c >= 'A' && c <= 'Z') {
        c = c + 32;
    }

    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1 + findVowels(str + 1);
    } else {
        return findVowels(str + 1);
    }
}
