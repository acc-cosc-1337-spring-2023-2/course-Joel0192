#include "expressions.h"
#include "hwexpressions.h"
//example
//int add_numbers(int num1, int num2)
//{
	//return num1 + num2;
//}

//write function code here
double get_sales_tax_amount(double meal_amount)
{
	auto meal = meal_amount * tax_rate;
	return meal;
}

double get_tip_amount(double meal_amount, double tip_rate)
{
	auto tip = meal_amount * tip_rate;
	return tip;
}



