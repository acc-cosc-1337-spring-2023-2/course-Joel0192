#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::istream; 
using std::ostream;

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

class TicTacToe
{
    friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);
    friend std::istream& operator>>(std::istream& in, TicTacToe& game);

    public:
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        void display_board() const;
        string get_winner();
        
    private:
        void set_next_player();
        void clear_board();
        bool check_board_full();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_winner();
        string winner;
        string player;
        vector<std::string> pegs {9, " "};

};

#endif