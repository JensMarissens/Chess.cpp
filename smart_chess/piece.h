#ifndef piece_h
#define piece_h

struct chessPiece{
    char color;
    char type;
    int coordinates[4]={9,9,9,9};
};

class piece {
    public:
    
    piece();
    void printPieceTest();

    chessPiece pieceStruct;
};

#endif