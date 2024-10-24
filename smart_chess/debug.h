#ifndef debug_h
#define debug_h

class debug
{

public:
    debug();

    void initDebugBoard();
    void printDebugBoard();
    
    char debugBoard[8][8];
};

#endif