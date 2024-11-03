#include <Arduino.h>
#include "../headers/board.h"

piece *gameBoard[8][8];

int coordinates[4] = {0, 0, 0, 0};

// nothing has to access this, this should be here
piece *backRowWhite[8] = {
    //  DELETE PIECES FROM MEMOPRY WHEN CAPTURED
    new Rook('W', 'R', coordinates[4]), new Knight('W', 'K', coordinates[4]), new Bishop('W', 'B', coordinates[4]), new Queen('W', 'Q', coordinates[4]), new King('W', 'K', coordinates[4]), new Bishop('W', 'B', coordinates[4]), new Knight('W', 'K', coordinates[4]), new Rook('W', 'R', coordinates[4])};

piece *pawnRowWhite[8] = {
    new Pawn('W', 'p', coordinates[4]), new Pawn('W', 'p', coordinates[4]), new Pawn('W', 'p', coordinates[4]), new Pawn('W', 'p', coordinates[4]), new Pawn('W', 'p', coordinates[4]), new Pawn('W', 'p', coordinates[4]), new Pawn('W', 'p', coordinates[4]), new Pawn('W', 'p', coordinates[4])};

piece *pawnRowBlack[8] = {
    new Pawn('B', 'p', coordinates[4]), new Pawn('B', 'p', coordinates[4]), new Pawn('B', 'p', coordinates[4]), new Pawn('B', 'p', coordinates[4]), new Pawn('B', 'p', coordinates[4]), new Pawn('B', 'p', coordinates[4]), new Pawn('B', 'p', coordinates[4]), new Pawn('B', 'p', coordinates[4])};

piece *backRowBlack[8] = {
    new Rook('B', 'R', coordinates[4]), new Knight('B', 'K', coordinates[4]), new Bishop('B', 'B', coordinates[4]), new Queen('B', 'Q', coordinates[4]), new King('B', 'K', coordinates[4]), new Bishop('B', 'B', coordinates[4]), new Knight('B', 'K', coordinates[4]), new Rook('B', 'R', coordinates[4])};

board::board()
{
    initDebugBoard();
    initBoard();
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

void board::initBoard()
{
    for (int i = 0; i < 8; i++)
    {
        gameBoard[0][i] = backRowWhite[i];
        gameBoard[1][i] = pawnRowWhite[i];

        gameBoard[6][i] = pawnRowBlack[i];
        gameBoard[7][i] = backRowBlack[i];

        for (int j = 2; j < 6; j++)
        {
            gameBoard[j][i] = nullptr; // Empty squares
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

    for (int col = 0; col < 4; col++) // Rewrite and add to above array? Or keep seperate for readability?
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
            Serial.print((debugBoard[row][col]));
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
            if (gameBoard[i][j] != nullptr)
            {

                // gameBoard[i][j]->print(gameBoard[i][j]->color, gameBoard[i][j]->type); // Call the print method on the piece
                Serial.print((char)gameBoard[i][j]->getColor());
                Serial.print((char)gameBoard[i][j]->getType());
                Serial.print("\t");
            }
            else
            {
                Serial.print("Empty\t");
            }
        }
        Serial.println(); // Newline for the next row
    }
}