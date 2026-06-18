#include <iostream>

using namespace std;

int main(){
	// For the old Allowances
	cout<<"Welcome to Dream-Tech Organization!\n\n";
	cout<<"Please enter your Basic Salary!\n\n";
	
	int basicSalary, houseAllowance, transportAllowance, medicalAllowance , totalSalary;
	cin>> basicSalary;
	
	cout<<"The following are your Allowances : \n\n";
	
	houseAllowance = (basicSalary)*0.3;
	cout<<"1.House Allowance : "<<houseAllowance<<endl<<endl;
	
	transportAllowance = (basicSalary)*0.1;
	cout<<"2.Transport Allowance : "<<transportAllowance<<endl<<endl;
	
	medicalAllowance = (basicSalary)*0.25;
	cout<<"3.Medical Allowance : "<<medicalAllowance<<endl<<endl;
	
	totalSalary = basicSalary+houseAllowance+transportAllowance+medicalAllowance;
	cout<<"   Your Total/Gross Salary is : "<<totalSalary<<endl<<endl;
	
	// For the new Allowances 
	
	cout<<"The following are your new allowances : \n\n";
	
	houseAllowance = (basicSalary)*0.4;
	cout<<"1.New House Allowance : "<<houseAllowance<<endl<<endl;
	
	transportAllowance = (basicSalary)*0.15;
	cout<<"2.New Transport Allowance : "<<transportAllowance<<endl<<endl;
	
	medicalAllowance = (basicSalary)*0.35;
	cout<<"3.New Medical Allowance : "<<medicalAllowance<<endl<<endl;
	
	int totalSalary2;
	totalSalary2 = basicSalary+houseAllowance+transportAllowance+medicalAllowance;
	cout<<"   Your New Total/Gross Salary is : "<<totalSalary2<<endl<<endl;
	//totalSalary2 is the new gross salary
	
	int difference;
	difference = totalSalary2 - totalSalary;
	cout<<"The difference between the Old Gross salary and the New Gross salary is : "<<difference;
	

	return 0;
}
