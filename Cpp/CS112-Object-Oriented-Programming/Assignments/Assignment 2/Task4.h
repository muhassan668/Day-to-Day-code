#ifndef TASK4_H
#define TASK4_H

class Record {
private:
    char* fileName;
    
    // Helper function to manually compare two strings
    bool compareStrings(char* str1, char* str2);
    
public:
    Record(char* str);  // Constructor
    ~Record();          // Destructor
    
    int record_Input();      // Input records into file
    void record_Display();   // Display records
    int delete_Record();     // Delete record by name
    int record_Count();      // Count records in file
    int record_Search();     // Search record by name
    int record_Insert();     // Insert record after a name
    void record_Replace();   // Replace record by name
};

#endif