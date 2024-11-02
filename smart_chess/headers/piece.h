#ifndef piece_h
#define piece_h

class piece
{
public:
    piece();

    char color;
    char type; //default on startCondition[8][8], then store to gameBoard
    int coordinates[4] = {9, 9, 9, 9};

    virtual bool validateMove(char color, char type, int coordinates[4]);
    void printPieceTest();
};

class Rook : public piece
{
public:
    Rook();
    bool validateMove(char color, char type, int coordinates[4]) override;
};

class Bishop : public piece
{
public:
    Bishop();
    bool validateMove(char color, char type, int coordinates[4]) override;
};

class Knight : public piece
{
public:
    Knight();
    bool validateMove(char color, char type, int coordinates[4]) override;
};

class Pawn : public piece
{
public:
    Pawn();
    bool validateMove(char color, char type, int coordinates[4]) override;
}

class King : public piece
{
public:
    King();
    bool validateMove(char color, char type, int coordinates[4]) override;
}

class Queen : public piece
{
public:
    Queen();
    bool validateMove(char color, char type, int coordinates[4]) override;
}

#endif