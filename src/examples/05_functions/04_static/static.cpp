#include "static.h"

using std::cout;

void use_static_var()
{
    static int num = 0;
    num++;
    cout<<num<<"\n";
}