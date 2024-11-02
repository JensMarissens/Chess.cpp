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
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, 
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}  
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