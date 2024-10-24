#include <Arduino.h>
#include "PGN.h"
#include "board.h"

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
    
    test = "";

    //Temp Serial Monitor clear
    for (size_t i = 0; i < 10; i++)
    {
      Serial.println();
    }
}