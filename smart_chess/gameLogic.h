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

    move validMove(char tempBoard[8][8], char debugBoard[8][8], bool whiteFirstFlag);
    move validTurn();
    char tempBoard[8][8];


    //void compareStart();
    //void compareLand();
};

#endif