#include <Arduino.h>
#include "../headers/piece.h"
#include "../headers/globals.h"

piece::piece()
{
}

bool piece::validateMove(char color, char type, int coordinates[4])
{
    return false;
}

void piece::printPieceTest()
{
    Serial.println("Starting coords:" + String(chess_piece.coordinates[1]) + String(chess_piece.coordinates[0]));
    Serial.println("End coords:" + String(chess_piece.coordinates[3]) + String(chess_piece.coordinates[2]));
}

Rook::Rook()
{
}

bool Rook::validateMove(char color, char type, int coordinates[4])
{

    return (coordinates[3] == coordinates[1] && coordinates[2] != coordinates[0]) || (coordinates[2] == coordinates[0] && coordinates[3] != coordinates[1]);
}

Bishop::Bishop()
{
}

bool Bishop::validateMove(char color, char type, int coordinates[4])
{

    return (abs(coordinates[3] - coordinates[1]) == abs(coordinates[2] - coordinates[0]));
}