#include <Arduino.h>
#include "gameLogic.h"
#include "board.h"

board chessbrd;

gameLogic::gameLogic() {}

move gameLogic::validMove() {
  move turnMove;
  String test;  // Rename

  //bool emptied = false;
  //bool filled = false;
  int moveCount = 0;
  String pieceType = "N";  // Replace with actual piece type

  Serial.println("Reading and assigning in 3s");
  delay(3000);
  chessbrd.readBoard();

  // Copy the debugBoard to tempBoard
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      chessbrd.tempBoard[i][j] = chessbrd.debugBoard[i][j];
    }
  }

  chessbrd.printDebugBoard();

  Serial.println("Reading again and checking in 3s");
  delay(3000);
  chessbrd.readBoard();

  // Check for differences
  for (size_t i = 0; i < 8; i++) {
    for (size_t j = 0; j < 8; j++) {
      if (chessbrd.debugBoard[i][j] != 'X') { //Record the tile that got filled.
        test = "Move number." + pieceType + String(char(j + 97)) + String(7 - i + 1); 
        moveCount++;
      }
    }//extra check for piece color. Per 
// move I then O. concat, store in 
// String, push to array.
  }

  chessbrd.printDebugBoard();

  Serial.print("Result: ");

  if (moveCount > 1) { //Emptied and filled to make sure the piece was inthe correct starting location. (For movementCheck later).
    turnMove.isValid = true;
    turnMove.PGNnotation = test;
  } else {
    Serial.println("No differences found.");
  }
  return turnMove;
}

/* Eventually the board should probably contain structs with type, color and moveSetq that gets moved around as a whole to keep the code sane*/