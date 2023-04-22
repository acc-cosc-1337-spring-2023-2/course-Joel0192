//write include statements
#include <iostream>
#include "decisions.h"
using std::cout;
using std::cin;
using std::string;
int main() 
{
	auto grade = 0;
	auto option = 0;
	string result;
	cout<<"MAIN MENU"<<"\n";
	cout<<"1-Letter grade using if"<<"\n";
	cout<<"2-Letter grade using switch"<<"\n";
	cout<<"3-EXIT"<<"\n";
	cin>>option;

	if(option == 1)
	{
		cout<<"Enter a number between 0 and 100: ";
		cin>>grade;
		result = get_letter_grade_using_if(grade);
		cout<<result<<"\n";
	}
	else if(option == 2)
	{
		cout<<"Enter a number between 0 and 100: ";
		cin>>grade;
		result = get_letter_grade_using_switch(grade);
		cout<<result<<"\n";
	}
	else if(option == 3)
	{
		cout<<std::endl;
	}
	else
	{
		cout<<"Invalid option";
	}
	

	return 0;
}