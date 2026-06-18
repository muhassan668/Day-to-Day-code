
#include <iostream>
#include <iomanip>

using namespace std;

// Changed MAX to DIM for clarity
const int DIM = 3; 

// Function to show the size options
void showSizeOptions(){
    cout<<"Matrix sizes : "<<endl;
    cout<<"1- (2x2)"<<endl;
    cout<<"2- (3x3)"<<endl;
    cout<<"Enter the option you want : ";
}

// Function to display the main menu (Added Option 7)
void showMenu(){
    cout<<"1- Identify the type of matrix"<<endl;
    cout<<"2- Identify the order of the matrix"<<endl;
    cout<<"3- Find the transpose of the matrix"<<endl;
    cout<<"4- Find the adjoint of the matrix"<<endl;
    cout<<"5- Find the inverse of the matrix"<<endl;
    cout<<"6- Multiply two matrices"<<endl;
    cout<<"7- Exit program"<<endl;
}

// Display function for integer matrices
void displayMatrix(const int arr[][DIM], int r, int c){
    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            cout<<setw(8)<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
}

// Display function for floating point matrices (Inverse)
void displayDoubleMatrix(const double arr[][DIM], int r, int c){
    cout<<fixed<<setprecision(3);
    for(int x=0; x<r; x++){
        for(int y=0; y<c; y++){
            cout<<setw(10)<<arr[x][y]<<" ";
        }
        cout<<endl;
    }
}

// Gets input from user to fill the matrix
void fillMatrix(int arr[][DIM], int r, int c, char label = 'A') {
    cout<<endl<<"Enter elements of matrix "<<label<<" ("<<r<<"x"<<c<<") : "<<endl;
    // Nested loop for input
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++) {
            cout<<label<<"["<<i<<"]["<<j<<"] = ";
            cin>>arr[i][j];
        }
    }
    cout<<endl<<"Matrix "<<label<<" is : "<<endl;
    displayMatrix(arr, r, c);
}

// Simply prints dimensions
void printOrder(int r, int c){
    cout<<"Order of the matrix is: "<<r<<" x "<<c<<endl;
}

// Logic to identify matrix properties
void identifyMatrixType(int arr[][DIM], int r, int c){
    bool square = (r == c);
    bool allZero = true;
    bool offDiagonalZero = true;
    bool diagElementsEqual = true;
    bool diagElementsOne = true;

    int firstDiag = arr[0][0];

    // Analyze elements
    for(int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            if (arr[i][j] != 0) allZero = false;
            
            if (i != j && arr[i][j] != 0) offDiagonalZero = false;
            
            if (i == j){
                if(arr[i][j] != firstDiag) diagElementsEqual = false;
                if(arr[i][j] != 1) diagElementsOne = false;
            } 
        }
    }

    cout<<"Matrix type : ";

    if(allZero){
        cout<<"Your Matrix is Zero Matrix"<<endl;
        return;
    }

    if(!square){
        cout<<"Your Matrix is Rectangular Matrix ("<<r<<"x"<<c<< ")"<<endl;
        return;
    }

    // Check hierarchy: Identity -> Scalar -> Diagonal -> Square
    if(offDiagonalZero && diagElementsOne){
        cout<<"Your Matrix is Identity Matrix"<<endl;
    } 
    else if(offDiagonalZero && diagElementsEqual){
        cout << "Your Matrix is Scalar Matrix"<<endl;
    }
    else if(offDiagonalZero){
        cout<<"Your Matrix is Diagonal Matrix"<<endl;
    } 
    else{
        cout<<"Your MAtrix is Square Matrix"<<endl;
    }
}

// Transpose logic: swap rows and cols
void computeTranspose(int src[][DIM], int r, int c, int dest[][DIM]) {
    for (int i=0; i<r; i++) {
        for(int j=0; j<c; j++){
            dest[j][i] = src[i][j];
        }
    }
}

// Helper to get submatrix for cofactor calculation
void createSubMatrix(int src[][DIM], int temp[][DIM], int skipRow, int skipCol, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // Copy if not in the skipped row/col
            if (row != skipRow && col != skipCol) {
                temp[i][j++] = src[row][col];
                
                if (j == n - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// Recursive function to find determinant
int calcDet(int mat[][DIM], int n){
    if (n == 1) return mat[0][0];

    int temp[DIM][DIM];
    int multiplier = 1; // Used for sign flipping
    int result = 0;

    for (int f = 0; f < n; f++) {
        createSubMatrix(mat, temp, 0, f, n);
        result += multiplier * mat[0][f] * calcDet(temp, n - 1);
        multiplier = -multiplier;
    }
    return result;
}

// Calculates Adjoint matrix
void computeAdjoint(int mat[][DIM], int n, int adj[][DIM]) {
    if (n == 1) {
        adj[0][0] = 1;
        return;
    }

    int sign;
    int temp[DIM][DIM];

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            createSubMatrix(mat, temp, i, j, n);
            // Alternate signs based on position
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            // Transpose happens here: adj[j][i]
            adj[j][i] = sign * calcDet(temp, n - 1);
        }
    }
}

// Calculates Inverse using Adjoint and Determinant
void computeInverse(int mat[][DIM], int n, double inv[][DIM]) {
    int d = calcDet(mat, n);
    if (d == 0) {
        cout << "Determinant is 0, inverse does NOT exist."<<endl;
        return;
    }

    int adjoint[DIM][DIM];
    computeAdjoint(mat, n, adjoint);

    cout<<"Determinant = "<<d<<endl;
    cout << "Inverse of matrix A is : "<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            inv[i][j] = adjoint[i][j] / static_cast<double>(d);
        }
    }

    displayDoubleMatrix(inv, n, n);
}

