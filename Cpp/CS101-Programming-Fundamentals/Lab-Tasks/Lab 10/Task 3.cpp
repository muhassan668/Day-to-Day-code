#include <iostream>
#include <fstream>			// using library for file input and output
#include <string>

using namespace std;

int main(){
    
	ifstream myfile("data.txt");		// opens the file for reading only
	   
  	if (!myfile){
	  	cout<<"Error : Unable to open file."<<endl;
	  	return 0;
	  }
  	
  	string find;
  	string replace; 
  	string x;

	cout<<"Enter the word to find : ";	// input from user
	cin>>find;
	cout<<"Enter the word to replace : ";	// input from user
	cin>>replace;
	cout<<endl;
	
	string updated_line=" ";
	bool found = true;
	while(myfile>>x){					// loop reads file one word at a time 
		cout<<x<<" ";
		if(x==find){					// loop checks if the word matches the required word
			x = replace; 				// if it matches it replaces word 
			found=false;
		}
		updated_line = updated_line + x + " ";		// reconstructs the file 
	}
	cout<<endl;
	
	if(found){
		cout<<"Word does not exist in line";
	}else{
		myfile.close();							//closing reading
		ofstream myfile_2;						// creating a stream to write 
		myfile_2.open("data.txt", ios::app);	// it copies the file and changes it but not the original 
		myfile_2<<updated_line;
		cout<<updated_line;
		myfile_2.close();						// closing the file at the end
	}
	
 
    return 0;
}
