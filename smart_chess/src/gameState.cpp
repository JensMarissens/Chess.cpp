#include <Arduino.h>

#include "../headers/gameState.h"

#include "../headers/globals.h"
#include "../headers/gameLogic.h"

gameLogic gl;

gameState::gameState() {}

void gameState::startGame()
{
    chessboard.initsensorReadingsGrid();
    chessboard.initBoard();

    // startFlag should come from a both boards function that checks. class gameLogic
    if (!gl.startConditionValidFlag()) // if board reading and assigned colors (tile values) DONT match, exit function, else go on. set startflag to false. (Startflag will replace param in ino file.)
    {
        return; // collect error message? Do we want a gui or not?? Maybe a log at least? For debugging.
    }
    Serial.println("Start condition valid.");

    while (true)
    {
        Serial.println("Game running");
        gl.gameRound();
        chessboard.printBoard();
        chessboard.printsensorReadingsGrid();

        delay(1000);
    }
}