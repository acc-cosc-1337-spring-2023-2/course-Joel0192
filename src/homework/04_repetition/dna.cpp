//add include statements
#include "dna.h"

//add function(s) code here
int factorial(int num)
{
    auto sum = 1;

    while(num > 0)
    {
        sum *= num;
        num--;
    }

    return sum;
}

int gcd(int num1, int num2)
{
    auto temp = 0;

    while(num1 != num2)
    {
        if(num1 < num2)
        {
            temp = num1;
            num1 = num2;
            num2 = temp;
        }
        if(num1 > num2)
        {
            num1 = num1 - num2;
        }
    }
    return num1;
}