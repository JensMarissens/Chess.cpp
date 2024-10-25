#include <Arduino.h>
#include "gameLogic.h"
#include "board.h"

#include "piece.h"
chessPiece chesspiece;
piece chp;

board chessbrd;

gameLogic::gameLogic() {}

move gameLogic::validMove()
{
  move turnMove;
  String PGNtestString; // Rename

  int moveCount = 0;
  String pieceType = "N"; // Replace with actual piece type

  // Read
  Serial.println("Reading and assigning in 3s");
  delay(3000);
  chessbrd.readBoard();

  // Copy
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      tempBoard[i][j] = chessbrd.debugBoard[i][j]; // old debugBoardVal, contains the ORIGINAL POSITION.
    }
  }

  Serial.println("DebugBoard/Tempboard (copied):");
  chessbrd.printDebugBoard();

  // Reread
  Serial.println("Reading again and checking in 3s");
  delay(3000);
  chessbrd.readBoard(); // DEBUGBOARD NOW CONTAINS THE NEW POSITION, THE PREVIOUS ONE SHOULD HAVE TURNED TO X

  Serial.println("DebugBoard (uncopied):");
  chessbrd.printDebugBoard();

  // Compare White
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessbrd.debugBoard[i][j] && tempBoard[i][j] == 'I')
      {
        chesspiece.color = 'I';

        Serial.println(String(i) + String(j) + ":" + chesspiece.color);
        //PGNtestString = "W Start pos." + pieceType + String(char(j + 97)) + String(7 - i + 1);
        chesspiece.coordinates[0] = i;
        chesspiece.coordinates[1] = j;
        moveCount++;
      }
    }
    // Per move I then O. concat, store in
    // String, push to array.
  }

  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessbrd.debugBoard[i][j] && chessbrd.debugBoard[i][j] == 'I')
      {

        Serial.println(String(i) + String(j) + ":" + chessbrd.debugBoard[i][j]);
        PGNtestString += "\tW Move number." + pieceType + String(char(j + 97)) + String(7 - i + 1);

        chesspiece.coordinates[2] = i;
        chesspiece.coordinates[3] = j;
        moveCount++;
      }
    }
    // Per move I then O. concat, store in
    // String, push to array.
  }

  // Compare Black
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessbrd.debugBoard[i][j] && tempBoard[i][j] == 'O')
      {

        Serial.println(String(i) + String(j) + ":" + chessbrd.debugBoard[i][j]);
        //PGNtestString = "B Start pos." + pieceType + String(char(j + 97)) + String(7 - i + 1);
        moveCount++;
      }
    }
    // Per move I then O. concat, store in
    // String, push to array.
  }

  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessbrd.debugBoard[i][j] && chessbrd.debugBoard[i][j] == 'O') 
      {                                                                                     

        Serial.println(String(i) + String(j) + ":" + chessbrd.debugBoard[i][j]);
        PGNtestString += "\tB Move number." + pieceType + String(char(j + 97)) + String(7 - i + 1);
        moveCount++;
      }
    }
  }

  Serial.print("Result: ");

  if (moveCount > 1)
  { // Emptied and filled to make sure the piece was inthe correct starting location. (For movementCheck later).
    turnMove.isValid = true;
    turnMove.PGNnotation = PGNtestString;

    chp.printPieceTest();
  }
  else
  {
    Serial.println("No differences found.");
  }
  return turnMove;
}

/* Eventually the board should probably contain structs with type, color and moveSetq that gets moved around as a whole to keep the code sane*/