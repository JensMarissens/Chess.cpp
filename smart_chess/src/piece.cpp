#include <Arduino.h>
#include "../headers/piece.h"
#include "../headers/globals.h"

piece::piece()
{
}

Rook::Rook()
{
}

Bishop::Bishop()
{
}

Knight::Knight()
{
}

Pawn::Pawn()
{
}

King::King()
{
}

Queen::Queen()
{
}

bool piece::validateMove(char color, char type, int coordinates[4])
{ // Here and in all subsequent implementations, coordinates contains [x1,y1,x2,y2]. Or old position, new position.
    return false;
}

bool Rook::validateMove(char color, char type, int coordinates[4])
{ // move in one axis only
    return (coordinates[3] == coordinates[1] && coordinates[2] != coordinates[0]) || (coordinates[2] == coordinates[0] && coordinates[3] != coordinates[1]);
}

bool Bishop::validateMove(char color, char type, int coordinates[4])
{ // diagonal movements affect x & y similarly
    return (abs(coordinates[3] - coordinates[1]) == abs(coordinates[2] - coordinates[0]));
}

bool Knight::validateMove(char color, char type, int coordinates[4])
{

    if (abs(coordinates[3] - coordinates[1] == 2) && abs(coordinates[2] - coordinates[0]) == 1)
    { // up or down 2, over 1
        return true;
    }

    if (abs(coordinates[2] - coordinates[0] == 2) && abs(coordinates[3] - coordinates[1]) == 1)
    { // up or down 1, over 2
        return true;
    }
    return false;
}

bool Pawn::validateMove(char color, char type, int coordinates[4])
{ // only up 1
    return (abs(coordinates[3] - coordinates[1] == 1) && (coordinates[2] == coordinates[0]));
    // We'll need to add an exception for regular/en passant capture.
    // AND for first move, but that's just a check if(on starting position), allow +2.
}

bool King::validateMove(char color, char type, int coordinates[4])
{ // any direction but only 1 tile
    return (abs(coordinates[3] - coordinates[1] == 1) && abs(coordinates[2] == coordinates[0] == 1));
}

bool Queen::validateMove(char color, char type, int coordinates[4])
{
    if ((coordinates[3] == coordinates[1] && coordinates[2] != coordinates[0]) || (coordinates[2] == coordinates[0] && coordinates[3] != coordinates[1]))
    { // same check as for rook
        return true;
    }

    if (abs(coordinates[3] - coordinates[1]) == abs(coordinates[2] - coordinates[0]))
    { // same check as for bishop
        return true;
    }
    return false;
}

/*--------------------------------------------------To be removed-----------------------------------------------------------------*/
void piece::printPieceTest()
{
    Serial.println("Starting coords:" + String(chess_piece.coordinates[1]) + String(chess_piece.coordinates[0]));
    Serial.println("End coords:" + String(chess_piece.coordinates[3]) + String(chess_piece.coordinates[2]));
}
/*--------------------------------------------------End To be removed-----------------------------------------------------------------*/

// ITS ABOUT TIME TO GOT VSCODE WORKING WITH THIS.

// ALSO LOOK INTO WHEN WE HAVE TO DELETE STUFF AND ADDING POINTERS.
