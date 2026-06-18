#include <iostream>
using namespace std;

void checkLevel() {					//Function to check the level of water tank 
 	if (waterLevel> 40.0){			//Checking if water level is below 40 or not 
	    cout<<"Water tank is stable." <<endl;
} 
    if (waterLevel < 40.0) {
        cout<<"Water level low! Filling tank..." <<endl;
    }
}

void fillTank() {					//Function that will add water if the level is below 40 
    cout<<"Adding water to the tank..."<<endl;
    waterLevel += 10.0;
}

void startSystem(double initialLevel) {
    waterLevel = initialLevel; 
    
    cout << "\n--- Initial Water Level: "<< waterLevel << "% ---" << endl;
    cout << "Starting Water Tank Auto Control System..." << endl;
}

int main() {
    double inputLevel;
    do{
    cout << "Enter initial water level (0-100%): ";
    cin >> inputLevel;
    if (inputLevel < 0 || inputLevel > 100) {	  				//Error handling 
    	
        cout << "Error: Level must be between 0 and 100." << endl;
    }
}while(inputLevel<0 || inputLevel > 100);
	
    startSystem(inputLevel);
    
    cout << "\n--- Final Water Level: "<< waterLevel << "% ---" << endl;

    return 0;
}
