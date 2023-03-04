//add include statements
#include "func.h"
#include <iostream>
#include <cctype>
using std::string;
//add function code here

double get_gc_content(const string &dna)
{
    double content_count = 0;

    for(auto &a : dna)
    {
        if(a == 'G' || a == 'C')
        {
            content_count++;
        }

    }
    return content_count / dna.length();
}

string reverse_string(string dna)
{
    string result;
    for(auto b = dna.length(); b > 0; b--)
    {
        result.push_back(dna[b - 1]);
    }
    return result;
}

string get_dna_compliment(string dna)
{
    string dna_compliment = reverse_string(dna);
    for(auto c = 0; c < dna_compliment.length(); c++)
    {
        auto d = dna_compliment[c];
        if(d == 'A')
        {
            dna_compliment[c] = 'T';
        }
        else if(d == 'T')
        {
            dna_compliment[c] = 'A';
        }
        else if(d == 'G')
        {
            dna_compliment[c] = 'C';
        }
        else if(d == 'C')
        {
            dna_compliment[c] = 'G';
        }

    }
    return dna_compliment;
}

bool valid_input(string dna) 
{
    bool valid;
    for (auto f = 0; f < dna.length(); f++)
    {
        auto e = dna[f];
        if(e == 'C' || e == 'G' || e == 'T' || e == 'A') 
        {
            valid = true;
        }
        else 
        {
            valid = false;
            break;
        }
    }
    return valid;
}