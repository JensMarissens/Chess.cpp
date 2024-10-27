#include <Arduino.h>
#include "gameLogic.h"
#include "globals.h"


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
  chessboard.readBoard();

  // Copy
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      tempBoard[i][j] = chessboard.debugBoard[i][j]; // old debugBoardVal, contains the ORIGINAL POSITION.
    }
  }

  Serial.println("DebugBoard/Tempboard (copied):");
  chessboard.printDebugBoard();

  // Reread
  Serial.println("Reading again and checking in 3s");
  delay(3000);
  chessboard.readBoard(); // DEBUGBOARD NOW CONTAINS THE NEW POSITION, THE PREVIOUS ONE SHOULD HAVE TURNED TO X

  Serial.println("DebugBoard (uncopied):");
  chessboard.printDebugBoard();

  // Compare White
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessboard.debugBoard[i][j] && tempBoard[i][j] == 'I')
      {
        chesspiece.color = 'I';

        //Serial.println(String(i) + String(j) + ":" + chesspiece.color);
        chesspiece.coordinates[0] = i;
        chesspiece.coordinates[1] = j;

        Serial.println(String(chesspiece.coordinates[1]) + (chesspiece.coordinates[0]) + ":" + chesspiece.color);

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
      if (tempBoard[i][j] != chessboard.debugBoard[i][j] && chessboard.debugBoard[i][j] == 'I')
      {
        chesspiece.coordinates[2] = i;
        chesspiece.coordinates[3] = j;

        Serial.println(String(chesspiece.coordinates[2]) + (chesspiece.coordinates[3]) + ":" + chessboard.debugBoard[i][j]);
        PGNtestString += "W Move number." + pieceType + String(char(j + 97)) + String(7 - i + 1);

        
        moveCount++;
      }
    }
  }

  // Compare Black
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessboard.debugBoard[i][j] && tempBoard[i][j] == 'O')
      {

        Serial.println(String(j) + String(i) + ":" + chessboard.debugBoard[i][j]);
        moveCount++;
      }
    }
  }

  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessboard.debugBoard[i][j] && chessboard.debugBoard[i][j] == 'O') 
      {                                                                                     

        Serial.println(String(i) + String(j) + ":" + chessboard.debugBoard[i][j]);
        PGNtestString += "B Move number." + pieceType + String(char(j + 97)) + String(7 - i + 1);
        moveCount++;
      }
    }
  }

  Serial.println("Result: ");

  if (moveCount > 1)
  { // Emptied and filled to make sure the piece was in the correct starting location. (For movementCheck later).
    turnMove.isValid = true;
    turnMove.PGNnotation = PGNtestString;

    chess_piece.printPieceTest();
  }
  else
  {
    Serial.println("No differences found.");
  }
  return turnMove;
}

/* Eventually the board should probably contain structs with type, color and moveSet that gets moved around as a whole to keep the code sane*/