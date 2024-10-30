#ifndef gameLogic_h
#define gameLogic_h

struct move
{
    bool isValid = false;
    String PGNnotation;
};

class gameLogic
{

public:
    gameLogic();

    bool wasItRook();
    bool wasItBishop();


    bool didPieceMove();
    bool wasItWhite();
    bool wasItValid();
    void storeMove(bool z);

    char tempBoard[8][8];
};

#endif