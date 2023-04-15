#include <iostream>
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"


using std::make_unique;

int main()
{
    TicTacToeManager manager;
    unique_ptr<TicTacToe> game;
    int o, x, t;
    int size;
    

    auto prompt = 'Y';

    while(prompt == 'Y' || prompt == 'y')
    {

        while(true)
        {
            cout<<"Choose game size (3 or 4): ";
            cin>>size;

            if (size == 3 || size == 4)
            {
                break;
            }
            else
            {
                cout<<"Invalid input. Please enter 3 or 4.\n";
            }
        }
        
        if(size == 3)
        {
            game = make_unique<TicTacToe3>();
        }
        else
        {
            game = make_unique<TicTacToe4>();
        }

        string first_player;
         while(true)
        {
            cout<<"Enter X or O: ";
            cin>>first_player;
            if(first_player == "x")
            {
                first_player = "X";
            }
            if(first_player == "o")
            {
                first_player = "O";
            }
            if(first_player == "X" || first_player == "O")
            {
                break;
            }
            else
            {
                cout<<"Invalid input. Please enter X or O.\n";
            }
        }
        
        game->start_game(first_player);

        while(!game->game_over())
        {   
            cin >> *game;
            cout<< *game;
        }
        cout<<"Game over\n"<<"The winner is "<<game->get_winner()<<".\n\n";

        manager.save_game(game); 
        manager.get_winner_total(o, x, t);

        
        cout<<"O wins: "<<o<<"\n";
        cout<<"X wins: "<<x<<"\n";
        cout<<"Ties: "<<t<<"\n\n";

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
    cout<<"\n"<<manager<<"\n";
    manager.get_winner_total(o, x, t);
   
    cout<<"O wins: "<<o<<"\n";
    cout<<"X wins: "<<x<<"\n";
    cout<<"Ties: "<<t<<"\n\n";
    

    return 0;
}