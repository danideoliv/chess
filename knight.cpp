#include <iostream>
#include "pieces.h"

Knight::Knight(int row, int column, int color) : Piece(row, column, color) {
    setType(KNIGHT);
    itMoved(false);
    setValue(3);
}

void Knight::possibleSquares(Board matrix[][8]) {
    int knightX = Column;
    int knightY = Row;

    auto isEmpty = [&](int row, int column) {
        return matrix[row][column].piece == nullptr;
    };

    auto hasEnemyPiece = [&](int row, int column) {
        return matrix[row][column].piece != nullptr && Color != matrix[row][column].piece->Color;
    };

    // UP SIDE
    
    if (knightY - 2 >= 0) {
        if (knightX - 1 >= 0) {
            if (hasEnemyPiece(knightY - 2, knightX - 1)) {
                matrix[knightY - 2][knightX - 1].piece->Threatened = true;

            } else if (isEmpty(knightY - 2, knightX - 1)) {
                matrix[knightY - 2][knightX - 1].movable = true;
            }
        }

        if (knightX + 1 <= 7) {
            if (hasEnemyPiece(knightY - 2, knightX + 1)) {
                matrix[knightY - 2][knightX + 1].piece->Threatened = true;
            } else if (isEmpty(knightY - 2, knightX + 1)) {
                matrix[knightY - 2][knightX + 1].movable = true;
            }
        }
    }

    // RIGHT SIDE
    
    if (knightX + 2 <= 7) {
        if (knightY - 1 >= 0) {
            if (hasEnemyPiece(knightY - 1, knightX + 2)) {
                matrix[knightY - 1][knightX + 2].piece->Threatened = true;
            } else if (isEmpty(knightY - 1, knightX + 2)) {
                matrix[knightY - 1][knightX + 2].movable = true;
            }
        }

        if (knightY + 1 <= 7) {
            if (hasEnemyPiece(knightY + 1, knightX + 2)) {
                matrix[knightY + 1][knightX + 2].piece->Threatened = true;
            } else if (isEmpty(knightY + 1, knightX + 2)) {
                matrix[knightY + 1][knightX + 2].movable = true;
            }
        }
    }

    // DOWN SIDE
    
    if (knightY + 2 <= 7) {
        if (knightX - 1 >= 0) {
            if (hasEnemyPiece(knightY + 2, knightX - 1)) {
                matrix[knightY + 2][knightX - 1].piece->Threatened = true;
            } else if (isEmpty(knightY + 2, knightX - 1)) {
                matrix[knightY + 2][knightX - 1].movable = true;
            }
        }

        if (knightX + 1 <= 7) {
            if (hasEnemyPiece(knightY + 2, knightX + 1)) {
                matrix[knightY + 2][knightX + 1].piece->Threatened = true;
            } else if (isEmpty(knightY + 2, knightX + 1)) {
                matrix[knightY + 2][knightX + 1].movable = true;
            }
        }
    }

    // LEFT SIDE
    
    if (knightX - 2 >= 0) {
        if (knightY - 1 >= 0) {
            if (hasEnemyPiece(knightY - 1, knightX - 2)) {
                matrix[knightY - 1][knightX - 2].piece->Threatened = true;
            } else if (isEmpty(knightY - 1, knightX - 2)) {
                matrix[knightY - 1][knightX - 2].movable = true;
            }
        }

        if (knightY + 1 <= 7) {
            if (hasEnemyPiece(knightY + 1, knightX - 2)) {
                matrix[knightY + 1][knightX - 2].piece->Threatened = true;
            } else if (isEmpty(knightY + 1, knightX - 2)) {
                matrix[knightY + 1][knightX - 2].movable = true;
            }
        }
    }
}