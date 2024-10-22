#ifndef gameLogic_h
#define gameLogic_h

class gameLogic
{

public:
    gameLogic();
    
    bool validMove();

    char prevArr[8][8];
    char arr[8][8];
};

#endif