/*
 * ReversiConsoleView.h
 *
 *  Created on: Oct 26, 2023
 *      Author: zakis
 */

/**
 * @file ReversiConsoleView.h
 * @brief Definition of the ReversiConsoleView class.
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_

#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief Handles the console view for the Reversi board.
 */
class ReversiConsoleView {

private:
    ReversiBoard* reversiBoard; ///< Pointer to the ReversiBoard model.

public:
    /**
     * @brief Constructor for ReversiConsoleView.
     * @param tempReversiBoard Pointer to the ReversiBoard model.
     */
    ReversiConsoleView(ReversiBoard* reversiBoard);

    /**
     * @brief Prints the current state of the Reversi game to the console.
     */
    void print();

    /**
     * @brief Destructor for ReversiConsoleView class
     */
   ~ReversiConsoleView();
};

#endif /* REVERSICONSOLEVIEW_H_ */

