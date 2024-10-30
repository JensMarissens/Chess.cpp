#include <Arduino.h>
#include "../headers/gameLogic.h"
#include "../headers/globals.h"

gameLogic::gameLogic() {}

// placeholder vars
char color = 'X';
char type = 'N';
int coordArray[4];
int turn = 1;

Rook rook;
Bishop bishop;

bool gameLogic::didPieceMove()
{
  int moveCount = 0;

  // Read
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

bool gameLogic::wasItWhite()
{
  return color == 'I';
}

bool gameLogic::wasItValid()
{
  // Implement your logic here
  return true; // Placeholder value
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
  bool isValid;

  if (moved && isWhite) // does nothing so far
  {
    isValid = logic.wasItValid(); // Check if the move is valid

    logic.storeMove(isValid); // Store the move

    whitePlayed = true;
    turn++;
  }

  if (moved && whitePlayed) // does nothing so far
  {
    logic.storeMove(isValid); // Store the move again

    whitePlayed = false;
    turn++;
  }
}

bool gameLogic::whatMovementType()
{
  
  
}

bool gameLogic::wasItRook()
{
  return rook.validateMove('I', 'R', coordArray);
}

bool gameLogic::wasItBishop()
{
  return bishop.validateMove('I', 'R', coordArray);
}

/*
move gameLogic::validMove(char tempBoard[8][8], char debugBoard[8][8], bool whiteFirstFlag) // RUNS TWICE
{
  move _move;

  // Compare
  compareStart(tempBoard, debugBoard, whiteFirstFlag);
  compareLand(tempBoard, debugBoard, whiteFirstFlag);

  Serial.println("Result: ");

  if (moveCount > 1)
  { // Emptied and filled to make sure the piece was in the correct starting location. (For movementCheck later).
    _move.isValid = true;
    _move.PGNnotation = PGNtestString;

    chess_piece.printrook();
  }
  else
  {
    Serial.println("No differences found.");
  }
  return _move;
}

move gameLogic::validTurn() // RUNS ONCE, First a white has to move, then a black piece
{
  move test;

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
  chessboard.readBoard();

  Serial.println("DebugBoard (uncopied):");
  chessboard.printDebugBoard();

  // Validate move (and order)
  move currMove = validMove(tempBoard, chessboard.debugBoard, false);

  if (currMove.isValid)
  {

    test.PGNnotation = "Qe2";

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
    chessboard.readBoard();

    Serial.println("DebugBoard (uncopied):");
    chessboard.printDebugBoard();

    Serial.println("Please: " + test.PGNnotation);

    currMove = validMove(tempBoard, chessboard.debugBoard, true);

    test.PGNnotation += " Qd2";

    Serial.println("Please: " + test.PGNnotation);
  };
}

// Eventually the board should probably contain structs with type, color and moveSet that gets moved around as a whole to keep the code sane

void gameLogic::compareStart(char tempBoard[8][8], char debugBoard[8][8], bool whiteFirstFlag)
{
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessboard.debugBoard[i][j] && tempBoard[i][j] == 'I') // Check if piece is white
      {
        chesspiece.color = 'I';
        chesspiece.coordinates[0] = i;
        chesspiece.coordinates[1] = j;
        moveCount++;
      }
      else if (tempBoard[i][j] != chessboard.debugBoard[i][j] && tempBoard[i][j] == 'O' && whiteFirstFlag == true) // Check if white piece has been read
      {
        chesspiece.color = 'O';
        chesspiece.coordinates[0] = i;
        chesspiece.coordinates[1] = j;
        moveCount++;
      }
    }
  }
}
void gameLogic::compareLand(char tempBoard[8][8], char debugBoard[8][8], bool whiteFirstFlag)
{
  for (size_t i = 0; i < 8; i++)
  {
    for (size_t j = 0; j < 8; j++)
    {
      if (tempBoard[i][j] != chessboard.debugBoard[i][j] && chessboard.debugBoard[i][j] == 'I') // Read landing position
      {
        chesspiece.coordinates[2] = i;
        chesspiece.coordinates[3] = j;

        PGNtestString += "W Move number." + pieceType + String(char(j + 97)) + String(7 - i + 1);
        moveCount++;
      }
      else if (tempBoard[i][j] != chessboard.debugBoard[i][j] && chessboard.debugBoard[i][j] == 'O' && whiteFirstFlag == true) // Read landing position
      {
        chesspiece.coordinates[2] = i;
        chesspiece.coordinates[3] = j;

        PGNtestString += "B Move number." + pieceType + String(char(j + 97)) + String(7 - i + 1);
        moveCount++;
      }
    }
  }
}

*/