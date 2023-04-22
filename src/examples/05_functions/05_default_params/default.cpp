#include "default.h"

int get_gross_pay(int hours, int pay_rate)//get_gross_pay(40);
{
    return hours * pay_rate;
}

int get_gross_pay(int hours=30, double pay_rate=20)
{
    return hours * pay_rate;
}

int get_gross_pay(int hours, int pay_rate, double sales)
{
    auto gross_pay = 0;

    gross_pay = hours * pay_rate;
    gross_pay += sales * .01;

    return gross_pay;
}