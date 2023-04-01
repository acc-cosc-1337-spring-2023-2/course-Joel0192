#include <iostream>
#include "tic_tac_toe.h"


int main()
{

    TicTacToe play;

    auto prompt = 'Y';

    while(prompt == 'Y' || prompt == 'y')
    {
        
        string first_player;
        int position;
        while(true)
        {
            cout<<"Enter X or O: ";
            cin>>first_player;
            if(first_player == "X" || first_player == "O")
            {
                break;
            }
            else
            {
                cout<<"Invalid input. Please enter X or O.\n";
            }
        }
        
        play.start_game(first_player);

        
        while(play.game_over() == false)
        {
            cout<<"Enter position from 1 to 9: ";
            cin>>position;
            play.mark_board(position);
            play.display_board();
        }
        cout<<"Game over\n"<<"The winner is "<<play.get_winner()<<".\n\n";

        while (true)
        {
            cout<<"Would you like to play another game? (Y/N) ";
            cin>>prompt;
        
            if (prompt == 'n' || prompt == 'N' || prompt == 'y' || prompt == 'Y')
            {
                break;
            }
            else{cout<<"Invalid input. Please enter a Y or N/\n";}
        }
    } 
    

    return 0;
}