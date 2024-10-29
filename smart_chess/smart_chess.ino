#include "headers/globals.h"

gameState gs;
gameLogic glo;

bool startGame = true;  // false;
int EN = 3;

void setup() {
  Serial.begin(19200);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);
}

void loop() {

  if (startGame) {
    //Temp Serial Monitor clear
    for (size_t i = 0; i < 5; i++) {
      Serial.println();
    }

    //gs.startGame();

    bool test = glo.didPieceMove(); //If I make all these functions piece datatype I could just update the parameters?
    bool wasItWhite = glo.wasItWhite();

    if (test) {
      Serial.println("Moved");
    } else {
      Serial.println("Hasn't moved");
    }

    if (wasItWhite) {
      Serial.println("White");
    } else {
      Serial.println("Black");
    }

    glo.storeMove(test && wasItWhite);
  }
}
