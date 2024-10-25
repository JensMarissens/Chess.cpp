#include <Arduino.h>
#include "piece.h"

chessPiece cp;

piece::piece(){

}

void piece::printPieceTest() {

    Serial.println("Starting coords:" + String(cp.coordinates[0]) + String(cp.coordinates[1]));
    Serial.println("End coords:" + String(cp.coordinates[2]) + String(cp.coordinates[3]));
}