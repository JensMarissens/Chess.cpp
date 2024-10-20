/*#include <Arduino.h>
#include "PGN.h"
#include "board.h"

board chessbrd;

PGN::PGN() {}

void PGN::initPGNArray()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chessbrd.pieceType[i][j] = chessbrd.startCondition[i][j];
            // measurements[i][j] = 0;
            //Serial.println(String(chessbrd.pieceType[i][j]) + "\t");
        }
    }
    Serial.println("initPGNArray");
}
*/