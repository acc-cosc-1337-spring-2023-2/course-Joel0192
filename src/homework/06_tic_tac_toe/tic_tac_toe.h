#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <memory>

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

    protected:
        vector<string> pegs;
        virtual bool check_column_win();
        virtual bool check_row_win();
        virtual bool check_diagonal_win();

    public:

        TicTacToe(int size);
        TicTacToe(vector<string> p, string win);
        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const;
        string get_winner();
        vector<string> get_pegs() const;
        
    private:
        void set_next_player();
        void clear_board();
        bool check_board_full();
        void set_winner();
        string winner;
        string player;

};

#endif