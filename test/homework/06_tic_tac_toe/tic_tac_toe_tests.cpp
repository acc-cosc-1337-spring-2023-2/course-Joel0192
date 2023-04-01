#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test game over if 9 slots are selected.")
 {
 	TicTacToe test_instance;
 	test_instance.start_game("X");

 	test_instance.mark_board(1);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(2);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(3);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(4);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(5);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(7);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(6);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(9);
 	REQUIRE(test_instance.game_over() == false);

 	test_instance.mark_board(8);
 	REQUIRE(test_instance.game_over() == true);

 }
 TEST_CASE("Test first player set to X.")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	REQUIRE(test_instance.get_player() == "X");
}

TEST_CASE("Test first player set to O.")
{
	TicTacToe test_instance;
	test_instance.start_game("O");

	REQUIRE(test_instance.get_player() == "O");
}

TEST_CASE("Test win by first column.")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(1);
	test_instance.mark_board(2);
	test_instance.mark_board(4);
	test_instance.mark_board(3);
	test_instance.mark_board(7);
	REQUIRE(test_instance.game_over() == true);
}

TEST_CASE("Test win by second column")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(2);
	test_instance.mark_board(1);
	test_instance.mark_board(5);
	test_instance.mark_board(4);
	test_instance.mark_board(8);
	REQUIRE(test_instance.game_over() == true);
}
TEST_CASE("Test win by third column")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(3);
	test_instance.mark_board(1);
	test_instance.mark_board(6);
	test_instance.mark_board(2);
	test_instance.mark_board(9);
	REQUIRE(test_instance.game_over() == true);
}

TEST_CASE("Test win by first row")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(1);
	test_instance.mark_board(4);
	test_instance.mark_board(2);
	test_instance.mark_board(5);
	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == true);
}
TEST_CASE("Test win by second row")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(4);
	test_instance.mark_board(2);
	test_instance.mark_board(5);
	test_instance.mark_board(1);
	test_instance.mark_board(6);
	REQUIRE(test_instance.game_over() == true);
}
TEST_CASE("Test win by third row")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(7);
	test_instance.mark_board(1);
	test_instance.mark_board(8);
	test_instance.mark_board(2);
	test_instance.mark_board(9);
	REQUIRE(test_instance.game_over() == true);
}
TEST_CASE("Test win diagonlly from top left")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(1);
	test_instance.mark_board(2);
	test_instance.mark_board(5);
	test_instance.mark_board(3);
	test_instance.mark_board(9);
	REQUIRE(test_instance.game_over() == true);
}
TEST_CASE("Test win diagonlly from bottom left")
{
	TicTacToe test_instance;
	test_instance.start_game("X");

	test_instance.mark_board(7);
	test_instance.mark_board(1);
	test_instance.mark_board(5);
	test_instance.mark_board(2);
	test_instance.mark_board(3);
	REQUIRE(test_instance.game_over() == true);
}