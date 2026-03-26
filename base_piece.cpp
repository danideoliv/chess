#include <iostream>
#include "base_piece.h"

Piece::Piece() {
    Row = 0;
    Column = 0;
    Color = 0;
    Value = 0;
    Moved = false;
    Selected = false;
    Threatened = false;
}

Piece::Piece(int row, int column, int color) {
    Row = row;
    Column = column;
    Color = color;
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