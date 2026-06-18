#include <iostream>
#include <bitset>

using namespace std;

int main(){

    // Example of bit manipulation using bitset
    int num = 243;
    bitset<8> b(num);
    cout << "Original number: " << num << endl;
    cout << "Binary representation: " << b << endl;
    b.set(2); // Set the 3rd bit (0-indexed)
    cout << "After setting the 3rd bit: " << b << endl;
    b.reset(2); // Reset the 3rd bit
    cout << "After resetting the 3rd bit: " << b << endl;
    b.flip(2); // Flip the 3rd bit
    cout << "After flipping the 3rd bit: " << b << endl;
    b.flip(); // Flip all bits
    cout << "After flipping all bits: " << b << endl;
    b.flip(0);
    cout << "After flipping the 1st bit: " << b << endl;
    b.to_ulong();
    cout << "Decimal representation after flipping the 1st bit: " << b.to_ulong() << endl;



    return 0;
}
