#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include "base_piece.h"

using namespace std;

class King: public Piece {
public:
    King(int row, int column, int color);

    void possibleSquares(Board matrix[][8]) override;
};

class Pawn: public Piece {
public:
    Pawn(int row, int column, int color);

    void possibleSquares(Board matrix[][8]) override;
};

class Bishop: public Piece {
public:
    Bishop(int row, int column, int color);

    void possibleSquares(Board matrix[][8]) override;
};

class Knight: public Piece {
public:
    Knight(int row, int column, int color);

    void possibleSquares(Board matrix[][8]) override;
};

class Rook: public Piece {
public:
    Rook(int row, int column, int color);

    void possibleSquares(Board matrix[][8]) override;
};

class Queen: public Piece {
public:
    Queen(int row, int column, int color);

    void possibleSquares(Board matrix[][8]) override;
};

#endif