#include <Arduino.h>
#include "gameState.h"

#include "board.h"
#include "debug.h"

debug debuggy;

board chessboard;

gameState::gameState() {}

void gameState::startGame()
{

    chessboard.initBoard();
    debuggy.initDebugBoard();

    while (true)
    {
        chessboard.readBoard();
        debuggy.printDebugBoard();
        //chessboard.printBoard();

        delay(1000);
    }
}