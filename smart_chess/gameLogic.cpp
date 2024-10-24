#include <Arduino.h>
#include "gameLogic.h"
#include "board.h"

board chessbrd;

gameLogic::gameLogic() {}

move gameLogic::validMove()
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