#include <iostream>
#include "tic_tac_toe.h"
using std::string;
using std::cout;
using std::cin;

int main()
{
    string first_player;
    cout << "Enter first player (X or O): ";
    cin >> first_player;

    TicTacToe play;
    play.start_game(first_player);

    bool continue_play = true;
    while (continue_play)
    {
        int position;
        cout << "Player " << play.get_player() << ", enter a position (1-9): ";
        cin >> position;
        play.mark_board(position);

        play.display_board();
        if (play.game_over())
        {
            cout << "Game over!\n";
            continue_play = false;
        }
    }

    cout << "Would you like to play again? (Y/N): ";
    char play_again;
    cin >> play_again;
    if (play_again == 'Y' || play_again == 'y')
    {
        play.clear_board();
        main();
    }

    return 0;
}