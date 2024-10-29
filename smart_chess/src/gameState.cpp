#include "../headers/gameState.h"

#include "../headers/globals.h"
#include "../headers/gameLogic.h"

gameLogic gl;

gameState::gameState() {}

void gameState::startGame()
{

    chessboard.initBoard();
    chessboard.initDebugBoard();

    while (true)
    {
        //move currentMove = gl.validMove();
        //move currentTurn = gl.validTurn();
        
        //if (currentTurn.isValid)
        //{
        //    pgn.writePGNArray(currentTurn.PGNnotation);
        //};
        
    
        //chessboard.printDebugBoard();
        //chessboard.printBoard();
    }
}