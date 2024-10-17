#ifndef pgn_h
#define pgn_h

class PGN
{

public:
    PGN();

private:
    void initPGNArray();
    void writePGNArray();
    String exportPGN();
};

#endif