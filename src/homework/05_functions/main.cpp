#include "func.h"
#include<iostream>

using std::string;
using std::cout;
using std::cin;

int main() 
{
	auto choice = 0;	
	string dna;
	string option;

	do
	{
		cout<<"1-Get GC Content"<<"\n";
		cout<<"2-Get DNA Complement"<<"\n";
		cout<<"3-Exit"<<"\n";
		cout<<"Please enter an option: ";
		cin>>choice;
		cout<<"\n";
		if(choice == 1)
		{
			
			cout<<"Enter a DNA string: ";
			cin>>dna;
			if(valid_input(dna))
			{
				cout<<"The GC content is "<<get_gc_content(dna)*100<<"%"<<"\n\n";
			}
			else
			{
				cout<<"Invalid option."<<"\n\n";
			}
		}
		else if(choice == 2)
		{
			cout<<"Enter a DNA string: ";
			cin>>dna;
			if(valid_input(dna))
			{
				cout<<"The dna compliment is "<<get_dna_compliment(dna)<<"\n\n";
			}
			else
			{
				cout<<"Invalid option."<<"\n\n";
			}
			cout<<"\n";
			
		}
		else if(choice == 3)
		{
			cout<<"are you sure you want to exit?"<<"\n";
			cout<<"Enter y or n: ";
			cin>>option;
			if(option == "y"||option == "Y")
			{
				
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
	} while (option != "y" && option != "Y");
	
	
	return 0;
}