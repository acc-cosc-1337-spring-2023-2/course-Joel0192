#include "tic_tac_toe_4.h"

bool TicTacToe4::check_column_win()
{   
    for(int i = 0; i < 4; i++)
    {
        if(pegs[i] == "X" && pegs[i+4] == "X" && pegs[i+8] == "X" && pegs[i+12] == "X")
        {
            return true;
        }
        else if(pegs[i] == "O" && pegs[i+4] == "O" && pegs[i+8] == "O" && pegs[i+12] == "O")
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_row_win()
{   
    for(int i = 0; i < 16; i+=4)
    {
        if(pegs[i] == "X" && pegs[i+1] == "X" && pegs[i+2] == "X" && pegs[i+3] == "X")
        {
            return true;
        }
        else if(pegs[i] == "O" && pegs[i+1] == "O" && pegs[i+2] == "O" && pegs[i+3] == "O")
        {
            return true;
        }
    }
    return false;
}

bool TicTacToe4::check_diagonal_win()
{   
    if((pegs[0] == "X" && pegs[5] == "X" && pegs[10] == "X" && pegs[15] == "X") || 
    (pegs[0] == "O" && pegs[5] == "O" && pegs[10] == "O" && pegs[15] == "O"))
    {
        return true;
    }
    else if((pegs[12] == "X" && pegs[9] == "X" && pegs[6] == "X" && pegs[3] == "X") || 
    (pegs[12] == "O" && pegs[9] == "O" && pegs[6] == "O" && pegs[3] == "O"))
    {
        return true;
    }
    else{return false;}
}