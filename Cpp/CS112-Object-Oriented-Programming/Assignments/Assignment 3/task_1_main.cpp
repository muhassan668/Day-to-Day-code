#include <iostream>
#include "array.h" // Make sure this matches your header file name!

using namespace std;

int main() {
    cout << "--- The Smart Array Vault Tests ---\n\n";

    // 1. Testing Constructors & I/O Operator (<<)
    cout << "[1] Constructors & Output:\n";
    int raw1[] = {10, 20, 30, 40, 50};
    int raw2[] = {5, 5, 5, 5, 5};
    
    Array A(raw1, 5);         // Pointer constructor
    Array B(raw2, 5);         // Pointer constructor
    Array C(A);               // Copy constructor
    Array emptyArr;           // Default constructor

    cout << "Array A: " << A << "\n";
    cout << "Array B: " << B << "\n";
    cout << "Array C (Copy of A): " << C << "\n\n";

    // 2. Testing Index Operator [] and Assignment =
    cout << "[2] Index Access & Deep Copy Assignment:\n";
    cout << "A[2] is: " << A[2] << "\n";
    
    Array D;
    D = B; // Testing operator=
    cout << "Array D (Assigned from B): " << D << "\n\n";

    // 3. Testing Math Engine (+, -, +=, -=)
    cout << "[3] Math Engine:\n";
    Array sum = A + B;
    Array diff = A - B;
    
    cout << "A + B = " << sum << "\n";
    cout << "A - B = " << diff << "\n";

    C += B;
    cout << "C += B -> " << C << "\n";
    
    C -= B;
    cout << "C -= B -> " << C << "\n\n";

    // 4. Testing Modifiers (++, --)
    cout << "[4] Increment & Decrement:\n";
    Array preInc = ++A;
    cout << "++A (Pre-increment): " << preInc << " | A is now: " << A << "\n";
    
    Array postInc = B++;
    cout << "B++ (Post-increment): " << postInc << " | B is now: " << B << "\n";

    Array postDec = D--; 
    cout << "D-- (Post-decrement): " << postDec << "\n\n";

    // 5. Testing Inspectors (==, !)
    cout << "[5] Inspectors:\n";
    cout << "Is A == B? " << (A == B ? "Yes" : "No") << "\n";
    cout << "Is emptyArr empty (!)? " << (!emptyArr ? "Yes" : "No") << "\n\n";

    // 6. Testing The Eraser Operator ()
    cout << "[6] The Eraser (Remove index 2):\n";
    cout << "Before Eraser: " << A << "\n";
    int eraseSuccess = A(2, 0); // Erasing index 2. Second parameter is ignored in our logic but required by prototype.
    cout << "After Eraser (Status " << eraseSuccess << "): " << A << "\n\n";

    // 7. Testing Input Operator (>>)
    // Note: I put this at the very end so it doesn't interrupt the automated output tests.
    cout << "[7] Scanner Input:\n";
    Array E(3); // Make a blank array of size 3
    cout << "Please enter 3 integers separated by spaces: ";
    cin >> E;
    cout << "You entered: " << E << "\n\n";

    cout << "--- All tests completed successfully! ---\n";
    
    // Destructors (~Array) will automatically fire here and clean up all the memory!
    return 0;
}
