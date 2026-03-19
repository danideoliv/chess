#include <iostream>
#include "pieces.h"

King::King(int row, int column, int color, Board board[][8]) : Piece(row, column, color, board) {
    setType(KING);
    board[Row][Column].piece = KING;
    itMoved(false);
    setValue(0);
}

void King::possibleSquares(string matrix[][8]) {
    int kingY = Row;
    int kingX = Column;

    bool kingUp = false;
    bool kingRight = false;
    bool kingDown = false;
    bool kingLeft = false;
    
    if (kingY - 1 >= 0) {
        kingUp = true;
        matrix[kingY - 1][kingX] = "■ ";
    } 

    if (kingX + 1 <= 7) {
        kingRight = true;
        matrix[kingY][kingX + 1] = "■ ";
    }

    if (kingY + 1 <= 7) {
        kingDown = true;
        matrix[kingY + 1][kingX] = "■ ";
    } 

    if (kingX - 1>= 0) {
        kingLeft = true;
        matrix[kingY][kingX - 1] = "■ ";
    }

    if (kingUp == true && kingRight == true)  {
        matrix[kingY - 1][kingX + 1] = "■ ";
    }

    if (kingRight == true && kingDown == true)  {
        matrix[kingY + 1][kingX + 1] = "■ ";
    }

    if (kingDown == true && kingLeft == true)  {
        matrix[kingY + 1][kingX - 1] = "■ ";
    }

    if (kingLeft == true && kingUp == true)  {
        matrix[kingY - 1][kingX - 1] = "■ ";
    }
}