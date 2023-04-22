//cpp
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <fstream>

using std::ofstream; using std::ifstream; 
using std::getline; using std::make_unique;

void TicTacToeData::save_games(const vector<unique_ptr<TicTacToe>>& games)
{

    ofstream saveFile;
    saveFile.open("saved_games.dat");
    
    
    for(const auto& game : games)
    {
        vector<string> pegs = game->get_pegs();
         
        for (const string& s : pegs)
        {
            
            saveFile << s;
        }
        
  
        
        saveFile<<game->get_winner();
        saveFile<<"\n";
    }
     
    saveFile.close();
}

vector<unique_ptr<TicTacToe>> TicTacToeData::get_games()
{
    
    vector<unique_ptr<TicTacToe>> games;
    string line;
    ifstream readFile;
    readFile.open("saved_games.dat");
    
    if(readFile.is_open())
    {
        while (getline(readFile, line)) 
        {
            vector<string> pegs;
            for(size_t i = 0; i < line.size() - 1; i++)
            {
                pegs.emplace_back(string(1, line[i]));
            }
            string winner(1, line.back());

            if (pegs.size() == 9)
            {
                games.push_back(make_unique<TicTacToe3>(pegs, winner));
            }
            else if (pegs.size() == 16)
            {
                games.push_back(make_unique<TicTacToe4>(pegs, winner));
            }
        }
    readFile.close();
    }
    else
    {
        cout<<"Unable to open the file\n";
    }
    return games;
}