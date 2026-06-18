#include <iostream>
#include <string>						// library to include words
using namespace std;

int main(){
	int halls=2 , days=3, showtimes=1;	//declairing and initializing the required variables
	
	string schedule[halls][days][showtimes];	// declairing array named scheduled
	for(int i=0; i<halls; i++){					//For loop 
		for(int j=0; j<days; j++){
			for(int k=0; k<showtimes; k++){
				
				schedule [i][j][k]= "UNSET";	//declairing to unset as there is no input
			}
		}
	}
	cout<<"Enter movie names for 2 halls for a 3 day schedule. \n";
	cout<<endl;
	
	for(int i=0; i<halls; i++){						//For loops to input the movie names according to the hall and day
		for(int j=0; j<days; j++){
			for ( int k=0; k<showtimes; k++){
				cout<<"Hall "<<i<<", Day "<<j<<", Showtime 0: "<<"Movies ";
				getline(cin, schedule [i][j][k]);	//getline is used to get the entire name of the movie even if it is two or more words 
			}
		}
	}
	cout<<endl;
	
	cout<<"Final 3-Day movie schedule : "<<endl;
	cout<<endl;
	
	for(int i=0; i<halls; i++){						//For loops to show the apropriate output 
			cout<<"Hall "<<i<<":  "<<endl;
		for(int j=0; j<days; j++){
			for (int k=0; k<showtimes; k++){
				cout<<"  Day "<<j<<": "<<"Movie "<<schedule[i][j][k]<<endl;
			}
		}
		cout<<endl;
	}
	
	
	
	return 0;
}
