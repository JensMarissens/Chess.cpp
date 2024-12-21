#include <Arduino.h>
#include "../headers/debug.h"

debug::debug(){}


void debug::printBoard(/*so string converted parameter we want to print*/) //   Create debug class and put all debug functions in there for readability
{

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            //passed parameter we want to print
            Serial.print("\t");
        }
        Serial.println();
    }
    Serial.println("----------------------------------------------------------");
}


//Make 1 print function with a parameter to specify which one. sensorReadingsGrid/tempStorage/gameBoard.. and resolve the logic in here seperately