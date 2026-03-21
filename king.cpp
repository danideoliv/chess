#include <iostream>
#include "pieces.h"

King::King(int row, int column, int color) : Piece(row, column, color) {
    setType(KING);
    itMoved(false);
    setValue(0);
}

void King::possibleSquares(Board matrix[][8]) {
    int kingY = Row;
    int kingX = Column;

    auto isEmpty = [&](int row, int column) {
        return matrix[row][column].piece == nullptr;
    };

    bool kingUp = false;
    bool kingRight = false;
    bool kingDown = false;
    bool kingLeft = false;
    
    if (kingY - 1 >= 0 && isEmpty(kingY - 1, kingX)) {
        matrix[kingY - 1][kingX].movable = true;
    } 

    if (kingX + 1 <= 7 && isEmpty(kingY, kingX + 1)) {
        matrix[kingY][kingX + 1].movable = true;
    }

    if (kingY + 1 <= 7 && isEmpty(kingY + 1, kingX)) {
        matrix[kingY + 1][kingX].movable = true;
    } 

    if (kingX - 1>= 0 && isEmpty(kingY, kingX - 1)) {
        matrix[kingY][kingX - 1].movable = true;
    }

    if (kingY - 1 >= 0 && kingX + 1 <= 7 && isEmpty(kingY - 1, kingX + 1))  {
        matrix[kingY - 1][kingX + 1].movable = true;
    }

    if (kingX + 1 <= 7 && kingY + 1 <= 7 && isEmpty(kingY + 1, kingX + 1))  {
        matrix[kingY + 1][kingX + 1].movable = true;
    }

    if (kingY + 1 <= 7 && kingX - 1>= 0 && isEmpty(kingY + 1, kingX - 1))  {
        matrix[kingY + 1][kingX - 1].movable = true;
    }

    if (kingX - 1>= 0 && kingY - 1 >= 0 && isEmpty(kingY - 1, kingX - 1))  {
        matrix[kingY - 1][kingX - 1].movable = true;
    }
}