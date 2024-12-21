#ifndef board_h
#define board_

#include "piece.h"

class board
{

private:
  uint8_t S0;
  uint8_t S1;
  uint8_t S2;
  uint8_t S3;
  char sensorReadingsRaw[64];

public:
  board();

  piece *gameBoard[8][8]; 

  void initBoard();
  void readBoard();
  bool storePrevReadingAndCompare();
  void updateBoard();

  char writeSensorReadingsgrid(int reading);

  piece *(*getBoard())[8][8]; //??

  void printBoard();

  /*DEBUG FUNCTIONS PARAMS*/
  char sensorReadingsGrid[8][8];
  char tempStorage[8][8];
  int coordArray[4];
  /*END DEBUG FUNCTIONS PARAMS*/

  /*DEBUG FUNCTIONS VARS*/
  void initsensorReadingsGrid();
  void printsensorReadingsGrid();
  /*END DEBUG FUNCTIONS VARS*/
};

#endif