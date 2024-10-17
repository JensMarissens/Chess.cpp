#include <Arduino.h>
#include "gameState.h"

#include "board.h"

board chessboard;

void startGame(){

    chessboard.initBoard();
    chessboard.initDebugBoard();

    
    chessboard.readBoard();
}