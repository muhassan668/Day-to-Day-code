#include <iostream>
// We are restricted to using only basic control structures and arrays.
// Therefore, we will perform all logic inside the main function
// and avoid custom functions, classes, or advanced libraries.

using namespace std;

// The program must be at least 150 lines long and use:
// 1. for loop
// 2. while loop
// 3. do-while loop
// 4. if statement
// 5. arrays

int main() {
    // --- 1. Variable and Array Declarations ---
    
    // Define the maximum fixed size for the array as a constant integer.
    const int MAX_SIZE = 10;
    
    // Declare the main array of integers. This is our primary data structure.
    int dataArray[MAX_SIZE];
    
    // Store the actual number of elements the user enters, which will be 
    // less than or equal to MAX_SIZE.
    int actualSize = 0;
    
    // Variable for user input in control flow sections.
    int inputChoice = 0;
    
    // Variables for the search functionality.
    int searchValue = 0;
    bool foundFlag = false;
    char continueSearch = 'y';
    
    // Temporary variable for swapping elements during the Bubble Sort.
    int tempSwap = 0;

    cout << "================================================================" << endl;
    cout << "        CS Project: Fundamental Array Utility (C++)             " << endl;
    cout << "================================================================" << endl;
    cout << "The program is restricted to FOR, WHILE, DO-WHILE, IF, and Arrays." << endl;
    cout << "----------------------------------------------------------------" << endl;

    // --- 2. Initial Array Data Entry (Using FOR and IF) ---
    
    cout << "\n--- Section A: Array Data Input ---" << endl;
    
    // Use an outer DO-WHILE loop to prompt the user to continue entry until
    // a valid choice is made or the array is full.
    do {
        cout << "Enter the number of elements (1 to " << MAX_SIZE << "): ";
        if (!(cin >> actualSize) || actualSize < 1 || actualSize > MAX_SIZE) {
            cout << "Invalid input. Please enter a number between 1 and " << MAX_SIZE << "." << endl;
            cin.clear(); // Clear the error flags
            // Flush the input buffer to prevent infinite loops with bad input.
            // Note: This simple loop is used instead of cin.ignore() due to strict constraints.
            while (cin.get() != '\n') {}
            actualSize = 0; // Reset size to force re-entry
            continue;
        } else {
            // Exit the loop if input is valid.
            break; 
        }
    } while (true); // Loop runs until broken by valid input

    cout << "Please enter " << actualSize << " integer values:" << endl;

    // Use a FOR loop to iterate exactly 'actualSize' times and fill the array.
    for (int i = 0; i < actualSize; i++) {
        cout << "Enter element at index [" << i << "]: ";
        if (!(cin >> dataArray[i])) {
            cout << "Input error detected. Setting value to 0 and continuing." << endl;
            dataArray[i] = 0;
            cin.clear();
            while (cin.get() != '\n') {}
        }
    }
    
    // --- 3. Display Unsorted Array (Using WHILE) ---

    cout << "\n--- Section B: Displaying Unsorted Array ---" << endl;
    
    // Initialize a counter for the WHILE loop.
    int i = 0;
    
    // Use a WHILE loop to iterate through the array and print each element.
    cout << "Current Array: [";
    while (i < actualSize) {
        cout << dataArray[i];
        
        // Use IF statement to determine if a comma separator is needed.
        if (i < actualSize - 1) {
            cout << ", ";
        }
        i++;
    }
    cout << "]" << endl;

    // --- 4. Sorting the Array (Using Nested FOR loops and IF) ---

    cout << "\n--- Section C: Sorting (Bubble Sort Algorithm) ---" << endl;
    cout << "Applying Bubble Sort using nested FOR loops..." << endl;

    // Outer FOR loop: Controls the number of passes.
    for (int pass = 0; pass < actualSize - 1; pass++) {
        
        // Inner FOR loop: Compares adjacent elements and performs swaps.
        // The '- pass' optimization reduces unnecessary comparisons in later passes.
        for (int j = 0; j < actualSize - 1 - pass; j++) {
            
            // Use an IF statement to check if a swap is necessary.
            // If the current element is greater than the next element, swap them.
            if (dataArray[j] > dataArray[j + 1]) {
                
                // Manual swap logic (avoiding the std::swap function due to constraints).
                tempSwap = dataArray[j];
                dataArray[j] = dataArray[j + 1];
                dataArray[j + 1] = tempSwap;
            }
        }
    }

    cout << "Sorting complete. The array is now sorted." << endl;
    
    // Display the Sorted Array (using a simple FOR loop for brevity here).
    cout << "Sorted Array: [";
    for (int k = 0; k < actualSize; k++) {
        cout << dataArray[k];
        if (k < actualSize - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    // --- 5. Searching Utility (Using DO-WHILE, FOR, and IF) ---
    
    cout << "\n--- Section D: Linear Search Utility ---" << endl;
    
    // Use a DO-WHILE loop to allow the user to perform multiple searches
    // without restarting the program.
    do {
        cout << "\nEnter the value to search for in the array: ";
        if (!(cin >> searchValue)) {
            cout << "Invalid input. Exiting search loop." << endl;
            break;
        }

        foundFlag = false; // Reset the flag before each search.
        int foundIndex = -1; // Stores the index where the value is found.

        // Use a FOR loop to perform a Linear Search.
        for (int m = 0; m < actualSize; m++) {
            
            // Use an IF statement to check for a match.
            if (dataArray[m] == searchValue) {
                foundFlag = true;
                foundIndex = m;
                // Note: We intentionally do not use 'break' here to satisfy the 
                // requirement to use ONLY the allowed control flow structures.
                // We let the loop finish, which is less efficient but adheres to the rule.
            }
        }

        // Use IF statements to report the search result to the user.
        if (foundFlag) {
            cout << "Result: SUCCESS! Value " << searchValue << " was found in the array";
            
            // Due to the constraint of not breaking the FOR loop, we can only report 
            // the *last* found index if duplicates exist. If there are no duplicates,
            // this is correct.
            if (foundIndex != -1) {
                 cout << " (e.g., at index [" << foundIndex << "]).";
            }
            cout << endl;
        } else {
            cout << "Result: FAILURE. Value " << searchValue << " was NOT found in the array." << endl;
        }

        // Prompt the user to continue the search utility.
        cout << "Do you want to search for another value? (y/n): ";
        cin >> continueSearch;
        
    // Loop condition: continue as long as the user enters 'y' or 'Y'.
    } while (continueSearch == 'y' || continueSearch == 'Y');

    // --- 6. Program Conclusion ---

    cout << "\n================================================================" << endl;
    cout << "Project execution finished. Thank you for using the utility." << endl;
    cout << "================================================================" << endl;

    return 0;
}
