#include <Arduino.h>
#include "../headers/board.h"

piece *gameBoard[8][8];

int coordinates[4] = {9, 9, 9, 9}; // This is here and in piece.h. Shouldn't be here but it gives an error?

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
    initsensorReadingsGrid();
    initBoard();
}

void board::initsensorReadingsGrid()
{
    // Serial.println("Initializing Debug Array");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            sensorReadingsGrid[i][j] = 'X';
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

piece *(*board::getBoard())[8][8]
{

    return &gameBoard;
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

        sensorReadingsRaw[15 - i] = writeSensorReadingsgrid(0);
        sensorReadingsRaw[31 - i] = writeSensorReadingsgrid(1);
        sensorReadingsRaw[47 - i] = writeSensorReadingsgrid(2);
        sensorReadingsRaw[63 - i] = writeSensorReadingsgrid(3);
    }

    for (int col = 0; col < 4; col++) // Rewrite and add to above array? Or keep seperate for readability?
    {
        for (int row = 0; row < 4; row++)
        {
            int baseIndex = col * 4 + row;

            sensorReadingsGrid[3 - row][col] = sensorReadingsRaw[baseIndex];
            sensorReadingsGrid[3 - row][col + 4] = sensorReadingsRaw[baseIndex + 16];
            sensorReadingsGrid[7 - row][col] = sensorReadingsRaw[baseIndex + 32];
            sensorReadingsGrid[7 - row][col + 4] = sensorReadingsRaw[baseIndex + 48];
        }
    }
}

bool board::storePrevReadingAndCompare()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            tempStorage[i][j] = sensorReadingsGrid[i][j]; // old sensorReadingsGridVal, contains the ORIGINAL POSITION.
        }
    }

    // Reread
    Serial.println("Reading again in 3s:");
    delay(3000);
    readBoard();

    int x = 0;

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (sensorReadingsGrid[i][j] != tempStorage[i][j])
            {
                if (sensorReadingsGrid[i][j] == 'X')
                {
                    coordArray[0] = i;
                    coordArray[1] = j;
                }
                else
                {
                    coordArray[2] = i;
                    coordArray[3] = j;
                }

                // coordArray[x] = 8 - i;
                // coordArray[x + 1] = j + 1;

                Serial.print(coordArray[x]);
                Serial.print(coordArray[x + 1]);
                Serial.print(" to ");

                updateBoard();

                coordArray[0] = 9;
                coordArray[1] = 9;
                coordArray[2] = 9;
                coordArray[3] = 9;

                x += 2;
            }
        }
    }
    return x == 4;
}

void board::updateBoard()
{
    int coords[4] = {coordArray[0], coordArray[1], coordArray[2], coordArray[3]};

    gameBoard[coords[2]][coords[3]] = gameBoard[coords[0]][coords[1]];
    gameBoard[coords[0]][coords[1]] = nullptr;
}

char board::writeSensorReadingsgrid(int pin)
{
    return (analogRead(pin) > 700) ? 'W' : (analogRead(pin) < 300) ? 'B'
                                                                   : 'X';
}

void board::printsensorReadingsGrid() //   Create debug class and put all debug functions in there for readability
{

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Serial.print((sensorReadingsGrid[row][col]));
            Serial.print("\t");
        }
        Serial.println();
    }
}

void board::printBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (gameBoard[i][j] != nullptr)
            {
                Serial.print((char)gameBoard[i][j]->getColor());
                Serial.print((char)gameBoard[i][j]->getType());
                // Serial.print(gameBoard[i][j]->getCoordinates());
                Serial.print("\t");
            }
            else
            {
                Serial.print(char(79));
                Serial.print("\t");
            }
        }
        Serial.println("\n"); // Newline for the next row
    }
}