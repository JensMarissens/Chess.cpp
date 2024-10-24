#include <Arduino.h>
#include "gameState.h"

#include "board.h"
#include "PGN.h"
#include "gameLogic.h"

board chessboard;
PGN pgn;
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