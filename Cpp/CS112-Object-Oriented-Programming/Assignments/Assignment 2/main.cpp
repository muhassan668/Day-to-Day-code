#include <iostream>
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

using namespace std;

void testTask1() {
    ZooChain myZoo;

    cout << "--- Adding Cages ---" << endl;
    // Defining strings as char arrays to pass them
    char lion[] = "Lion";
    char tiger[] = "Tiger";
    char bear[] = "Bear";
    char zebra[] = "Zebra";
    char duplicateZebra[] = "Zebra (Clone)";
    
    myZoo.add_Cage(lion, 105);
    myZoo.add_Cage(tiger, 102);
    myZoo.add_Cage(bear, 108);
    myZoo.add_Cage(zebra, 102); // Duplicate cage number for testing
    myZoo.add_Cage(duplicateZebra, 102); // Another duplicate

    myZoo.print_Chain();

    cout << "\n--- Sorting the Chain ---" << endl;
    myZoo.Sort_Chain();
    myZoo.print_Chain();

    cout << "\n--- Removing Duplicates ---" << endl;
    myZoo.remove_Duplicate();
    myZoo.print_Chain();

    cout << "\n--- Updating Name at Cage 105 ---" << endl;
    char kingLion[] = "King Lion";
    myZoo.update_name_at_cageNumber(105, kingLion);
    myZoo.print_Chain();

    cout << "\n--- Deleting Cage 108 ---" << endl;
    myZoo.delete_Chain(108);
    myZoo.print_Chain();
}

void testTask2() {
    cout << "--- Task 2 Tests ---\n\n";

    cout << "[1] Constructors & Getters:\n";
    String s1("Batman");
    String s2(" is a ");
    String s3("man");
    String emptyStr;

    cout << "s1: " << s1.getdata() << " (Length: " << s1.length() << ")\n";
    cout << "s2: " << s2.getdata() << "\n";
    cout << "emptyStr isEmpty? " << (emptyStr.isEmpty() ? "Yes" : "No") << "\n\n";

    cout << "[2] Inspectors (isEqual):\n";
    cout << "Does s1 equal 'Batman'? " << (s1.isEqual("Batman") ? "Yes" : "No") << "\n";
    cout << "Does s1 equal s3? " << (s1.isEqual(s3) ? "Yes" : "No") << "\n\n";

    cout << "[3] Search Party (index_at):\n";
    cout << "Index of 'm' in s1 ('Batman'): " << s1.index_at('m') << "\n";
    cout << "Index of 'man' in s1: " << s1.index_at(s3) << "\n";
    cout << "Index of 'Cat' in s1 (Should be -1): " << s1.index_at("Cat") << "\n\n";

    cout << "[4] Builders (append_string):\n";
    String temp1 = s1.append_string(s2);          
    String sentence = temp1.append_string("man"); 
    String plural = sentence.append_string('s');  
    
    cout << "Appended String: " << sentence.getdata() << "\n";
    cout << "Single char append: " << plural.getdata() << "\n\n";

    cout << "[5] Erasers (remove_string):\n";
    String noA = s1.remove_string('a'); 
    cout << "Remove 'a' from 'Batman': " << noA.getdata() << "\n";

    String target("man");
    String noMan = sentence.remove_string(target); 
    cout << "Remove 'man' from '" << sentence.getdata() << "': " << noMan.getdata() << "\n";

    String noIs = sentence.remove_string(" is "); 
    cout << "Remove ' is ' from '" << sentence.getdata() << "': " << noIs.getdata() << "\n\n";

    cout << "--- All tests completed successfully! ---\n";
}

void testTask3() {
    cout << "\n=============================================\n";
    cout << "TESTING TASK 3: BinaryStore Implementation\n";
    cout << "=============================================\n";
    
    // Create a BinaryStore
    BinaryStore store(5);
    
    cout << "\nAdding addresses and setting bytes...\n";
    
    // Add addresses and set bytes
    store.add_Address("A001");
    store.set_Byte("A001", "10101010");
    
    store.add_Address("B002");
    store.set_Byte("B002", "11001100");
    
    store.add_Address("C003");
    store.set_Byte("C003", "11110000");
    
    // Set byte for a new address
    store.set_Byte("D004", "00001111");
    
    // Display the BinaryStore
    cout << "\nBinaryStore contents:\n";
    cout << store.ToString();
    
    // Test Get function
    cout << "\nTesting Get function:\n";
    cout << "Byte at A001: " << store.Get("A001") << endl;
    cout << "Byte at B002: " << store.Get("B002") << endl;
    cout << "Byte at C003: " << store.Get("C003") << endl;
    cout << "Byte at D004: " << store.Get("D004") << endl;
    
    // Test binary operations
    cout << "\nTesting binary operations:\n";
    
    // Add (XOR)
    char* addResult = store.Add(store.Get("A001"), store.Get("B002"));
    cout << "A001 XOR B002: " << addResult << endl;
    
    // AND
    char* andResult = store.comp_AND(store.Get("A001"), store.Get("B002"));
    cout << "A001 AND B002: " << andResult << endl;
    
    // OR
    char* orResult = store.comp_OR(store.Get("A001"), store.Get("B002"));
    cout << "A001 OR B002: " << orResult << endl;
    
    // NOT
    char* notResult = store.comp_NOT(store.Get("A001"));
    cout << "NOT A001: " << notResult << endl;
    
    // EQUAL
    bool equalResult = store.comp_EQUAL(store.Get("A001"), store.Get("B002"));
    cout << "A001 EQUALS B002: " << (equalResult ? "true" : "false") << endl;
    
    // Clean up dynamically allocated memory
    delete[] addResult;
    delete[] andResult;
    delete[] orResult;
    delete[] notResult;
}

void testTask4() {
    cout << "\n=============================================\n";
    cout << "TESTING TASK 4: Record Management Implementation\n";
    cout << "=============================================\n";
    
    // Create a Record with file name
    char fileName[] = "student_records.txt";
    Record records(fileName);
    
    // Input records (comment this out to avoid interactive input during automated testing)
    cout << "\nInput a new record:\n";
    records.record_Input();
    
    // Display all records
    cout << "\nDisplaying all records:\n";
    records.record_Display();
    
    // Count records
    cout << "\nCounting records:\n";
    int count = records.record_Count();
    
    // Search for a record (comment this out to avoid interactive input during automated testing)
    cout << "\nSearching for a record:\n";
    records.record_Search();
    
    // Insert a record (comment this out to avoid interactive input during automated testing)
    cout << "\nInserting a record:\n";
    records.record_Insert();
    
    // Display all records after insertion
    cout << "\nDisplaying all records after insertion:\n";
    records.record_Display();
    
    // Replace a record (comment this out to avoid interactive input during automated testing)
    cout << "\nReplacing a record:\n";
    records.record_Replace();
    
    // Display all records after replacement
    cout << "\nDisplaying all records after replacement:\n";
    records.record_Display();
    
    // Delete a record (comment this out to avoid interactive input during automated testing)
    cout << "\nDeleting a record:\n";
    records.delete_Record();
    
    // Display all records after deletion
    cout << "\nDisplaying all records after deletion:\n";
    records.record_Display();
}

int main() {
    cout << "Object Oriented Programming and Design - Assignment #2\n";
    
    // Test Task 1
    testTask1();
    
    // Test Task 2
    testTask2();
    
    // Test Task 3
    testTask3();
    
    // Test Task 4
    // Uncomment the following line to test Task 4 (requires user input)
    // testTask4();
    
    return 0;
}
