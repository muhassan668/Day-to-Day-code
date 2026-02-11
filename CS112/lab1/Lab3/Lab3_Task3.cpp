#include <iostream>
using namespace std;

int main(){

    int max = 3;
    float std_salary[3];                // making static array for standard salary
    float* curr_salary = std_salary;    // pointer to track current salaries (starts at stack)
    
    char choice;
    float avg_salary=0;

    cout<<"Enter the Salary of the Initial 3 Employees."<<endl;

    for(int i=0; i<max; i++){
        cout<<"Salary of Employee "<<i+1<<" : ";        // taking input of the standard salary 
        cin>>std_salary[i];
    }

    do{
        cout<<"Enter more Employees.(y/n)"<<endl;
        cin>>choice;

        if(choice == 'y' || choice == 'Y'){
            max = max + 1;
            float* temp = new float[max];               // making dynamic memory to add more salaries

            for(int i=0; i<max-1; i++){
                temp[i]= curr_salary[i];                // copying the original salaries to the dynamic memory 
            }
            
            cout<<"Enter the Salary of the new Employee : ";
            cin>>temp[max-1];                           // taking the input of the new salary 

            if(curr_salary != std_salary){              // deleting old heap memory if it exists
                delete[] curr_salary;
            }
            curr_salary = temp;                         // updating pointer to new memory

            avg_salary = 0;
            for(int i=0; i<max; i++){
                avg_salary = avg_salary + curr_salary[i];
            }
            avg_salary = avg_salary/max;                // calculating the average salary 
            
        }else break;
        
    }while(choice == 'y' || choice == 'Y');

    cout<<"Average Salary of All Employees : "<<avg_salary<<endl;   // printing averge salary 

    // cleanup memory at the end
    if(curr_salary != std_salary){
        delete[] curr_salary;
    }

    return 0;
}