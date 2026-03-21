#include <iostream>
#include "pieces.h"

Pawn::Pawn(int row, int column, int color) : Piece(row, column, color) {
    setType(PAWN);
    itMoved(false);
    setValue(1);
}

void Pawn::possibleSquares(Board matrix[][8]) {
    int pawnY = Row;
    int pawnX = Column;

    auto isEmpty = [&](int row, int column) {
        return matrix[row][column].piece == nullptr;
    };

    auto hasEnemyPiece = [&](int row, int column) {
        return matrix[row][column].piece != nullptr && Color != matrix[row][column].piece->Color;
    };

    if (Moved == false) {
        if (Color == BRANCO) {
            if (isEmpty(pawnY - 2, pawnX) && isEmpty(pawnY - 1, pawnX)) {
                matrix[pawnY - 1][pawnX].movable = true;
                matrix[pawnY - 2][pawnX].movable = true;
            } else if (isEmpty(pawnY - 1, pawnX)) {
                matrix[pawnY - 1][pawnX].movable = true;
            }
        } else {
            if (isEmpty(pawnY + 2, pawnX) && isEmpty(pawnY + 1, pawnX)) {
                matrix[pawnY + 1][pawnX].movable = true;
                matrix[pawnY + 2][pawnX].movable = true;
            } else if (isEmpty(pawnY + 1, pawnX)) {
                matrix[pawnY + 1][pawnX].movable = true;
            }
        }
    } else {
        if (Color == BRANCO) {
            if (isEmpty(pawnY - 1, pawnX))
                matrix[pawnY - 1][pawnX].movable = true;
        } else {
            if (isEmpty(pawnY + 1, pawnX))
                matrix[pawnY + 1][pawnX].movable = true;
        }
    }

    if (Color == BRANCO) {
        if (hasEnemyPiece(pawnY - 1, pawnX + 1)) {
            // Farei algo
        }

        if (hasEnemyPiece(pawnY - 1, pawnX - 1)) {
            // Farei algo
        }
    }

    if (Color == PRETO) {
        if (hasEnemyPiece(pawnY + 1, pawnX + 1)) {
            // Farei algo
        }

        if (hasEnemyPiece(pawnY + 1, pawnX - 1)) {
            // Farei algo
        }
    }
}
