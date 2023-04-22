#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <memory>

using std::unique_ptr; 
using std::make_unique;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(5);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "C");

	
}

TEST_CASE("Test first player set to X.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	REQUIRE(test_instance->get_player() == "X");
}

TEST_CASE("Test first player set to O.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("O");

	REQUIRE(test_instance->get_player() == "O");
}

TEST_CASE("Test win by first column.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	test_instance->mark_board(2);
	test_instance->mark_board(4);
	test_instance->mark_board(3);
	test_instance->mark_board(7);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}

TEST_CASE("Test win by second column")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(2);
	test_instance->mark_board(1);
	test_instance->mark_board(5);
	test_instance->mark_board(4);
	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by third column")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(3);
	test_instance->mark_board(1);
	test_instance->mark_board(6);
	test_instance->mark_board(2);
	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}

TEST_CASE("Test win by first row")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	test_instance->mark_board(4);
	test_instance->mark_board(2);
	test_instance->mark_board(5);
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by second row")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(4);
	test_instance->mark_board(2);
	test_instance->mark_board(5);
	test_instance->mark_board(1);
	test_instance->mark_board(6);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by third row")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(7);
	test_instance->mark_board(1);
	test_instance->mark_board(8);
	test_instance->mark_board(2);
	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win diagonlly from top left")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	test_instance->mark_board(2);
	test_instance->mark_board(5);
	test_instance->mark_board(3);
	test_instance->mark_board(9);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win diagonlly from bottom left")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe3>();
	test_instance->start_game("X");

	test_instance->mark_board(7);
	test_instance->mark_board(1);
	test_instance->mark_board(5);
	test_instance->mark_board(2);
	test_instance->mark_board(3);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}

TEST_CASE("Verify that that x_win, o_win, and ties tally correctly")
{
	TicTacToeManager manager_instance;

	unique_ptr<TicTacToe> test_instance1 = make_unique<TicTacToe3>();
	test_instance1->start_game("X");

	test_instance1->mark_board(7);
	test_instance1->mark_board(1);
	test_instance1->mark_board(5);
	test_instance1->mark_board(2);
	test_instance1->mark_board(3);
	REQUIRE(test_instance1->game_over() == true);
	REQUIRE(test_instance1->get_winner() == "X");

	manager_instance.save_game(test_instance1);
	int o, x, t;
    manager_instance.get_winner_total(o, x, t);
    REQUIRE(o == 0);
    REQUIRE(x == 1);
    REQUIRE(t == 0);

	unique_ptr<TicTacToe> test_instance2 = make_unique<TicTacToe3>();
	test_instance2->start_game("O");

	test_instance2->mark_board(1);
	test_instance2->mark_board(2);
	test_instance2->mark_board(5);
	test_instance2->mark_board(3);
	test_instance2->mark_board(9);
	REQUIRE(test_instance2->game_over() == true);
	REQUIRE(test_instance2->get_winner() == "O");

	manager_instance.save_game(test_instance2);
	
    manager_instance.get_winner_total(o, x, t);
    REQUIRE(o == 1);
    REQUIRE(x == 1);
    REQUIRE(t == 0);

	unique_ptr<TicTacToe> test_instance3 = make_unique<TicTacToe3>();
	test_instance3->start_game("X");

	test_instance3->mark_board(1);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(2);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(3);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(4);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(5);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(7);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(6);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(9);
	REQUIRE(test_instance3->game_over() == false);
	test_instance3->mark_board(8);
	REQUIRE(test_instance3->game_over() == true);
	REQUIRE(test_instance3->get_winner() == "C");

	manager_instance.save_game(test_instance3);
	
    manager_instance.get_winner_total(o, x, t);
    REQUIRE(o == 1);
    REQUIRE(x == 1);
    REQUIRE(t == 1);
}





