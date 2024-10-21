#include <Arduino.h>
#include "board.h"

// #include "PGN.h"

// PGN pgn;

board::board()
{
    initDebugBoard();
}

void board::initBoard()
{
    Serial.println("Initializing PGN Array");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pieceType[i][j] = startCondition[i][j];
        }
    }
}

void board::initDebugBoard()
{
    Serial.println("Initializing Debug Array");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            debugBoard[i][j] = 0;
        }
    }
}

void board::readBoard()
{

    for (int i = 0; i < 16; i++)
    {

        S0 = i & 1;
        S1 = (i >> 1) & 1;
        S2 = (i >> 2) & 1;
        S3 = (i >> 3) & 1;

        digitalWrite(4, S0);
        digitalWrite(5, S1);
        digitalWrite(6, S2);
        digitalWrite(7, S3);

        boardReadings[15 - i] = '1'; // writeBoard(0);
        boardReadings[31 - i] = '2'; // writeBoard(1);
        boardReadings[47 - i] = writeBoard(2);
        boardReadings[63 - i] = writeBoard(3);
    }

    for (int col = 0; col < 4; col++) //Rewrite and add to above array? Or keep seperate for readability?
    {
        for (int row = 0; row < 4; row++)
        {
            int baseIndex = col * 4 + row;

            debugBoard[3 - row][col] = boardReadings[baseIndex];
            debugBoard[3 - row][col + 4] = boardReadings[baseIndex + 16];
            debugBoard[7 - row][col] = boardReadings[baseIndex + 32];
            debugBoard[7 - row][col + 4] = boardReadings[baseIndex + 48];
        }
    }
}

char board::writeBoard(int pin)
{
    return (analogRead(pin) > 700) ? 'I' : (analogRead(pin) < 300) ? 'O'
                                                                   : 'X';
}

void board::printDebugBoard() //   Create debug class and put all debug functions in there for readability
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

void board::printBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Serial.print(pieceType[i][j]);
            Serial.print("\t");
        }
        Serial.println();
    }
    Serial.println("----------------------------------------------------------");
}