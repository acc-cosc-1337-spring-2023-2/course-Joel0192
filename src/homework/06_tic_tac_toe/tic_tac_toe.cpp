//cpp
#include "tic_tac_toe.h"
#include <iostream>

TicTacToe::TicTacToe(int size) : pegs(size*size, " "){}

void TicTacToe::set_next_player() 
{
    if (player == "X") 
    {
        player = "O";
    }
    else 
    {
        player = "X";
    }
}
bool TicTacToe::check_board_full() 
{
    for (int i = 0; i < 9; i++) 
    {
        if (pegs[i] == " ") 
        {
            return false;
        }
    }
    return true;
}
void TicTacToe::clear_board() 
{
    for (int i = 0; i < 9; i++) 
    {
        pegs[i] = " ";
    }
}
bool TicTacToe::game_over() 
{
    if (check_column_win() == true || check_row_win() == true || check_diagonal_win() == true)
    {
        set_winner();
        return true;
    }
    else if (check_board_full() == true)
    {
        winner = "C";
        return true;
    }
    else
    {
        return false;
    }
}

void TicTacToe::start_game(string first_player) 
{
    if(first_player == "X" || first_player == "O")
    {
        player = first_player;
    }
    
    clear_board();
}

void TicTacToe::mark_board(int position) 
{
    pegs[position - 1] = player;
    set_next_player();
}

std::string TicTacToe::get_player() const 
{
    return player;
}

string TicTacToe::get_winner()
{
    return winner;
}
bool TicTacToe::check_column_win()
{   
    return false;
}
bool TicTacToe::check_row_win()
{   
    return false;
}
bool TicTacToe::check_diagonal_win()
{   
    return false;
}
void TicTacToe::set_winner()
{
    if(player == "X")
    {
        winner = "O";
    }
    else
    {
        winner = "X";
    }
}
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            out<<game.pegs[(i * 3) + j];
            if (j < 2){out<<"|";}
        }
        if(i < 2){out<<"\n";}
    }
    out<<"\n";
    return out;
}
std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    while(true)
    {
        cout<<"Enter position from 1 to 9: ";
        in>>position;
        if(position >= 1 && position <=9)
        {
            break;
        }
        else
        {
            cout<<"invalid input.  Please enter a number from 1 to 9. \n";
        }
    }
    game.mark_board(position);
    return in;
}
