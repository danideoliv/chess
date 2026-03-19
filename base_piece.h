#ifndef BASE_PIECE_H
#define BASE_PIECE_H

#include <iostream>

using namespace std;

struct Board {
    int color;
    int piece;
    int piece_color;
    string location;
};

class Piece {
public:
    int Row;
    int Column;
    int Value;
    int Color;
    int Type;
    bool Moved;

    Piece(int row, int column, int color, Board board[][8]);

    void setType(int type);

    void itMoved(bool moved);

    void setValue(int value);
};

#endif