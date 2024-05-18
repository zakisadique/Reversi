/*
 * ReversiConsoleView.cpp
 *
 *  Created on: Oct 26, 2023
 *      Author: zakis
 */

/**
 * @file ReversiConsoleView.cpp
 * @brief Implementation of the ReversiConsoleView class functions.
 */

#include <iostream>
#include "ReversiConsoleView.h"
using namespace std;


// Constructor
ReversiConsoleView::ReversiConsoleView(ReversiBoard* tempReversiBoard) {
	reversiBoard = tempReversiBoard;
}

// prints the current view of the board
// Player one is shows as X, and player Two as O
void ReversiConsoleView::print() {


	for (int i = 0; i <= NUMBER_ROWS; ++i) {
		for (int j = 0; j <= NUMBER_COLUMNS; ++j) {
			if (i == 0) {
				if (j == 0) {
					cout << "  ";
				} else if (j != 0) {
					// print column number
					cout << j << " ";
				} else {}
			} else if (j == 0) {
				if (i == 0) {
					cout << "  ";
				} else if (i != 0) {
					// print row number
					cout << i << " ";
				} else {}
			} else { // print the state of the board
				if (reversiBoard -> getState(i-1, j-1) == EMPTY){
					cout << ". ";
				} else if (reversiBoard -> getState(i-1, j-1) == PLAYER_ONE){
					// X represents player one
					cout << "X ";
				} else if (reversiBoard -> getState(i-1, j-1) == PLAYER_TWO){
					// O represents player two
					cout << "O ";
				}
			}

		}
		cout << endl;
	}
}

ReversiConsoleView::~ReversiConsoleView() {
	// object destroyed
}
