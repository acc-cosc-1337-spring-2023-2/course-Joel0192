#include "for_ranged_str.h"

void iterate_string_val_param(std::string str)
{
    for(auto ch: str)    
    {
        ch = 'z';
    }
}

void iterate_string_ref_param(std::string &str)
{
    for(auto &ch: str)    
    {
        ch = 'z';
    }
}