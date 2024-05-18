/*
 * ReversiBoard.h
 *
 *  Created on: Oct 25, 2023
 *      Author: zakis
 */

/**
 * @file ReversiBoard.h
 * @brief Definition of the ReversiBoard class.
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_

/**
 * @file ReversiBoard.h
 * @brief Declaration of the ReversiBoard class and related entities.
 */

#define NUMBER_ROWS 8         ///< Number of rows in the Reversi board.
#define NUMBER_COLUMNS 8      ///< Number of columns in the Reversi board.

/**
 * @enum State
 * @brief Enumeration representing the possible states of a cell on the Reversi
 * board.
 */
enum State {
    PLAYER_ONE,  ///< State indicating the presence of Player One's stone.
    PLAYER_TWO,  ///< State indicating the presence of Player Two's stone.
    EMPTY        ///< State indicating an empty cell.
};

/**
 * @enum Error_Code
 * @brief Enumeration representing error codes for move validation in Reversi.
 */
enum ErrorCode {
    VALID_MOVE,         ///< Move is valid.
    OUT_OF_BOUNDS,      ///< Move is out of bounds.
    ALREADY_OCCUPIED,   ///< Cell is already occupied.
    INVALID_MOVE        ///< Move is not legal.
};

/**
 * @class ReversiBoard
 * @brief Represents the Reversi board and provides methods for interacting
 * with it.
 */
class ReversiBoard {
private:
    State board[NUMBER_ROWS][NUMBER_COLUMNS];  ///<  Reversi board.

    /**
     * @brief Validates a move at the specified row and column for the desired
     * state. If the move is valid, flips the corresponding stones according to
     * game rules.
     * @param row Row index.
     * @param col Column index.
     * @param desiredState State to be validated.
     * @return Error_Code indicating the validity of the move.
     */
    ErrorCode ValidateAndSetStone(int row, int col, State desiredState);

public:
    /**
     * @brief Constructor for the ReversiBoard class.
     */
    ReversiBoard();

    /**
     * @brief Gets the state of the cell at the specified row and column
     * (whether it is empty, or occupied by player one or two).
     * @param row Row index.
     * @param col Column index.
     * @return State of the specified cell.
     */
    State getState(int row, int col);

    /**
     * @brief Sets the state of the cell at the specified row and column.
     * @param row Row index.
     * @param col Column index.
     * @param desiredState State (Player one or Player two) to set for the
     * specified cell.
     */
    void setState(int row, int col, State desiredState);

    /**
     * @brief Destructor for ReversiBoard class
     */
    ~ReversiBoard();
};

#endif /* REVERSIBOARD_H_ */
