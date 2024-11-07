#include <Arduino.h>
#include "../headers/gameLogic.h"
#include "../headers/globals.h"

gameLogic::gameLogic() {}

// placeholder vars
char color = 'X';
char type = 'N';
int coordArray[4];
int turn = 1;

// Knight knight;
// Queen queen;
// Rook rook;

bool gameLogic::startConditionValidFlag()
{
  //chessboard.getBoard();
  return true;
}

bool gameLogic::didPieceMove()
{
  int moveCount = 0;

  // Read
  chessboard.initBoard();

  chessboard.readBoard();
  chessboard.printDebugBoard();

  // Copy
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      tempBoard[i][j] = chessboard.debugBoard[i][j]; // old debugBoardVal, contains the ORIGINAL POSITION.
    }
  }

  // Reread
  Serial.println("Reading in 3s:");
  delay(3000);
  chessboard.readBoard();
  chessboard.printDebugBoard();

  int x = 0;

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (chessboard.debugBoard[i][j] != tempBoard[i][j])
      {
        coordArray[x] = i + 1;
        coordArray[x + 1] = 8 - j;

        Serial.print(coordArray[x]);
        Serial.println(coordArray[x + 1]);

        color = chessboard.debugBoard[i][j]; // It's always assigning the last read square. So doesn't work.
        moveCount++;
        x += 2;
      }
    }
  }
}

void gameLogic::storeMove(bool isValid)
{
  pgn.writePGNArray(String(turn) + ". " + String(type) + "r9");
  turn++;
}

void gameRound() // does nothing so far
{
  gameLogic logic; // Create an instance of gameLogic
  bool whitePlayed = false;

  bool moved = logic.didPieceMove();
  bool isWhite = logic.wasItWhite();
}