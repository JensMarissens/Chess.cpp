#include <Arduino.h>
#include "PGN.h"
#include "gameState.h"

gameState gs;

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
}

void loop()
{

  if (startGame)
  {
    Serial.println("Starting game");
    gs.startGame();
    Serial.println("Game ended");
  }
}
