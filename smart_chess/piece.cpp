#include <Arduino.h>
#include "piece.h"
#include "globals.h"

piece::piece(){
}

void piece::printPieceTest() {
    Serial.println("Starting coords:" + String(chesspiece.coordinates[1]) + String(chesspiece.coordinates[0]));
    Serial.println("End coords:" + String(chesspiece.coordinates[3]) + String(chesspiece.coordinates[2]));
}