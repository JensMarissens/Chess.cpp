#include <Arduino.h>
#include "piece.h"
#include "globals.h"

piece::piece(){
}

void piece::printPieceTest() {
    Serial.println("Starting coords:" + String(chess_piece.coordinates[1]) + String(chess_piece.coordinates[0]));
    Serial.println("End coords:" + String(chess_piece.coordinates[3]) + String(chess_piece.coordinates[2]));
}