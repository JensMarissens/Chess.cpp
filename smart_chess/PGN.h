#ifndef pgn_h
#define pgn_h

class PGN
{

public:
    PGN();
    void initPGNArray();
    void writePGNArray(String PGNnotation);
    char* exportPGN();
};

#endif