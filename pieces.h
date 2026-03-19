#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include "base_piece.h"

using namespace std;

#define BLACK -10
#define WHITE 10

#define FREE -1
#define KING 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5

class King: public Piece {
public:
    King(int row, int column, int color, Board board[][8]);

    void possibleSquares(string matrix[][8]);
};

class Pawn: public Piece {
public:
    Pawn(int row, int column, int color, Board board[][8]);

    void possibleSquares(string matrix[][8], Board matrix2[][8]);
};

class Bishop: public Piece {
public:
    Bishop(int row, int column, int color, Board board[][8]);

    void possibleSquares(string matrix[][8], Board matrix2[][8]);
};

class Knight: public Piece {
public:
    Knight(int row, int column, int color, Board board[][8]);

    void possibleSquares(string matrix[][8], Board matrix2[][8]);
};

class Rook: public Piece {
public:
    Rook(int row, int column, int color, Board board[][8]);

    void possibleSquares(string matrix[][8], Board matrix2[][8]);
};

class Queen: public Piece {
public:
    Queen(int row, int column, int color, Board board[][8]);

    void possibleSquares(string matrix[][8], Board matrix2[][8]);
};

#endif