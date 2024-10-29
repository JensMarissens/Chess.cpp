#ifndef piece_h
#define piece_h

class piece
{
public:
    piece();

    char color;
    char type;
    int coordinates[4] = {9, 9, 9, 9};

    void printPieceTest();

    void updatePiece(char color, char type, int coordinates[4])
    {
        this->color = color;
        this->type = type;
        for (int i = 0; i < 4; i++)
        {
            this->coordinates[i] = coordinates[i];
        }
    }
};

#endif