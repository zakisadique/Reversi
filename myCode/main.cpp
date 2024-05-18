/*! \mainpage Reversi Board Implementation
 *	The implementation creates an 8 X 8 Reversi board and places players' pieces
 *	in the center as per the default configuration.
 *
 * The user has the ability to set its pieces at a particular cell on the board.
 *
 * If the move is legal, the board sets the piece and flips the required
 * intermediate pieces in compliance with the game rules.
 *
 * \section Rules Game rules
 *
 * A player can capture their opponent's pieces by trapping them between two of
 * their own pieces horizontally, vertically, or diagonally.
 *
 * When a player makes a move that results in capturing opponent pieces, those
 * pieces are changed to the capturing player's color.
 *
 * In order for the move to be deemed legal, at least one opponent's piece must
 * be captured.
 */

/**
 * @file main.cpp
 * @brief Entry point for the Reversi board application. It initializes the
 * board and asks the user to make moves, If the move is legal, the move is made
 * and  the board is updated, else, an error is displayed.
 */
#include <iostream>

#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

using namespace std;

int main ()
{
	// create a Reversi board
	ReversiBoard* myReversiBoard = new ReversiBoard;

	// create a console view of the Reversi board
	ReversiConsoleView printView(myReversiBoard);

	// Print the board's initial state
	printView.print();
	cout << endl;

	// Ask the user for player number and the coordinates they want to move to.
	for (int i = 0; i < 10; ++i){
		int playerNum = 0;
		cout << "Select player (1 or 2): ";
		cin >> playerNum;

		// Convert the player to its enum value
		State player = static_cast <State>(playerNum -1);

		// Get the coordinates
		int x, y = 0;
		cout << "Enter coordinates (x y): ";
		cin >> x >> y;

		// Make the move and print the board
		myReversiBoard -> setState(x, y, player);
		printView.print();
		cout << endl;
	}
	return 0;
}
