    // TASK 3
    
#include <iostream>
using namespace std;
int main()
{
	int number1;
	cout<<"Enter number1\n";
	cin>>number1;
	int number2;
	cout<<"Enter number2\n";
	cin>>number2;
	
	cout<<"Select one of the operations\n";
	cout<<"1.Addition\n"<<"2.Subtraction\n"<<"3.Multiplication\n"<<"4.Division\n"<<"5.Modulus\n";
	int operations;
    cin>> operations;

switch (operations)
{
    case 1:
	cout<<"Answer = "<<number1+number2;
	break;
    case 2:
    cout<<"Answer = "<<number1-number2;
    break;
    case 3:
    cout<<"Answer = "<<number1*number2;
    break;
    case 4:
    if (number2 != 0)
    cout<<"Answer = "<<number1/number2;
    else
    cout<<"Error! Division by zero.";
    break;
    case 5:
    if(number2 != 0)
    cout<<"Answer = "<<number1%number2;
    else
    cout<<"Error! Modulus by zero.";
    break;
    default:
    cout<<"Invalid option!";
		
	}
	
	return 0;
}









