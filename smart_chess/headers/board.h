#ifndef board_h
#define board_

#include "piece.h"

class board
{

public:
  board();

  void readBoard();
  char writeBoard(int reading);

  piece* gameboard[8][8];

  char startCondition[8][8] = {
      {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, // Black
      {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, // Black
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, // White
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}  // White
  };

  /*DEBUG FUNCTIONS VARS*/
  void initDebugBoard();
  void printDebugBoard();
  char debugBoard[8][8];
  /*END DEBUG FUNCTIONS VARS*/

  /*HARDWARE VARIABLES*/
  uint8_t S0;
  uint8_t S1;
  uint8_t S2;
  uint8_t S3;
  char boardReadings[64];
  /*END HARDWARE VARIABLES*/
};

#endif