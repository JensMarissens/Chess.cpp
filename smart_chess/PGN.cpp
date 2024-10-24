#include <Arduino.h>
#include "PGN.h"
#include "board.h"

//board chessbrd;

PGN::PGN() {}

void PGN::initPGNArray()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // chessbrd.pieceType[i][j] = chessbrd.startCondition[i][j];
            //  measurements[i][j] = 0;
            // Serial.println(String(chessbrd.pieceType[i][j]) + "\t");
        }
    }
    Serial.println("initPGNArray");
}

void PGN::writePGNArray(String PGNnotation)
{

    String test = PGNnotation;

    Serial.print("Recorded PGN for current turn: ");
    Serial.println(test);
}
/*
move PGN::validMove() // To be moved to gameLogic once it works
{
    move turnMove;

    String test;

    Serial.println("Reading and assigning in 3s");
    delay(3000);
    chessbrd.readBoard();

    // Copy the debugBoard to tempBoard
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            chessbrd.tempBoard[i][j] = chessbrd.debugBoard[i][j];
        }
    }

    chessbrd.printDebugBoard();

    Serial.println("Reading again and checking in 3s");
    delay(3000);
    chessbrd.readBoard();

    // Check for differences
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (chessbrd.debugBoard[i][j] != chessbrd.tempBoard[i][j])
            {
                test += char(j + 97) + String(7 - i + 1) + ":"; // Seems to work, appears the problem is hardware. String doesn't get reset so we didn't see.
            }
        }
    }

    chessbrd.printDebugBoard();

    Serial.print("Result: ");

    // Print the differences
    if (test.length() > 0)
    {
        turnMove.isValid = true;
        turnMove.PGNnotation = test;
    }
    else
    {
        Serial.println("No differences found.");
        // return false;
    }

    test = "";
    return turnMove;
}
*/