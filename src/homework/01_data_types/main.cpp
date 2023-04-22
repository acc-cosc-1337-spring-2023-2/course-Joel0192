//write include statements
#include <iostream>
#include "data_types.h"

//write namespace using statement for cout
using namespace std;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/

int main()
{
	int num;
	cin >> num;
	int result;

	result = multiply_numbers(num);

	cout << result;


	

	return 0;
}
