#ifndef piece_h
#define piece_h

class piece
{
public:
    piece();

    char color;
    char type;
    int coordinates[4] = {9, 9, 9, 9};

    int validMove[2];

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

#endif