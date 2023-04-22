//cpp
#include "tic_tac_toe.h"

TicTacToe::TicTacToe(int size) : pegs(size*size, " "){}
TicTacToe::TicTacToe(vector<string> p, string win)
  : pegs(p), winner(win){}

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

vector<string> TicTacToe::get_pegs() const{return pegs;}

std::ostream& operator<<(std::ostream& out, const TicTacToe& game)
{
    int row_size = sqrt(game.pegs.size());
    int size = static_cast<int>(game.pegs.size());
    for (int i = 0; i < size; i++)
    {
        out << game.pegs[i];
        if ((i + 1) % row_size == 0) 
        {
            out << "\n";
        } else {
            out << "|";
        }
    }
    out<<"\n";
    return out;
}
std::istream& operator>>(std::istream& in, TicTacToe& game)
{
    int position;
    int max_position = game.pegs.size();
    while(true)
    {
        cout<<"Enter position from 1 to "<<max_position<<": ";
        in>>position;
        if(position >= 1 && position <= max_position)
        {
            break;
        }
        else
        {
            cout<<"invalid input.  Please enter a number from 1 to "<<max_position<<". \n";
        }
    }
    game.mark_board(position);
    return in;
}
