#ifndef piece_h
#define piece_h

struct chessPiece{
    char color;
    char type;
    int coordinates[4]={1,1,1,1};
};

class piece {
    public:
    piece();

    void printPieceTest();
};

#endif