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
                            //And after check & checkmate


    bool startConditionValidFlag();

    bool didPieceMove();
    bool wasItWhite();

    bool wasMoveValid();
    void storeMove(bool z);

    void takePiece();
};

#endif