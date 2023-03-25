//cpp
#include "tic_tac_toe.h"
#include <iostream>

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
    return check_board_full();
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

void TicTacToe::display_board() const 
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout<<pegs[(i * 3) + j];
            if (j < 2){cout<<"|";}
        }
        if(i < 2){cout<<"\n";}
    }
    cout<<"\n";
}