// Multiplication logic
void productMatrices(int m1[][DIM], int r1, int c1, int m2[][DIM], int r2, int c2, int res[][DIM]) {
    if (c1 != r2) {
        cout << "Matrix multiplication rule not satisfied."<<endl;
        return;
    }

    // Initialize result matrix and calculate product
    for(int i=0; i<r1; i++){
        for (int j=0; j<c2; j++){
            res[i][j] = 0;
            for(int k=0; k<c1; k++){
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}

int main() {
    int mainMat[DIM][DIM];
    int r = 0, c = 0; // dimensions

    bool keepRunning = true;
    bool matrixNeeded = true;

    cout << " Matrix Solver (2x2 and 3x3) "<<endl<<endl;

    while (keepRunning) {

        if (matrixNeeded) {
            int opt;
            // Validate size input
            do {
                showSizeOptions();
                cin >> opt;
            } while (opt < 1 || opt > 2);

            if (opt == 1) {
                r = c = 2;
            } else {
                r = c = 3;
            }

            fillMatrix(mainMat, r, c, 'A');
            matrixNeeded = false;
        }

        int selection;
        // Validate menu selection (Updated to accept 7)
        do {
            showMenu();
            cout<<"Please select one option (1-7): ";
            cin>>selection;
            if(selection < 1 || selection > 7){
                cout<<"Invalid input! Please try again.\n";
            }
        } while(selection < 1 || selection > 7);

        cout<<endl;

        switch(selection){
            case 1:
                identifyMatrixType(mainMat, r, c);
                break;
            
            case 2:
                printOrder(r, c);
                break;
            
            case 3: {
                int trans[DIM][DIM];
                computeTranspose(mainMat, r, c, trans);
                cout<<"Transpose of matrix A : "<<endl;
                displayMatrix(trans, c, r);
                break;
            }
            case 4: {
                if(r != c){
                    cout<<"Adjoint is defined only for square matrices."<<endl;
                }
                else{
                    int adjMat[DIM][DIM];
                    computeAdjoint(mainMat, r, adjMat);
                    cout<<"Adjoint of matrix A : "<<endl;
                    displayMatrix(adjMat, r, c);
                }
                break;
            }
            case 5: {
                if(r != c){
                    cout<<"Inverse is defined only for square matrices."<<endl;
                } 
                else{
                    double invMat[DIM][DIM];
                    computeInverse(mainMat, r, invMat);
                }
                break;
            }
            case 6: { 
                int rB, cB;
                int matB[DIM][DIM], resMat[DIM][DIM];
                int optB;

                cout<<"Second matrix B : "<<endl;
                do {
                    cout<<"Select order of B : "<<endl;
                    cout<<"1- 2x2 "<<endl;
                    cout<<"2- 3x3 "<<endl;
                    cout<<"Enter your choice : ";
                    cin>>optB;
                } while(optB < 1 || optB > 2);

                if(optB == 1) {
                    rB = cB = 2;
                } else { 
                    rB = cB = 3;
                }

                if(c != rB){
                    cout<<"Cannot multiply: columns of A must equal rows of B."<<endl;
                } 
                else{
                    fillMatrix(matB, rB, cB, 'B');
                    productMatrices(mainMat, r, c, matB, rB, cB, resMat);
                    cout<<"Result of A x B : "<<endl;
                    displayMatrix(resMat, r, cB);
                }
                break;
            }
            case 7: {
                keepRunning = false;
                break;
            }
            default:
                break;
        }

        // Only show the next move options if the user didn't choose exit
        if (keepRunning) {
            int userNextMove;
            cout<<"What do you want to do now?"<<endl;
            cout<<"1- Perform another operation on the SAME matrix"<<endl;
            cout<<"2- Create a NEW matrix"<<endl;
            // Exit option removed from here
            cout<<"Enter choice : ";
            cin>>userNextMove;

            if(userNextMove == 1) {
                matrixNeeded = false;
            }
            else {
                // Assuming any other key resets the matrix for simplicity
                // or specifically check for 2
                matrixNeeded = true;
            }
            cout<<endl;
        }
    }

    cout<<"Thank you for using Matrix Solver!"<<endl;
    return 0;
}