TEST_CASE("Test game over if 16 slots are selected.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(2); //o
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(3); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(4); //o
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(6); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(5); //o
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(7); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(8); //o
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(10); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(9); //o
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(12); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(11); //o
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(13); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(14); //o
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(15); //x
	REQUIRE(test_instance->game_over() == false);

	test_instance->mark_board(16); //o
	REQUIRE(test_instance->game_over() == true);

	REQUIRE(test_instance->get_winner() == "C");

	
}
TEST_CASE("Test first player set to X 4.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	REQUIRE(test_instance->get_player() == "X");
}
TEST_CASE("Test first player set to O 4.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("O");

	REQUIRE(test_instance->get_player() == "O");
}
TEST_CASE("Test win by first column 4.")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1); //x
	test_instance->mark_board(2); //o
	test_instance->mark_board(5);//x
	test_instance->mark_board(3);//o
	test_instance->mark_board(9);//x
	test_instance->mark_board(6);//o
	test_instance->mark_board(13);//x
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by second column 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(2);
	test_instance->mark_board(1);
	test_instance->mark_board(6);
	test_instance->mark_board(4);
	test_instance->mark_board(10);
	test_instance->mark_board(5);
	test_instance->mark_board(14);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by third column 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(3);
	test_instance->mark_board(1);
	test_instance->mark_board(7);
	test_instance->mark_board(2);
	test_instance->mark_board(11);
	test_instance->mark_board(12);
	test_instance->mark_board(15);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by fourth column 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(4);
	test_instance->mark_board(1);
	test_instance->mark_board(8);
	test_instance->mark_board(2);
	test_instance->mark_board(12);
	test_instance->mark_board(11);
	test_instance->mark_board(16);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by first row 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	test_instance->mark_board(10);
	test_instance->mark_board(2);
	test_instance->mark_board(5);
	test_instance->mark_board(3);
	test_instance->mark_board(16);
	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by second row 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(5);
	test_instance->mark_board(2);
	test_instance->mark_board(6);
	test_instance->mark_board(1);
	test_instance->mark_board(7);
	test_instance->mark_board(3);
	test_instance->mark_board(8);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by third row 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(9);
	test_instance->mark_board(1);
	test_instance->mark_board(10);
	test_instance->mark_board(2);
	test_instance->mark_board(11);
	test_instance->mark_board(3);
	test_instance->mark_board(12);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win by fourth row 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(13);
	test_instance->mark_board(1);
	test_instance->mark_board(14);
	test_instance->mark_board(2);
	test_instance->mark_board(15);
	test_instance->mark_board(3);
	test_instance->mark_board(16);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win diagonlly from top left 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(1);
	test_instance->mark_board(2);
	test_instance->mark_board(6);
	test_instance->mark_board(3);
	test_instance->mark_board(11);
	test_instance->mark_board(4);
	test_instance->mark_board(16);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Test win diagonlly from bottom left 4")
{
	unique_ptr<TicTacToe> test_instance = make_unique<TicTacToe4>();
	test_instance->start_game("X");

	test_instance->mark_board(13);
	test_instance->mark_board(1);
	test_instance->mark_board(10);
	test_instance->mark_board(2);
	test_instance->mark_board(7);
	test_instance->mark_board(3);
	test_instance->mark_board(4);
	REQUIRE(test_instance->game_over() == true);
	REQUIRE(test_instance->get_winner() == "X");
}
TEST_CASE("Verify that that x_win, o_win, and ties tally correctly 4")
{
	TicTacToeManager manager_instance;

	unique_ptr<TicTacToe> test_instance1 = make_unique<TicTacToe4>();
	test_instance1->start_game("X");

	test_instance1->mark_board(13);
	test_instance1->mark_board(1);
	test_instance1->mark_board(10);
	test_instance1->mark_board(2);
	test_instance1->mark_board(7);
	test_instance1->mark_board(3);
	test_instance1->mark_board(4);
	REQUIRE(test_instance1->game_over() == true);
	REQUIRE(test_instance1->get_winner() == "X");

	manager_instance.save_game(test_instance1);
	int o, x, t;
    manager_instance.get_winner_total(o, x, t);
    REQUIRE(o == 0);
    REQUIRE(x == 1);
    REQUIRE(t == 0);

	unique_ptr<TicTacToe> test_instance2 = make_unique<TicTacToe4>();
	test_instance2->start_game("O");
	test_instance2->mark_board(13);
	test_instance2->mark_board(1);
	test_instance2->mark_board(14);
	test_instance2->mark_board(2);
	test_instance2->mark_board(15);
	test_instance2->mark_board(3);
	test_instance2->mark_board(16);
	REQUIRE(test_instance2->game_over() == true);
	REQUIRE(test_instance2->get_winner() == "O");

	manager_instance.save_game(test_instance2);
	
    manager_instance.get_winner_total(o, x, t);
    REQUIRE(o == 1);
    REQUIRE(x == 1);
    REQUIRE(t == 0);

	unique_ptr<TicTacToe> test_instance3 = make_unique<TicTacToe4>();
	test_instance3->start_game("X");

	test_instance3->mark_board(1); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(2); //o
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(3); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(4); //o
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(6); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(5); //o
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(7); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(8); //o
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(10); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(9); //o
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(12); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(11); //o
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(13); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(14); //o
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(15); //x
	REQUIRE(test_instance3->game_over() == false);

	test_instance3->mark_board(16); //o
	
	REQUIRE(test_instance3->game_over() == true);
	REQUIRE(test_instance3->get_winner() == "C");

	manager_instance.save_game(test_instance3);
	
    manager_instance.get_winner_total(o, x, t);
    REQUIRE(o == 1);
    REQUIRE(x == 1);
    REQUIRE(t == 1);
}