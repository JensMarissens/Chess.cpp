#include <Arduino.h>

#include "../headers/gameState.h"

#include "../headers/globals.h"
#include "../headers/gameLogic.h"

gameLogic gl;

gameState::gameState() {}

void gameState::startGame()
{
    chessboard.initDebugBoard();
    chessboard.initBoard();

    // startFlag should come from a both boards function that checks. class gameLogic
    chessboard.printBoard();

    chessboard.readBoard();
    chessboard.printDebugBoard();

    if (!chessboard.startConditionValidFlag()) // if board reading and assigned colors (tile values) DONT match, exit function, else go on. set startflag to false. (Startflag will replace param in ino file.)
    {
        // collect error message? Do we want a gui or not?? Maybe a log at least? For debugging.
        return;
    }
    else if (chessboard.startConditionValidFlag())
    {
        Serial.println();
    }

    while (true)
    {
        /* code */
    }
}