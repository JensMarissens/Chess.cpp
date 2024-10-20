#include <Arduino.h>
#include "gameState.h"

#include "board.h"

board chessboard;

gameState::gameState() {}

void gameState::startGame()
{

    chessboard.initBoard();
    chessboard.initDebugBoard();

    while (true)
    {
        chessboard.readBoard();
        chessboard.printDebugBoard();
        //chessboard.printBoard();

        delay(1000);
    }
}