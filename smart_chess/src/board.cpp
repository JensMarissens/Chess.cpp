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
    initsensorGridArray();
    initBoard();
}

void board::initsensorGridArray()
{
    // Serial.println("Initializing Debug Array");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            sensorGridArray[i][j] = 'X';
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

    Serial.println("getBoard exectued");
    return gameBoard;  // Return the entire 2D array
}*/
void board::getBoard();

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

            sensorGridArray[3 - row][col] = boardReadings[baseIndex];
            sensorGridArray[3 - row][col + 4] = boardReadings[baseIndex + 16];
            sensorGridArray[7 - row][col] = boardReadings[baseIndex + 32];
            sensorGridArray[7 - row][col + 4] = boardReadings[baseIndex + 48];
        }
    }
}

bool board::storePrevReadingsAndCompareNew()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            tempSensorReadings[i][j] = sensorGridArray[i][j]; // old sensorGridArrayVal, contains the ORIGINAL POSITION.
        }
    }

    Serial.println("Reading again in 3s:");
    delay(3000);
    readBoard();

    int alteredTileCount = 0;

    for (int i = 0; i < 8; i++) // can we not make this a board function?
    {
        for (int j = 0; j < 8; j++)
        {
            if (sensorGridArray[i][j] != tempSensorReadings[i][j])
            {
                alteredTileCount++;
            }
        }
    }
    return alteredTileCount == 2;
}

char board::writeBoard(int pin)
{
    return (analogRead(pin) > 700) ? 'W' : (analogRead(pin) < 300) ? 'B'
                                                                   : 'X';
}

void board::printSensorGridArray() //   Create debug class and put all debug functions in there for readability
{

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            Serial.print((sensorGridArray[row][col]));
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
                Serial.print((char)gameBoard[i][j]->getColor());
                Serial.print((char)gameBoard[i][j]->getType());

                int *coo;
                coo = gameBoard[i][j]->getCoordinates();

                for (size_t i = 0; i < 2; i++)
                {
                    Serial.print(String(coo[i]));
                }

                Serial.print("\t");
            }
            else
            {
                Serial.print(char(254));
                Serial.print("\t");
            }
        }
        Serial.println("\n"); // Newline for the next row
    }
}

bool board::startConditionValidFlag()
{
    int passFlag = 0;
    

    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if (gameBoard[i][j]->getColor() == debugBoard[i][j])
            {
                passFlag++;
            }
        }
    }

    Serial.println("Passflag: " + String(passFlag));
    return passFlag == 63;
}