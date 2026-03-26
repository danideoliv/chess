#ifndef BASE_PIECE_H
#define BASE_PIECE_H

#include <iostream>
#include "raylib.h"
#include <memory>

#define PRETO -10
#define BRANCO 10
#define SELECTED -20

#define FREE -1
#define KING 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5

const Color checkColor = {255, 68, 68, 255};

using namespace std;

struct Board;

class Piece {
public:
    int Row;
    int Column;
    int Value;
    int Color;
    int Type;
    bool Moved;
    bool Selected;
    bool Threatened;

    Piece();  // Default constructor
    Piece(int row, int column, int color);

    virtual void possibleSquares(Board board[][8]) = 0;

    void setType(int type);

    void itMoved(bool moved);

    void setValue(int value);
};

struct Board {
    int color;
    std::unique_ptr<Piece> piece; // Use a pointer to enable polymorphism
    string location;
    Color drawColor;
    bool movable;
    bool checked;
};

#endif