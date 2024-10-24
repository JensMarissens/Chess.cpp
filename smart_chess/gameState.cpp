#include <Arduino.h>
#include "gameState.h"

#include "board.h"
#include "PGN.h"

board chessboard;
PGN pgn;

gameState::gameState() {}

void gameState::startGame()
{

    chessboard.initBoard();
    chessboard.initDebugBoard();

    while (true)
    {
        move currentMove = pgn.validMove();
        
        if (currentMove.isValid)
        {
            pgn.writePGNArray(currentMove.PGNnotation);
        };
        

        //chessboard.printDebugBoard();
        //chessboard.printBoard();
    }
}