#include <Arduino.h>
#include "debug.h"

debug::debug(){}

void debug::initDebugBoard()
{
    Serial.println("Initializing Debug Array");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            debugBoard[i][j] = '0';
        }
    }
}

void debug::printDebugBoard() //   Create debug class and put all debug functions in there for readability
{

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Serial.print(char(debugBoard[row][col]));
            Serial.print("\t");
        }
        Serial.println();
    }
    Serial.println("----------------------------------------------------------");
}