#include <iostream>
#include "pieces.h"

Rook::Rook(int row, int column, int color) : Piece(row, column, color) {
    setType(ROOK);
    itMoved(false);
    setValue(5);
}

void Rook::possibleSquares(Board matrix[][8]) {
    int firstLineX = Column;
    int firstLineY = Row - 1;

    int secondLineX = Column + 1;
    int secondLineY = Row;

    int thirdLineX = Column;
    int thirdLineY = Row + 1;

    int forthLineX = Column - 1;
    int forthLineY = Row;

    auto isEmpty = [&](int row, int column) {
        return matrix[row][column].piece == nullptr;
    };

    auto hasEnemyPiece = [&](int row, int column) {
        return matrix[row][column].piece != nullptr && Color != matrix[row][column].piece->Color;
    };

    // UP LINE

    while (firstLineY >= 0) {
        if (hasEnemyPiece(firstLineY, firstLineX)) {
            matrix[firstLineY][firstLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(firstLineY, firstLineX)) {
            break;
        }

        matrix[firstLineY][firstLineX].movable = true;

        firstLineY--;
    }

    // RIGHT LINE

    while (secondLineX <= 7) {
        if (hasEnemyPiece(secondLineY, secondLineX)) {
            matrix[secondLineY][secondLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(secondLineY, secondLineX)) {
            break;
        }

        matrix[secondLineY][secondLineX].movable = true;

        secondLineX++;
    }

    // DOWN LINE

    while (thirdLineY <= 7) {
        if (hasEnemyPiece(thirdLineY, thirdLineX)) {
            matrix[thirdLineY][thirdLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(thirdLineY, thirdLineX)) {
            break;
        }

        matrix[thirdLineY][thirdLineX].movable = true;

        thirdLineY++;
    }

    // LEFT LINE

    while (forthLineX >= 0) {
        if (hasEnemyPiece(forthLineY, forthLineX)) {
            matrix[forthLineY][forthLineX].piece->Threatened = true;
            break;
        }

        if (!isEmpty(forthLineY, forthLineX)) {
            break;
        }

        matrix[forthLineY][forthLineX].movable = true;

        forthLineX--;
    }
}