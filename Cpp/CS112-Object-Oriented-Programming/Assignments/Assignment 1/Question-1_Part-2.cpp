#include <iostream>

using namespace std;

bool FindSubString(char* Str, char* substr, int & start, int & end);

int main() {
    char str[] = "abcdab";
    char input[50];
    int start = -1, end = -1;

    cout << "Current String: " << str << endl;
    cout << "Enter substring to find: ";
    cin.getline(input, 50);

    if (FindSubString(str, input, start, end)) {
        cout << "Return true ,start=" << start <<", end=" << end << endl;
    } else {
        cout << "Return false, start=-1, end=-1" << endl;
    }

    return 0;
}

bool FindSubString(char* Str, char* substr, int & start, int & end) {
    int N = 0;
    while (Str[N] != '\0') {
        N++;
    }

    int M = 0;
    while (substr[M] != '\0') {
        M++;
    }
    if (M == 0) return false;

    for (int i = 0; i < N; i++) {
        int j = 0;
        
        while (j < M) {
            int circularIndex = (i + j) % N;
            
            if (Str[circularIndex] != substr[j]) {
                break;
            }
            j++;
        }

        if (j == M) {
            start = i;
            end = (i + M - 1) % N;
            return true;
        }
    }

    return false;
}
