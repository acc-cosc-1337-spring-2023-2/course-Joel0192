#include "tic_tac_toe_3.h"

bool TicTacToe3::check_column_win()
{   
    for(int i = 0; i < 3; i++)
    {
        if(pegs[i] == "X" && pegs[i+3] == "X" && pegs[i+6] == "X")
        {
            return true;
        }
        else if(pegs[i] == "O" && pegs[i+3] == "O" && pegs[i+6] == "O")
        {
            return true;
        }
    }
    return false;
}


bool TicTacToe3::check_row_win()
{   
    for(int i = 0; i < 9; i+=3)
    {
        if(pegs[i] == "X" && pegs[i+1] == "X" && pegs[i+2] == "X")
        {
            return true;
        }
        else if(pegs[i] == "O" && pegs[i+1] == "O" && pegs[i+2] == "O")
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe3::check_diagonal_win()
{   
    
    if((pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X"))
    {
        return true;
    }
    else if(pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X")
    {
        return true;
    }

    
    else if(pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
    {
        return true;
    }
    else if(pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O")
    {
        return true;
    }
    
    else{return false;}
}