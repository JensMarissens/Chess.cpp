#include <Arduino.h>
#include "../headers/gameLogic.h"
#include "../headers/globals.h"

gameLogic::gameLogic() {}

// placeholder vars
char color = 'X';
char type = 'N';
int coordArray[4];
int turn = 1;
piece* (*logicBoard)[8][8];

// Knight knight;
// Queen queen;
// Rook rook;

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
      if (currentPiece->getColor() == chessboard.debugBoard[i][j] ||
          currentPiece == nullptr && chessboard.debugBoard[i][j] == 'X')
      {
        passFlag++;
      }
    }
  }

  Serial.println("Passflag: " + String(passFlag));
  // return passFlag == 64;
  return passFlag == 32;

  //return chessboard.startConditionValidFlag();
}

bool gameLogic::didPieceMove()
{

  // Read
  chessboard.readBoard();

  // Copy
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      tempBoard[i][j] = chessboard.debugBoard[i][j]; // old debugBoardVal, contains the ORIGINAL POSITION.
    }
  }

  // Reread
  Serial.println("Reading again in 3s:");
  delay(3000);
  chessboard.readBoard();

  int x = 0;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (chessboard.debugBoard[i][j] != tempBoard[i][j])
      {
        coordArray[x] = i + 1;
        coordArray[x + 1] = 8 - j;

        Serial.print(String(coordArray[x]) + String(coordArray[x + 1]) + " ");
        x += 2;

        // color
      }
    }
  }
  return x == 4;
}

bool wasItWHite()
{
}

void gameLogic::storeMove(bool isValid)
{
  pgn.writePGNArray(String(turn) + ". " + String(type) + "r9");
  turn++;
}

void gameLogic::gameRound() // does nothing so far
{
  bool moved;
  bool wasWhite;

  bool whitePlayed = false;

  moved = didPieceMove();

  Serial.println(moved ? "Moved" : "Didn't move");
  // wasWhite = wasItWhite();
}