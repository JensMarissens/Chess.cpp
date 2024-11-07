#ifndef piece_h
#define piece_h

class piece
{

protected:      // Protected members are accessible within the same class and in any derived (child) class.
    char color;
    char type;  // default on startCondition[8][8], then store to gameBoard
    int coordinates[4] = {9, 9, 9, 9};

public:
    piece();

    virtual bool validateMove(int coordinates[4]);
    void printPieceTest();

    char getColor();
    char getType();

    int *getCoordinates();
    // int getCoordinates();

    /*DELETE*/
    void print(char color, char type, int coordinates[4]);
    /*DELETE*/
};

class Rook : public piece
{
public:
    Rook(char color, char type, int coordinates[4]);
    bool validateMove(int coordinates[4]) override;
};

class Bishop : public piece
{
public:
    Bishop(char color, char type, int coordinates[4]);
    bool validateMove(int coordinates[4]) override;
};

class Knight : public piece
{
public:
    Knight(char color, char type, int coordinates[4]);
    bool validateMove(int coordinates[4]) override;
};

class Pawn : public piece
{
public:
    Pawn(char color, char type, int coordinates[4]);
    bool validateMove(int coordinates[4]) override;
};

class King : public piece
{
public:
    King(char color, char type, int coordinates[4]);
    bool validateMove(int coordinates[4]) override;
};

class Queen : public piece
{
public:
    Queen(char color, char type, int coordinates[4]);
    bool validateMove(int coordinates[4]) override;
};

#endif