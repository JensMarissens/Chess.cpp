#include <Arduino.h>
#include "board.h"

#include "PGN.h"

PGN pgn;

void initBoard()
{

    pgn.initPGNArray();
}

void initDebugBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // pieceType[i][j] = startCondition[i][j]; //Start condition works. But get immedsiately updated cause the game just starts on upload.
            // measurements[i][j] = 0;
        }
    }
}

void readBoard()
{
}
