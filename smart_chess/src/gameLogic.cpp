#include <Arduino.h>
#include "../headers/gameLogic.h"
#include "../headers/globals.h"

gameLogic::gameLogic() {}

// placeholder vars
char type = 'N';
int coordArray[4];
int turn = 1;
piece* (*logicBoard)[8][8];

bool gameLogic::startConditionValidFlag()
{
  int passFlag = 0;
  chessboard.readBoard();

  piece* (*boardPointer)[8][8] = chessboard.getBoard();


  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      piece* currentPiece = (*boardPointer)[i][j];
      if (currentPiece->getColor() == chessboard.sensorReadingsGrid[i][j] ||
          currentPiece == nullptr && chessboard.sensorReadingsGrid[i][j] == 'X')
      {
        passFlag++;
      }
    }
  }

  Serial.println("Passflag: " + String(passFlag));
  // return passFlag == 64;
  return passFlag == 32;
}

bool gameLogic::didPieceMove()
{

  chessboard.readBoard();
  bool moved = chessboard.storePrevReadingAndCompare();
  
  return moved;
}

bool gameLogic::wasItWite()
{
  bool white = false;

  return white;
}

void gameLogic::storeMove(bool isValid)
{
  pgn.writePGNArray(String(turn) + ". " + String(type) + "r9");
  turn++;
}

void gameLogic::gameRound() // does nothing so far
{
  bool moved;
  bool white;

  bool whitePlayed = false;

  moved = didPieceMove();
  white = wasItWhite();

  Serial.print(white ? "White " : "Black ");
  Serial.println(moved ? "moved" : " didn't move");
}