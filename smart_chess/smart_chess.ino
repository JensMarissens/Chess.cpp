#include "PGN.h"
#include "gameState.h"

gameState gs;

bool startGame = false;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  if (startGame)
  {
    gs.startGame();
  }
  
}
