#include <iostream>
using namespace std;

int main() {
    
for (int i = 0; i < 3 ; i++) {
    	
    for(int A = 25 ; A >= 0 ; A--){	
        cout << " ";
	}
       									 // Loop through each column
    for (int j = 0; j < 6 ; j++) {
          								  // Print * at borders, else print space
        if (i == 0  || j == 0 || j == 3 )
            cout << "*";
        else
            cout << "  ";
        }    
        cout << endl;
    }
    for (int i = 0; i < 3 ; i++) {
    	
    	 for(int B = 21 ; B >= 1 ; B--){	
        cout << " ";
	    }
        									// Left rectangle
        for (int j = 0; j < 6 ; j++) {
            if (i == 0 || j == 0 )
                cout << "*";
            else
                cout << " ";
        }
        									// space between rectangle
        for (int s = 0; s < 4 ; s++)
            cout << " ";
        									// right rectangle
        cout << "*";
        cout << endl;
    }
 for (int i = 0; i < 3 ; i++) {
    	
    	 for(int B = 16 ; B >= 1 ; B--){	
        cout << " ";
	    }
     									   // Left rectangle
        for (int j = 0; j < 6 ; j++) {
            if (i == 0 || j == 0 )
                cout << "*";
            else
                cout << " ";
        }
        									// space between rectangle
        for (int s = 0; s < 9 ; s++)
            cout << " ";
        									// right rectangle
        cout << "*";
        cout << endl;
    }
   for (int i = 0; i < 3 ; i++) {
    	
    	 for(int B = 11 ; B >= 1 ; B--){	
        cout << " ";
	    }
        									// Left rectangle
        for (int j = 0; j < 6 ; j++) {
            if (i == 0 || j == 0 )
                cout << "*";
            else
                cout << " ";
        }
        									// space between rectangle
        for (int s = 0; s < 14 ; s++)
            cout << " ";
        									// right rectangle
        cout << "*";
        cout << endl;
    }
   for (int i = 0; i < 3 ; i++) {
    	
    	 for(int B = 6 ; B >= 1 ; B--){	
        cout << " ";
	    }
        									// Left rectangle
        for (int j = 0; j < 6 ; j++) {
            if (i == 0 || j == 0 )
                cout << "*";
            else
                cout << " ";
        }
        									// space between rectangle
        for (int s = 0; s < 19 ; s++)
            cout << " ";
        									// right rectangle
        cout << "*";
        cout << endl;
    }

 for(int k=1;k<=32;k++)
 { 											//creating the bottom horizontal line
			cout<<"*"; 
		}         
}
