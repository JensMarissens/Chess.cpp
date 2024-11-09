#ifndef board_h
#define board_

#include "piece.h"

class board
{
protected:

  uint8_t S0;
  uint8_t S1;
  uint8_t S2;
  uint8_t S3;
  char boardReadings[64];

public:
  board();

  piece *gameBoard[8][8]; // Get this shit implemnted.

  char startCondition[8][8] = {
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'E', 'E', 'E', 'E', 'E', 'E', 'E', 'E'},
      {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
      {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

  void initBoard();
  void readBoard();
  bool storePrevReadingsAndCompareNew();


  char writeBoard(int reading);

  piece* (*getBoard())[8][8];


  void printBoard();

  /*DEBUG FUNCTIONS PARAMS*/
  char sensorGridArray[8][8];
  char tempSensorReadings[8][8];
  /*END DEBUG FUNCTIONS PARAMS*/

  /*DEBUG FUNCTIONS VARS*/
  void initsensorGridArray();
  void printSensorGridArray();
  /*END DEBUG FUNCTIONS VARS*/
};

#endif