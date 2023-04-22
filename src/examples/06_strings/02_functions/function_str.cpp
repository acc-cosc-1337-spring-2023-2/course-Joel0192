#include "function_str.h"

void str_val_ref_param(std::string str1, std::string &str2, const std::string & str3)
{
    str1 = "changed";
    str2 = "changed";
    //str3 = "changed"; can't change a const parameter
    //cout<<str<<"\n";//this would work
}