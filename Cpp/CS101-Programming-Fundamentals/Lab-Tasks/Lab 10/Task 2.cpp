#include <iostream>
#include <fstream>			// using library for file input and output

using namespace std;
int main(){
	
	ifstream myfile("text.txt");		// creating an input stream 
	string s;
	if(!myfile){
		cout<<"Error: Unable to open file."<<endl;		// error handeling for if file is not oppened 
		return 0;
	}
		
	string words;
	int x=0;
	
	while(!myfile.eof()){		// loop continues till the end of file has been reached 
		myfile>>words;			// grabbing one word at a time 
		cout<<words<<" ";		// printing each word 
		x++;					// incrementing the counter for every word read 
	}
	cout<<endl;
	cout<<"Total words in the file = "<<x<<endl;
	
	myfile.close();				// closing the file at the end 
	
	return 0;
}
