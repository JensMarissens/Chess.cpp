#include "Arduino.h"
#include "headers/globals.h"

gameState gs;
gameLogic glo;

bool startGame = true; // false;
int EN = 3;

void setup()
{
  Serial.begin(19200);

  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);

  chessboard.initBoard();
}

void loop()
{

  if (startGame)
  {
    // Temp Serial Monitor clear
    for (size_t i = 0; i < 5; i++)
    {
      Serial.println();
    }

    chessboard.printBoard();
    delay(2000);

    /*


        //gs.startGame();

        bool test = glo.didPieceMove();
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

        bool knight = glo.wasItKnight();
        bool queen = glo.wasItQueen();

        Serial.println(knight ? "knight" : "knight");
        Serial.println(queen ? "queen" : "queen");*/
  }
}
