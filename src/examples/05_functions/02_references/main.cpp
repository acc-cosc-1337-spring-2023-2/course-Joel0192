#include<iostream>

using std::cout; using std::cin;


int main()
{
    auto num = 10;
    auto num1 = 50;
    int &num_ref = num;//num_ref is a reference variable; holds the stack address of num

    cout<<"Num is: "<<num<<"\n";
    cout<<"Stack address of num: "<<&num<<"\n\n";

    cout<<"Num via num_ref is: "<<num_ref<<"\n";
    cout<<"Address that num_ref points to: "<<&num_ref<<"\n\n";

    num_ref = 20;

    cout<<"Num is: "<<num<<"\n";
    cout<<"Num via num_ref is: "<<num_ref<<"\n";

    num_ref = num1;

    cout<<"Num is: "<<num<<"\n";
    cout<<"Num via num_ref is: "<<num_ref<<"\n";
    cout<<"Stack address num_ref points to: "<<&num_ref<<"\n\n";

    return 0;
}