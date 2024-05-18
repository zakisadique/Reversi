/*
 * ReversiBoard.cpp
 *
 *  Created on: Oct 25, 2023
 *      Author: zakis
 */

/**
 * @file ReversiBoard.cpp
 * @brief Implementation of the ReversiBoard class functions and related enums.
 */

#include "ReversiBoard.h"
#include <iostream>

using namespace std;

/**
 * @brief Enumeration representing eight possible directions on the Reversi
 * board.
 */
enum Direction {
    UP,          ///< Up direction.
    UP_RIGHT,    ///< Up-right direction.
    RIGHT,       ///< Right direction.
    RIGHT_DOWN,  ///< Right-down direction.
    DOWN,        ///< Down direction.
    DOWN_LEFT,   ///< Down-left direction.
    LEFT,        ///< Left direction.
    LEFT_UP      ///< Left-up direction.
};

// constructor
ReversiBoard::ReversiBoard() {

	for (int i = 0; i < NUMBER_ROWS; ++i){
		for (int j = 0; j < NUMBER_COLUMNS; ++j){
			board[i][j] = EMPTY;
		}
	}

	// sets the middle cells according to the default layout
	board[NUMBER_ROWS/2 - 1][NUMBER_COLUMNS/2 - 1] = PLAYER_ONE;
	board[NUMBER_ROWS/2 - 1][NUMBER_COLUMNS/2] = PLAYER_TWO;
	board[NUMBER_ROWS/2][NUMBER_COLUMNS/2 - 1] = PLAYER_TWO;
	board[NUMBER_ROWS/2][NUMBER_COLUMNS/2] = PLAYER_ONE;

}

// gets the current state of the cell
State ReversiBoard::getState(int row, int col) {
	return (board[row][col]);
}

// Validates and flips stones as per game rules
ErrorCode ReversiBoard::ValidateAndSetStone(int row, int col,
		State currentPlayer) {

	// Sets the valid flag to no
	bool isValidMove = false;

	// Return if the move is out of bounds
	if (row > NUMBER_ROWS -1 || col > NUMBER_COLUMNS -1 || row < 0 || col < 0) {
		return OUT_OF_BOUNDS;

	// Return if the cell is already occupied
	} else if (board[row][col] != EMPTY){
		return ALREADY_OCCUPIED;


	} else {

		/** Array representing the change in row position while traversing
		 * every direction (based on Direction enum).
		 */
		int tempRowCondition[] = {-1, -1, 0, 1, 1, 1, 0, -1};

		/**
		 * Array representing the change in column position while traversing
		 * every direction (based on Direction enum).
		 */
		int tempColCondition[] = {0, 1, 1, 1, 0, -1, -1, -1};

		// for loop for traversing in every direction
		for (int direction = UP; direction <= LEFT_UP; ++direction){

			/**
			 * sets the initial values of row and column from where traversing
			 * starts
			 */
			int tempRow = row + tempRowCondition[direction];
			int tempCol = col + tempColCondition[direction];


			/**
			 * keeps track of the steps taken while traversing a particular
			 * direction
			 */
			int directionSteps = 0;

			/**
			 * keeps traversing while the row and column indices are within
			 * bounds
			 */
			while ((tempRow >= 0 && tempRow < NUMBER_ROWS) &&
					(tempCol >= 0 && tempCol < NUMBER_COLUMNS)) {

				/**
				 * gets the stone of the current cell
				 */
				State curentStone = board[tempRow][tempCol];

				/**
				 * traversal ends if an empty cell is encountered
				 */
				if (curentStone == EMPTY){
					break;

				 // keeps traversing if an enemy stone is met
				} else if (curentStone != currentPlayer){
					directionSteps++;
					tempRow += tempRowCondition[direction];
					tempCol += tempColCondition[direction];

					continue;

				 // if a stone of the current player is encountered
				} else if (curentStone == currentPlayer){
					/**
					 * if steps taken is equal to or more than 1, the move is
					 * valid and the intermediate stones need to be flipped
					 * as per game rules
					 */
					if (directionSteps != 0){

						//stores the current values of rows and columns

						int updateRow = row;
						int updateCol = col;

						// retraces the steps and flips the stones
						for (int i = 0; i <= directionSteps; ++i){

							board[updateRow][updateCol] =  currentPlayer;
							updateRow += tempRowCondition[direction];
							updateCol += tempColCondition[direction];
						}

						// marks the move as valid

						isValidMove = true;
						break;


					 //if steps taken is 0, stop traversal. the move is not

					} else if (directionSteps == 0){
						break;
					} else {
						// do nothing
					}
				} else {
					// do nothing
				}
			}
		}


	}

	return isValidMove ? VALID_MOVE : INVALID_MOVE;
}

void ReversiBoard::setState(int row, int col, State currentPlayer) {

	/**
	 * input from users is based on 1-index. Changes the rows and columns to
	 * 0-index
	 */
	row--;
	col--;
	// validate the move. If move is valid, sets the stones as per game rules
	ErrorCode status = ValidateAndSetStone(row, col, currentPlayer);

	if (status == OUT_OF_BOUNDS){
		cout << "Invalid move: Entered position is out of bounds" <<
				endl << endl;
		return;

	} else if (status == ALREADY_OCCUPIED){
		cout << "Invalid move: Entered position is already occupied" <<
				endl << endl;
		return;

	} else if (status == INVALID_MOVE){
		cout << "Invalid move: Entered position is an illegal move" <<
				endl << endl;
		return;

	}
	else {
		// prints which player made the move based on enum values of Players
		cout << endl << (currentPlayer ? "Player Two" : "Player One") <<
				" moved to " << row+1 << ", " << col+1 << endl << endl;
	}
}

ReversiBoard::~ReversiBoard() {
}
