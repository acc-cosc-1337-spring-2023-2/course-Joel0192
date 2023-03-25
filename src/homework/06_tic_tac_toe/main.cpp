#include <iostream>
#include "tic_tac_toe.h"


int main()
{

    TicTacToe play;

    auto prompt = 'i';

    do
    {
        
        string first_player;
        int position;
        while(first_player != "X" && first_player != "O")
        {
            cout<<"Enter X or O: ";
            cin>>first_player;
        }
        
        
        play.start_game(first_player);

        
        while(play.game_over() == false)
        {
            cout<<"Enter position from 1 to 9: ";
            cin>>position;
            play.mark_board(position);
            play.display_board();
        }
        cout<<"Game over\n\n";

        cout<<"Would you like to play another game? (Y/N) ";
        cin>>prompt;
    } 
    while (prompt != 'n' && prompt != 'N');

    return 0;
}