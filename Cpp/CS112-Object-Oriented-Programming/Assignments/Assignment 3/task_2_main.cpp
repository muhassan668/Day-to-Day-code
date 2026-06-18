#include <iostream>
#include "BigInt.h"

using namespace std;

int main() {
    BigInt a("999999999999999999999999999999");
    BigInt b(1);
    
    BigInt c = a + b;
    cout << c << endl;
    
    BigInt d = a * BigInt(5);
    cout << d << endl;
    
    BigInt e = a - b;
    cout << e << endl;
    
    c -= b;
    cout << c << endl;
    
    c++;
    cout << c << endl;
    
    --c;
    cout << c << endl;
    
    if (a == "999999999999999999999999999999") {
        cout << 1 << endl;
    }
    
    if (b < a) {
        cout << 1 << endl;
    }
    
    int len = (int)a;
    cout << len << endl;
    
    string str = (string)b;
    cout << str << endl;

    return 0;
}
