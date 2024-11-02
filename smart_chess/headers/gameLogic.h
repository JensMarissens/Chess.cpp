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

    registerBoardState();   //update memory to the current state of Piece* array. 
                            //We need this before we can implement the capture mechanic. 
    bool wasItKnight();     //And after check & checkmate
    bool wasItQueen();


    bool didPieceMove();
    bool wasItWhite();
    bool wasItValid();
    void storeMove(bool z);

    void takePiece();

    char tempBoard[8][8];
};

#endif