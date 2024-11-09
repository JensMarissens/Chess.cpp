#include <Arduino.h>
#include "../headers/piece.h"
#include "../headers/globals.h"

piece::piece() {}

bool piece::validateMove(int coordinates[4])
{
    // Here and in all subsequent implementations, coordinates contains [x1,y1,x2,y2]. Or old position, new position.
    return false;
}

char piece::getColor()
{
    return color;
}

char piece::getType()
{
    return type;
}

int* piece::getCoordinates() { //I need to pull the appropriate value somehow to assign it
    return coordinates;
}

Rook::Rook(char c, char t, int coordinates[4])
{
    color = c;
    type = t;
    for (int i = 0; i < 4; i++)
    {
        this->coordinates[i] = coordinates[i]; // Initialize coordinates
    }
}

Bishop::Bishop(char c, char t, int coordinates[4])
{
    color = c;
    type = t;
    for (int i = 0; i < 4; i++)
    {
        this->coordinates[i] = coordinates[i]; // Initialize coordinates
    }
}

Knight::Knight(char c, char t, int coordinates[4])
{
    color = c;
    type = t;
    for (int i = 0; i < 4; i++)
    {
        this->coordinates[i] = coordinates[i]; // Initialize coordinates
    }
}

Pawn::Pawn(char c, char t, int coordinates[4])
{
    color = c;
    type = t;
    for (int i = 0; i < 4; i++)
    {
        this->coordinates[i] = coordinates[i]; // Initialize coordinates
    }
}

King::King(char c, char t, int coordinates[4])
{
    color = c;
    type = t;
    for (int i = 0; i < 4; i++)
    {
        this->coordinates[i] = coordinates[i]; // Initialize coordinates
    }
}

Queen::Queen(char c, char t, int coordinates[4])
{
    color = c;
    type = t;
    for (int i = 0; i < 4; i++)
    {
        this->coordinates[i] = coordinates[i]; // Initialize coordinates
    }
}

bool Rook::validateMove(int coordinates[4])
{
    // move in one axis only
    return (coordinates[3] == coordinates[1] && coordinates[2] != coordinates[0]) ||
           (coordinates[2] == coordinates[0] && coordinates[3] != coordinates[1]);
}

bool Bishop::validateMove(int coordinates[4])
{
    // diagonal movements affect x & y similarly
    return (abs(coordinates[3] - coordinates[1]) == abs(coordinates[2] - coordinates[0]));
}

bool Knight::validateMove(int coordinates[4])
{
    // x or y moves 2, the other moves 1. Subtract tha absoluted and 1 remains
    //  abs( abs(coord[0] - coord[2]) - abs(coord[1] - coord[3]) ) == 1

    if (abs(coordinates[3] - coordinates[1]) == 2 && abs(coordinates[2] - coordinates[0]) == 1)
    {
        return true; // up or down 2, over 1
    }
    if (abs(coordinates[2] - coordinates[0]) == 2 && abs(coordinates[3] - coordinates[1]) == 1)
    {
        return true; // up or down 1, over 2
    }
    return false;
}

bool Pawn::validateMove(int coordinates[4])
{
    return (coordinates[2] == coordinates[0] && abs(coordinates[3] - coordinates[1]) == 1);
    // We'll need to add an exception for regular/en passant capture.
    // AND for first move, but that's just a check if(on starting position), allow +2.
}

bool King::validateMove(int coordinates[4])
{
    return (abs(coordinates[3] - coordinates[1]) == 1 && abs(coordinates[2] - coordinates[0]) <= 1) ||
           (abs(coordinates[2] - coordinates[0]) == 1 && abs(coordinates[3] - coordinates[1]) <= 1);
}

bool Queen::validateMove(int coordinates[4])
{
    if ((coordinates[3] == coordinates[1] && coordinates[2] != coordinates[0]) ||
        (coordinates[2] == coordinates[0] && coordinates[3] != coordinates[1]))
    {
        // same check as for rook
        return true;
    }
    if (abs(coordinates[3] - coordinates[1]) == abs(coordinates[2] - coordinates[0]))
    {
        // same check as for bishop
        return true;
    }
    return false;
}

/*--------------------------------------------------To be removed-----------------------------------------------------------------*/

void piece::print(char color, char type, int coordinates[4]) //Currently does nothing
{
    Serial.print(String(color) + String(type) + "(" + coordinates[0] + coordinates[1] + ")\t");
}

void piece::printPieceTest()
{
    Serial.println("Starting coords:" + String(chess_piece.coordinates[1]) + String(chess_piece.coordinates[0]));
    Serial.println("End coords:" + String(chess_piece.coordinates[3]) + String(chess_piece.coordinates[2]));
}
/*--------------------------------------------------End To be removed-----------------------------------------------------------------*/

// ITS ABOUT TIME TO GOT VSCODE WORKING WITH THIS.

// ALSO LOOK INTO WHEN WE HAVE TO DELETE STUFF AND ADDING POINTERS.
