#ifndef board_h
#define board_h

class board
{

public:
    board();
    
    void readBoard();

private:
    void initBoard();
    void initDebugBoard();
};

#endif