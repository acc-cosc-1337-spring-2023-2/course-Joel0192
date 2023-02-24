//write include statements
#include "dna.h"
#include <iostream>
//write using statements
using std::cout;
using std::cin;
using std::string;

int main() 
{
	auto choice = 0;
	string option;
	auto integer = 0;
	auto integer2 = 0;
	auto result = 0;
	do
	{
		cout<<"1-Factorial"<<"\n";
		cout<<"2-Greatest Common Divisor"<<"\n";
		cout<<"3-Exit"<<"\n";
		cout<<"Please enter an option: ";
		cin>>choice;
		cout<<"\n";
		if(choice == 1)
		{
			cout<<"Enter a positive integer: ";
			cin>>integer;
			result = factorial(integer);
			cout<<"The Factorial of the number is: "<<result<<"\n\n";
		}
		else if(choice == 2)
		{
			cout<<"Enter two positive integers"<<"\n";
			cout<<"#1: ";
			cin>>integer;
			cout<<"#2: ";
			cin>>integer2;
			cout<<"\n";
			result = gcd(integer, integer2);
			cout<<"The Greatest common divisor of these numbers is: "<<result<<"\n\n";
		}
		else if(choice == 3)
		{
			cout<<"are you sure you want to exit?"<<"\n";
			cout<<"Enter y or n: ";
			cin>>option;
			if(option == "y"||option == "Y")
			{
				choice += -4;
				cout<<"Thank You!"<<"\n";
			}
			else
			{
				cout<<"\n";
			}
			
		
		}
		else
		{
			cout<<"Invalid option, Try again"<<"\n\n";
		}
	} while (choice != -1);
	
	return 0;
}