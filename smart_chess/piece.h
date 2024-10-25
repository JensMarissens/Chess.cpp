#ifndef piece_h
#define piece_h

struct chessPiece{
    char color;
    char type;
    int coordinates[2][2];
};

class piece {
    public:
    piece();

    void printPieceTest();
};

#endif