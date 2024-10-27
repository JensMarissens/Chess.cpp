#include <Arduino.h>
#include "gameState.h"

#include "globals.h"
#include "gameLogic.h"

gameLogic gl;

gameState::gameState() {}

void gameState::startGame()
{

    chessboard.initBoard();
    chessboard.initDebugBoard();

    while (true)
    {
        move currentMove = gl.validMove();
        
        if (currentMove.isValid)
        {
            pgn.writePGNArray(currentMove.PGNnotation);
        };
        
    
        //chessboard.printDebugBoard();
        //chessboard.printBoard();
    }
}