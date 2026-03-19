#include <iostream>
#include "base_piece.h"

Piece::Piece(int row, int column, int color, Board board[][8]) {
    Row = row;
    Column = column;
    Color = color;
    board[Row][Column].piece_color = color;
}

void Piece::setType(int type) {
    Type = type;
} 

void Piece::itMoved(bool moved) {
    Moved = moved;
} 

void Piece::setValue(int value) {
    Value = value;
}   