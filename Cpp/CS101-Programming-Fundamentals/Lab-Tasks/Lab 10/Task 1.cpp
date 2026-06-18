#include <iostream>
#include <fstream>   		// using library for file input and output

using namespace std;

int main() {
    
	cout << "Writing to file..." << endl; 
    ofstream myFile_out("example.txt");		// creating output file stream
    if (!myFile_out) {
        cout << "Error: Unable to open file." << endl; // error handling for if file is not oppened 
    } else {
        myFile_out << "Hello, World!" << endl;			// write text into file
        myFile_out << "This is a file handling example." << endl;
        myFile_out.close();					// close to save changes
        cout << "File written successfully." << endl;
    }
    cout << endl; 
    
	
	cout << "Reading from file..." << endl;
    ifstream myFile_in("example.txt");		// creating an input file stream
    string s; 
    if (!myFile_in) {
        cout << "Error: Unable to open file." << endl;
        
    } else {
        while (getline(myFile_in, s)) {		// reading line using loop 
            cout << s << endl;
    }
        myFile_in.close();					// closing file after reading 
}

    return 0;
}
