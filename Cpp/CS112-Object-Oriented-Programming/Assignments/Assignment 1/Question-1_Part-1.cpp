#include <iostream>
using namespace std;

char* removeSentence(char* Para, char* input);

int main() {
    char para[100] = "I am currently studying OOP course. I hope to pass it. I might fail.";
    char input[99];
    cout << "Current Paragraph: " << para << endl;
    cout << "Enter the substring to remove: ";
    cin.getline(input, 99);

    removeSentence(para, input);
    cout << "Final Paragraph: " << para << endl;

    return 0;
}

char* removeSentence(char* Para, char* input) {
    int paraLen = 0;
    while (Para[paraLen] != '\0') {
        paraLen++;
    }
    int inputLen = 0;
    while (input[inputLen] != '\0') {
        inputLen++;
    }
    if (inputLen == 0) {
        cout << "Input is empty. The paragraph stays the same." << endl;
        return Para;
    }
    if (inputLen > paraLen) {
        cout << "Error: Input is longer than paragraph. No change to the paragraph." << endl;
        return Para;
    }
    int matchIndex = -1;

    for (int i = 0; i <= paraLen - inputLen; i++) {
        int j = 0;
        while (j < inputLen && Para[i + j] == input[j]) {
            j++;
        }
        if (j == inputLen) {
            matchIndex = i;
            break;
        }
    }
    if (matchIndex != -1) {
        int i = matchIndex;
        while (Para[i + inputLen] != '\0') {
            Para[i] = Para[i + inputLen];
            i++;
        }
        Para[i] = '\0';
    } else {
        cout << "Error: Substring not found." << endl;
    }

    return Para;
}








