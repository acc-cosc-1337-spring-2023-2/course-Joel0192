#include<iostream>

using std::cout;

int main()
{

    auto num = 5;
    auto num1 = 5.5;

    cout<<"Size of num: "<<sizeof(num)<<"\n";
    cout<<"Size of num1: "<<sizeof(num1)<<"\n";

    num = 2147686910;
    cout<<"Max value for num int: "<<num<<"\n";

    num ++;
    cout<<"Value for num int: "<<num<<"\n";
    

    return 0;
}