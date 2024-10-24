#ifndef pgn_h
#define pgn_h

/*
struct move
  {
    bool isValid = false;
    String PGNnotation;
  };
*/

class PGN
{

public:
    PGN();
    void initPGNArray();
    void writePGNArray(String PGNnotation);
    char* exportPGN();



    //move validMove();
};

#endif